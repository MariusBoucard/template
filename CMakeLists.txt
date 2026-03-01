cmake_minimum_required(VERSION 3.15)

project(Template VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add JUCE as a subdirectory (adjust the path to where your JUCE folder is located)
# Option 1: If JUCE is in a subdirectory relative to this CMakeLists.txt
# add_subdirectory(path/to/JUCE)

# Option 2: If JUCE is installed elsewhere
# For this example, assuming JUCE is at C:/Users/Marius/Documents/JUCE/JUCE
# add_subdirectory("C:/Users/Marius/Documents/JUCE/JUCE" JUCE)

# Define the plugin
juce_add_plugin(Template
        COMPANY_NAME "Ballzzy"
        COMPANY_WEBSITE "http://juce.com"
        COMPANY_EMAIL ""
        PLUGIN_MANUFACTURER_CODE Ball
        PLUGIN_CODE E0kf
        FORMATS VST3 Standalone
        PRODUCT_NAME "Template"
        BUNDLE_ID "com.JUCE.Template"

        # VST3 specific settings
        VST3_CATEGORIES Fx

        # Plugin characteristics
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE

        # Other settings
        COPY_PLUGIN_AFTER_BUILD FALSE
        PLUGIN_NAME "Template"
        PLUGIN_DESCRIPTION "Template"
        VST3_AUTO_MANIFEST FALSE
)

# Link binary data and JUCE modules to the plugin
target_link_libraries(Template
        PRIVATE
        TemplateData
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# Add source files
target_sources(Template
        PRIVATE
        # Main source files
        Source/FaustPlugin.h
        Source/Main.cpp
        Source/PluginAudioProcessor.cpp
        Source/PluginAudioProcessor.h
        Source/PluginAudioProcessor.hpp

        # DSP files
        Source/dsp/Mappers.cpp
        Source/dsp/Mappers.h
        Source/dsp/ParameterSetup.h
        Source/dsp/ParameterSetup.cpp
        Source/dsp/Processor.cpp
        Source/dsp/Processor.h
        Source/dsp/Processor.hpp

        # DSP Bones
        Source/dsp/Bones/FaustMultiheadFeedback.h

        # Look and Feel
        Source/looknfeel/StripKnob_look_n_feel.h
        Source/looknfeel/ToogleButtonLookAndFeel.h

        # UI
        Source/ui/gui.cpp
        Source/ui/gui.h
        Source/ui/gui.hpp

        # UI Components
        Source/ui/components/TopBarComponent.cpp
        Source/ui/components/TopBarComponent.h
)

# Add binary resources (images)
juce_add_binary_data(TemplateData
        SOURCES
        # Knobs
        Source/ressources/knob/g1.png

        # Plate
        Source/ressources/plate/plate.png
)

# Preprocessor definitions
target_compile_definitions(Template
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_DISPLAY_SPLASH_SCREEN=1
        JUCE_STRICT_REFCOUNTEDPOINTER=1
        PRIVATE
        PIP_JUCE_EXAMPLES_DIRECTORY="C:/Users/Marius/Desktop/AIPlugin/Juce/examples"
)

# Platform-specific settings
if(MSVC)
    target_compile_options(Template PRIVATE /bigobj)
endif()

# Custom post-build command to copy VST3 to specific location
if(WIN32)
    set(VST3_DESTINATION_PATH "D:/vstcreation/Template.vst3/Contents/x86_64-win")

    add_custom_command(TARGET Template_VST3 POST_BUILD
            # Create the necessary internal folder structure
            COMMAND ${CMAKE_COMMAND} -E make_directory "${VST3_DESTINATION_PATH}"

            # Copy the VST3 file
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:Template_VST3>"
            "${VST3_DESTINATION_PATH}/$<TARGET_FILE_NAME:Template_VST3>"
            COMMENT "Creating VST3 Bundle structure in D:/vstcreation"
    )
endif()