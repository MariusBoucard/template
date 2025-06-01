
/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             GainPlugin
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Gain audio plugin.

 dependencies:     juce_audio_basics, juce_audio_devices, juce_audio_formats,
                   juce_audio_plugin_client, juce_audio_processors,
                   juce_audio_utils, juce_core, juce_data_structures,
                   juce_events, juce_graphics, juce_gui_basics, juce_gui_extra
 exporters:        xcode_mac, vs2022

 moduleFlags:      JUCE_STRICT_REFCOUNTEDPOINTER=1

 type:             AudioProcessor
 mainClass:        GainProcessor

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/

#pragma once
#include "ui/gui.h"
#include "dsp/Processor.h"
#include "dsp/ParameterSetup.h"

class PluginAudioProcessor final : public AudioProcessor
{
public:

    PluginAudioProcessor();
    ~PluginAudioProcessor() override;

    juce::AudioProcessorValueTreeState::ParameterLayout PluginAudioProcessor::createParameterLayout()
    {
        std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
        auto attributes = juce::AudioParameterFloatAttributes()
                                .withStringFromValueFunction ([](float value, int )
                                                              {
                                                                  return juce::String (value * 100.0f);
                                                              })
                                .withLabel (" db magueul");

        params.push_back(std::make_unique<juce::AudioParameterFloat>("gain",
                                                                    "Gain",
                                                                     juce::NormalisableRange<float>(0.0f,
                                                                     1.0f,
                                                                     0.01),
                                                                     0.5f,
                                                                     attributes));
        return { params.begin(), params.end() };
    }

    void prepareToPlay (double sampleRate, int blockSize) override {
        std::cout << "prepareToPlay" << std::endl;
        mSkeletonProcessor.prepareToPlay(sampleRate, blockSize);
    }
    void releaseResources() override {}

    void processBlock(AudioBuffer<float>& buffer, MidiBuffer&) override;

    AudioProcessorEditor* createEditor() override {
        //auto editor = new RootViewComponent(mSkeletonProcessor);
        auto editor = new GenericAudioProcessorEditor(this);

        //editor->updatePath();
        return editor;
    }
    bool hasEditor() const override                        { return true;   }

    const String getName() const override                  { return "Template"; }
    bool acceptsMidi() const override                      { return false; }
    bool producesMidi() const override                     { return false; }
    double getTailLengthSeconds() const override           { return 0; }

    int getNumPrograms() override                          { return 1; }
    int getCurrentProgram() override                       { return 0; }
    void setCurrentProgram (int) override                  {}
    const String getProgramName (int) override             { return "None"; }
    void changeProgramName (int, const String&) override   {}


    void getStateInformation (MemoryBlock& destData) override
    {
        juce::MemoryOutputStream stream(destData, true);
        mParameters.state.writeToStream(stream);  
    }


    void setStateInformation (const void* data, int sizeInBytes) override
    {

    }

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override
    {
        const auto& mainInLayout  = layouts.getChannelSet (true,  0);
        const auto& mainOutLayout = layouts.getChannelSet (false, 0);

        return (mainInLayout == mainOutLayout && (! mainInLayout.isDisabled()));
    }

    juce::AudioProcessorValueTreeState& PluginAudioProcessor::getCustomParameterTree()
    {
        return mParameters;
    }

private:
    juce::AudioProcessorValueTreeState mParameters; 
    SkeletonAudioProcessor mSkeletonProcessor;
    ParameterSetup mParameterSetup;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessor)
};
