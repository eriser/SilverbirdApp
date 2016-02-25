/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_BFCCA2FBCF2CF29E__
#define __JUCE_HEADER_BFCCA2FBCF2CF29E__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "Parameter.h"
#include "Controller.h"
#include "Knob.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixerStrip  : public Component,
                    public SliderListener,
                    public ButtonListener
{
public:
    //==============================================================================
    MixerStrip (Controller* controller, int trackId);
    ~MixerStrip();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Controller* controller;
    int trackId;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Knob> volumeSlider;
    ScopedPointer<Label> striplabel;
    ScopedPointer<TextButton> muteButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerStrip)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_BFCCA2FBCF2CF29E__