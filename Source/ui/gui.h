#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_audio_processors_headless/juce_audio_processors_headless.h>
#include <juce_graphics/juce_graphics.h>
#include "../looknfeel/ToogleButtonLookAndFeel.h"
#include "../looknfeel/TopBarLookAndFeel.h"
#include "components/TopBarComponent.h"

class RootViewComponent : public juce::AudioProcessorEditor
{
public:
    struct KnobLayout {
        struct input {
            int x;
            int y;
            int frameWidth ;
            int frameHeight;
            float ratio;
            int textboxHeight;
            int textboxPadding;
        };
        struct output {
            int x;
            int y;
            int sliderWidth;
            int sliderHeight;
        };
        input inLayout;
        output outLayout;
    };

    static int ROOT_WIDTH;
    static int ROOT_HEIGHT;
    RootViewComponent(juce::AudioProcessor& processor);
    ~RootViewComponent() override;  

    void setSliderAttachement(juce::AudioProcessor& inProcessor);
    void computeKnobLayout(KnobLayout& inKnobLayout)
    {
	    inKnobLayout.outLayout.x = inKnobLayout.inLayout.x;
        inKnobLayout.outLayout.y = inKnobLayout.inLayout.y;
        inKnobLayout.outLayout.sliderWidth = inKnobLayout.inLayout.frameWidth * inKnobLayout.inLayout.ratio;
        inKnobLayout.outLayout.sliderHeight = inKnobLayout.inLayout.frameHeight * inKnobLayout.inLayout.ratio;
	}

    void updatePath();
    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    juce::Image mImage;
    juce::AudioProcessor& mProcessor;

   // KnobLookAndFeel mKnobLookAndFeel;
    DropDownLookAndFeel mDropDownLookAndFeel; 
  //  ToggleButtonLookAndFeel mToggleLookAndFeel;

#include "gui.hpp"
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RootViewComponent)
};