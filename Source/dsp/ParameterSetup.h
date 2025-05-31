#pragma once
#include <JuceHeader.h>
#include <atomic>
#include <mutex>
#include "Mappers.h"

struct FilterCoefficients
{
    double cutoff = 2000.0;
    double resonance = 0.707;
};

struct ParameterSetupData
{
        FilterCoefficients lowPassFilterCoeffs;
        FilterCoefficients highPassFilterCoeffs;
        float gain;
        uint64_t version = 0;
};

class ParameterSetup : AudioProcessorValueTreeState::Listener, public juce::Thread
{
    using MapperTask = std::function<void()>;
public:
    ParameterSetup(AudioProcessorValueTreeState& inApvts)
        : juce::Thread("MappersProcessingThread")
    , mMappers()
    ,
          mParameters(inApvts),
          mFifoTasks(128) // Capacité de la file d'attente des tâches (ajustez selon les besoins)
    // mFifoBuffer(128)


    {
        mCurrentParamsForAudio = &mSetupData1;
        mNextParamsForProcessing = &mSetupData2;

        initParametersListener();
        launchAllMappers();

        *mCurrentParamsForAudio.load(std::memory_order_relaxed) = *mNextParamsForProcessing;
    }

    void initParametersListener()
    {
        mParameters.addParameterListener("gain", this);
    }
    ~ParameterSetup() {

    }

    void launchAllMappers()
    {
        std::lock_guard<std::mutex> lock(mUpdateMutex);
        auto* gainParam = mParameters.getRawParameterValue("gain");
        if (gainParam)
        {
            mNextParamsForProcessing->gain = gainParam->load();
        }
    }
    const ParameterSetupData* getAudioThreadParams() const // TODO / OSEF ?
    {
        return mCurrentParamsForAudio.load(std::memory_order_acquire);
    }

    void onParameterChanged(const juce::String& parameterID, float newValue)
    {
        std::lock_guard<std::mutex> lock(mUpdateMutex); // if we could avoid this mutex
        *mNextParamsForProcessing = *mCurrentParamsForAudio.load(std::memory_order_relaxed);


        if (parameterID == "lowPassCutoff")
        {
            // Here's this will be called by mappers

            mNextParamsForProcessing->lowPassFilterCoeffs.cutoff = static_cast<double>(newValue);
        }
        else if (parameterID == "highPassResonance")
        {
            mNextParamsForProcessing->highPassFilterCoeffs.resonance = static_cast<double>(newValue);
        }
        else if (parameterID == "gain")
        {
            mNextParamsForProcessing->gain = newValue;
            // Here call in mapper and wait
        }

        mNextParamsForProcessing->version++;
        commitParameterChanges();
    }


    void commitParameterChanges()
    {
        std::lock_guard<std::mutex> lock(mUpdateMutex);

        ParameterSetupData* temp = mCurrentParamsForAudio.load(std::memory_order_relaxed);
        mCurrentParamsForAudio.store(mNextParamsForProcessing, std::memory_order_release);
        mNextParamsForProcessing = temp;
    }


private:
    ParameterSetupData mSetupData1;
    ParameterSetupData mSetupData2;

    Mappers mMappers;

    AudioProcessorValueTreeState& mParameters;

    std::atomic<ParameterSetupData*> mCurrentParamsForAudio;
    ParameterSetupData* mNextParamsForProcessing;

    std::mutex mUpdateMutex;
    juce::AbstractFifo mFifoTasks;
   // std::vector<MapperTask> mFifoBuffer; // Le buffer réel pour la FIFO
    juce::WaitableEvent mTasksEvent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterSetup)
};
