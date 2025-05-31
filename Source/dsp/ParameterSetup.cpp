#include "ParameterSetup.h"
// #include <iostream> // For debugging

ParameterSetup::ParameterSetup(juce::AudioProcessorValueTreeState& inApvts)
    : juce::Thread("MappersProcessingThread")
    , mParameters(inApvts)
    // TODO Should init mSetupData
{
    mCurrentParamsForAudio.store(&mSetupData1, std::memory_order_relaxed);
    mNextParamsForProcessing = &mSetupData2;
    *mCurrentParamsForAudio.load(std::memory_order_relaxed) = *mNextParamsForProcessing;

    initParametersListener();
    startThread();
}

ParameterSetup::~ParameterSetup()
{
    mTasksEvent.signal();
    stopThread(5000);

    // Remove listeners
    mParameters.removeParameterListener("gain", this);
    mParameters.removeParameterListener("lowPassCutoff", this);
    mParameters.removeParameterListener("highPassResonance", this);
    // Add other listeners that were registered
}

void ParameterSetup::initParametersListener()
{
    mParameters.addParameterListener("gain", this);
    mParameters.addParameterListener("lowPassCutoff", this); // Example
    mParameters.addParameterListener("highPassResonance", this); // Example
    // Add other relevant parameters here
}

void ParameterSetup::initializeParameters()
{
    if (auto* gainParam = mParameters.getRawParameterValue("gain"))
        mNextParamsForProcessing->gain = gainParam->load();

    if (auto* lpCutoffParam = mParameters.getRawParameterValue("lowPassCutoff"))
        mNextParamsForProcessing->lowPassFilterCoeffs.cutoff = static_cast<double>(lpCutoffParam->load());

    if (auto* hpResonanceParam = mParameters.getRawParameterValue("highPassResonance"))
         mNextParamsForProcessing->highPassFilterCoeffs.resonance = static_cast<double>(hpResonanceParam->load());

    mNextParamsForProcessing->version = 0; // Initial version
}

const ParameterSetupData* ParameterSetup::getAudioThreadParams() const
{
    return mCurrentParamsForAudio.load(std::memory_order_acquire);
}

void ParameterSetup::parameterChanged(const juce::String& parameterID, float newValue)
{
    juce::String paramIDCopy = parameterID;

    // Create a task (lambda function) that will be executed by the MappersProcessingThread.
    MapperTask task = [this, paramIDCopy, newValue]() {
        ParameterSetupData* paramsToUpdate = mNextParamsForProcessing;
        {
            std::lock_guard<std::mutex> lock(mUpdateMutex);
            *paramsToUpdate = *mCurrentParamsForAudio.load(std::memory_order_relaxed);
        }

        bool calculationPerformed = false;

        if (paramIDCopy == "gain")
        {
            Mappers::setGain(paramsToUpdate->gain, static_cast<double>(newValue));
            calculationPerformed = true;
        }
        else if (paramIDCopy == "lowPassCutoff")
        {
            paramsToUpdate->lowPassFilterCoeffs.cutoff = static_cast<double>(newValue); // Direct update
            calculationPerformed = true;
        }
        else if (paramIDCopy == "highPassResonance")
        {
            paramsToUpdate->highPassFilterCoeffs.resonance = static_cast<double>(newValue); // Direct update
            calculationPerformed = true;
        }
        // ... handle other parameters similarly ...

        // Step 3: Commit the changes if a calculation was performed.
        // This involves updating the version and swapping the buffers, protected by mUpdateMutex.
        if (calculationPerformed)
        {
            std::lock_guard<std::mutex> lock(mUpdateMutex);
            paramsToUpdate->version++; // Increment the version of the data that's about to become current.
            performSwap(); // Atomically swap mCurrentParamsForAudio and mNextParamsForProcessing.
        }
    };

    {
        std::lock_guard<std::mutex> lock(mTasksQueueMutex);
        mTaskQueue.push_back(std::move(task));
    }
    mTasksEvent.signal();
}

// This is the main loop for the MappersProcessingThread.
void ParameterSetup::run()
{
    while (!threadShouldExit())
    {
        // Wait for a signal indicating that new tasks are available or the thread should exit.
        // wait(-1) waits indefinitely.
        mTasksEvent.wait(-1);

        if (threadShouldExit())
            break;

        // Process all tasks currently in the queue.
        while (true)
        {
            MapperTask taskToExecute;
            {
                std::lock_guard<std::mutex> lock(mTasksQueueMutex);
                if (mTaskQueue.empty())
                    break; // No more tasks in the queue.

                taskToExecute = std::move(mTaskQueue.front());
                mTaskQueue.pop_front();
            }

            if (taskToExecute)
            {
                taskToExecute(); // Execute the task.
            }
        }
    }
}

// Helper function to swap the data buffers.
// This function assumes that mUpdateMutex is ALREADY HELD by the caller.
void ParameterSetup::performSwap()
{
    // mNextParamsForProcessing (which has just been updated) becomes the new mCurrentParamsForAudio.
    // The old mCurrentParamsForAudio becomes the new mNextParamsForProcessing, ready for the next update cycle.
    ParameterSetupData* tempOldCurrentAudioParams = mCurrentParamsForAudio.load(std::memory_order_relaxed);
    mCurrentParamsForAudio.store(mNextParamsForProcessing, std::memory_order_release);
    mNextParamsForProcessing = tempOldCurrentAudioParams;
}