#include "ParameterSetup.h"

ParameterSetup::ParameterSetup(juce::AudioProcessorValueTreeState &inApvts)
    : juce::Thread("MappersProcessingThread")
      , mParameters(inApvts)
      , mSetupData1(createSetupData())
      , mSetupData2(createSetupData())
{
    mCurrentParamsForAudio.store(&mSetupData1, std::memory_order_relaxed);
    mNextParamsForProcessing = &mSetupData2;
    initializeParameters();
    *mCurrentParamsForAudio.load(std::memory_order_relaxed) = *mNextParamsForProcessing;

    initParametersListener();
    startThread();
}

ParameterSetup::~ParameterSetup() {
    mTasksEvent.signal();
    mParameters.removeParameterListener("gain", this);
    mParameters.removeParameterListener("lowPassCutoff", this);
    mParameters.removeParameterListener("highPassResonance", this);
    stopThread(10);
}

ParameterSetupData ParameterSetup::createSetupData() {
    ParameterSetupData data;
    data.lowPassFilterCoeffs = {0.0, 0.0};
    data.highPassFilterCoeffs = {0.0, 0.0};
    data.gain = 0.0;
    return data;
}

void ParameterSetup::initParametersListener() {
    mParameters.addParameterListener("gain", this);
    mParameters.addParameterListener("lowPassCutoff", this); // Example
    mParameters.addParameterListener("highPassResonance", this); // Example
}

void ParameterSetup::initializeParameters() {
    auto *gainParam = mParameters.getRawParameterValue("gain");
    parameterChanged("gain",gainParam->load()) ;

    if (auto *lpCutoffParam = mParameters.getRawParameterValue("lowPassCutoff"))
        mNextParamsForProcessing->lowPassFilterCoeffs.cutoff = static_cast<double>(lpCutoffParam->load());

    if (auto *hpResonanceParam = mParameters.getRawParameterValue("highPassResonance"))
        mNextParamsForProcessing->highPassFilterCoeffs.resonance = static_cast<double>(hpResonanceParam->load());

    mNextParamsForProcessing->version = 0;
}

const ParameterSetupData *ParameterSetup::getAudioThreadParams() const {
    return mCurrentParamsForAudio.load(std::memory_order_acquire);
}

void ParameterSetup::parameterChanged(const juce::String &parameterID, float newValue) {
    juce::String paramIDCopy = parameterID;

    MapperTask task = [this, paramIDCopy, newValue]() {
        ParameterSetupData *paramsToUpdate = mNextParamsForProcessing; {
            std::lock_guard<std::mutex> lock(mUpdateMutex);
            *paramsToUpdate = *mCurrentParamsForAudio.load(std::memory_order_relaxed);
        }

        bool calculationPerformed = false;

        if (paramIDCopy == "gain") {
            Mappers::setGain(paramsToUpdate->gain, static_cast<double>(newValue));
            calculationPerformed = true;
        }

        if (calculationPerformed) {
            std::lock_guard<std::mutex> lock(mUpdateMutex);
            paramsToUpdate->version++; // Increment the version of the data that's about to become current.
            performSwap();
        }
    }; {
        std::lock_guard<std::mutex> lock(mTasksQueueMutex);
        mTaskQueue.push_back(std::move(task));
    }
    mTasksEvent.signal();
}

void ParameterSetup::run() {
    while (!threadShouldExit()) {
        mTasksEvent.wait(-1);

        if (threadShouldExit())
            break;

        // Process all tasks currently in the queue.
        while (true) {
            MapperTask taskToExecute; {
                std::lock_guard<std::mutex> lock(mTasksQueueMutex);
                if (mTaskQueue.empty())
                    break;

                taskToExecute = std::move(mTaskQueue.front());
                mTaskQueue.pop_front();
            }

            if (taskToExecute) {
                taskToExecute();
            }
        }
    }
}

void ParameterSetup::performSwap() {
    // mNextParamsForProcessing (which has just been updated) becomes the new mCurrentParamsForAudio.
    // The old mCurrentParamsForAudio becomes the new mNextParamsForProcessing, ready for the next update cycle.
    ParameterSetupData *tempOldCurrentAudioParams = mCurrentParamsForAudio.load(std::memory_order_relaxed);
    mCurrentParamsForAudio.store(mNextParamsForProcessing, std::memory_order_release);
    mNextParamsForProcessing = tempOldCurrentAudioParams;
}
