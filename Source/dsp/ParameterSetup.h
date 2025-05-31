#pragma once

#include <JuceHeader.h>
#include <atomic>
#include <mutex>
#include <deque>
#include <functional>
#include "Mappers.h" // Ensure this path is correct

// Forward declaration if Mappers is complex, or include if simple
// class Mappers;

struct FilterCoefficients
{
    double cutoff = 2000.0;
    double resonance = 0.707;
};

struct ParameterSetupData
{
    FilterCoefficients lowPassFilterCoeffs;
    FilterCoefficients highPassFilterCoeffs;
    double gain = 0.0; // Initialize members
    uint64_t version = 0;
};

class ParameterSetup : public juce::Thread, public juce::AudioProcessorValueTreeState::Listener
{
public:
    using MapperTask = std::function<void()>;

    ParameterSetup(juce::AudioProcessorValueTreeState& inApvts);
    ~ParameterSetup() override;

    void parameterChanged(const juce::String& parameterID, float newValue) override;

    const ParameterSetupData* getAudioThreadParams() const;

private:
    void run() override;

    void initParametersListener();
    void initializeParameters();
    void performSwap();

    ParameterSetupData mSetupData1;
    ParameterSetupData mSetupData2;

    juce::AudioProcessorValueTreeState& mParameters;

    std::atomic<ParameterSetupData*> mCurrentParamsForAudio;
    ParameterSetupData* mNextParamsForProcessing;

    std::mutex mUpdateMutex;

    std::deque<MapperTask> mTaskQueue;
    std::mutex mTasksQueueMutex;
    juce::WaitableEvent mTasksEvent; // To signal the MappersProcessingThread about new tasks

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterSetup)
};