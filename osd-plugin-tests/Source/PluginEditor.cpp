/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    
    testDrum.setSliderStyle (juce::Slider::LinearBarVertical);
    testDrum.setRange (0.0, 127.0, 1.0);
    testDrum.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    testDrum.setPopupDisplayEnabled (true, false, this);
    testDrum.setTextValueSuffix (" Volume");
    testDrum.setValue(1.0);
    
//  testButton.onClick = [&]() {}
    
    addAndMakeVisible (&testDrum);
    addAndMakeVisible (&testButton);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Test Slider", getLocalBounds(), juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    testDrum.setBounds (40, 30, 20, getHeight() - 60);
    testButton.setBounds (150, 100, 100, 100);
}
