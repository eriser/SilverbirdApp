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

#ifndef __JUCE_HEADER_CAE02453DB8909B0__
#define __JUCE_HEADER_CAE02453DB8909B0__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "Controller.h"
#include "BaseComponent.h"
//[/Headers]

#include "MixerStrip.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixerComponent  : public BaseComponent
{
public:
    //==============================================================================
    MixerComponent (Controller* controller);
    ~MixerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void positionLabels(MixerStrip* referenceMixerStripComponent);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void setLabelTransform(ScopedPointer<Label>);
    AffineTransform myTransform;
    Array<Label*> labels;
    Array<MixerStrip*> channelStrips;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<MixerStrip> ch2;
    ScopedPointer<MixerStrip> ch3;
    ScopedPointer<MixerStrip> ch4;
    ScopedPointer<MixerStrip> ch5;
    ScopedPointer<MixerStrip> ch6;
    ScopedPointer<MixerStrip> ch1;
    ScopedPointer<Label> muteLabel;
    ScopedPointer<Label> levelLabel;
    ScopedPointer<Label> reverbLabel;
    ScopedPointer<Label> delayLabel;
    ScopedPointer<Label> panLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CAE02453DB8909B0__
