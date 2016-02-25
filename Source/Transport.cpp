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

//[Headers] You can add your own extra header files here...
#include "Knob.h"
#include "Controller.h"
//[/Headers]

#include "Transport.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Transport::Transport (Controller* controller)
    : controller(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (bpmSlider = new Knob (String()));
    bpmSlider->setRange (100, 180, 1);
    bpmSlider->setSliderStyle (Slider::LinearBar);
    bpmSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 100, 20);
    bpmSlider->setColour (Slider::thumbColourId, Colour (0xff656565));
    bpmSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    bpmSlider->addListener (this);

    addAndMakeVisible (playButton = new TextButton ("play"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);
    playButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("BPM")));
    label->setFont (Font (11.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Shuffle\n")));
    label10->setFont (Font (11.00f, Font::plain));
    label10->setJustificationType (Justification::centred);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colour (0xfff3f3f3));
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (shuffleSlider = new Knob ("Shuffle"));
    shuffleSlider->setRange (0, 1, 0.01);
    shuffleSlider->setSliderStyle (Slider::LinearBar);
    shuffleSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    shuffleSlider->setColour (Slider::thumbColourId, Colour (0xff656565));
    shuffleSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    shuffleSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 40);


    //[Constructor] You can add your own custom stuff here..
    bpmSlider->setValue(controller->clock.getBpm());
    
    Parameter* p;
    p = controller->getParameterByAttrs(Controller::params::shuffle);
    shuffleSlider->addListener(controller);
    shuffleSlider->getValueObject().referTo(*p);
    shuffleSlider->setDoubleClickReturnValue(true, p->getDefaultValue());
    //[/Constructor]
}

Transport::~Transport()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    bpmSlider = nullptr;
    playButton = nullptr;
    label = nullptr;
    label10 = nullptr;
    shuffleSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Transport::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Transport::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    bpmSlider->setBounds (proportionOfWidth (0.3750f), proportionOfHeight (0.0286f), proportionOfWidth (0.3013f), proportionOfHeight (0.6571f));
    playButton->setBounds (proportionOfWidth (0.7219f), proportionOfHeight (0.0250f), proportionOfWidth (0.2500f), proportionOfHeight (0.6500f));
    label->setBounds (proportionOfWidth (0.4776f), proportionOfHeight (0.7429f), proportionOfWidth (0.1026f), proportionOfHeight (0.2286f));
    label10->setBounds (proportionOfWidth (0.0906f), proportionOfHeight (0.7500f), proportionOfWidth (0.1563f), proportionOfHeight (0.2250f));
    shuffleSlider->setBounds (proportionOfWidth (0.0219f), proportionOfHeight (0.0250f), proportionOfWidth (0.3000f), proportionOfHeight (0.6500f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Transport::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == bpmSlider)
    {
        //[UserSliderCode_bpmSlider] -- add your slider handling code here..
        controller->setBpm(bpmSlider->getValue());
        //[/UserSliderCode_bpmSlider]
    }
    else if (sliderThatWasMoved == shuffleSlider)
    {
        //[UserSliderCode_shuffleSlider] -- add your slider handling code here..
        //[/UserSliderCode_shuffleSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Transport::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        bool isPlaying = controller->togglePlayPause();
        playButton->setButtonText (TRANS(isPlaying ? "Stop" : "Play"));
        //[/UserButtonCode_playButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Transport" componentName=""
                 parentClasses="public Component" constructorParams="Controller* controller"
                 variableInitialisers="controller(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="320" initialHeight="40">
  <BACKGROUND backgroundColour="0"/>
  <SLIDER name="" id="3368eda71e194b82" memberName="bpmSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="37.5% 2.5% 30% 65%" thumbcol="ff656565"
          textboxtext="ffffffff" min="100" max="180" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="100"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="play" id="e919a91fb78e40b3" memberName="playButton" virtualName=""
              explicitFocusOrder="0" pos="72.188% 2.5% 25% 65%" bgColOff="ffcecece"
              buttonText="Play" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="e5bd61ea8c7a90cf" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="47.812% 75% 10.312% 22.5%" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="BPM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="cfbf1f6cb7801bfe" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="9.062% 75% 15.625% 22.5%" textCol="fff3f3f3"
         edTextCol="ff000000" edBkgCol="0" labelText="Shuffle&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="36"/>
  <SLIDER name="Shuffle" id="f2d61c4a72ddf897" memberName="shuffleSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="2.188% 2.5% 30% 65%"
          thumbcol="ff656565" textboxtext="ffffffff" min="0" max="1" int="0.010000000000000000208"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
