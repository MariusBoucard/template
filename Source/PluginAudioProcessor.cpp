

#include "PluginAudioProcessor.h"

#include <filesystem>
#include <iostream>



PluginAudioProcessor::PluginAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input", AudioChannelSet::stereo())
    . withOutput("Output", AudioChannelSet::stereo()))
    , mParameters(*this, nullptr, "PARAMETERS", createParameterLayout())
    , mParameterSetup()
    , mSkeletonProcessor(mParameters,mParameterSetup)
{

}
PluginAudioProcessor::~PluginAudioProcessor()
{
   
}

void PluginAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer&)
{
       mSkeletonProcessor.processBlock(buffer, MidiBuffer());
}
