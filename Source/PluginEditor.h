/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleDelayAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleDelayAudioProcessorEditor (SimpleDelayAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~SimpleDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleDelayAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& treeState;

    juce::Slider delayTimeSlider;
    juce::Slider delayTime2Slider;
    juce::Slider feedbackSlider;
    juce::Slider drywetSlider;

    juce::Label delayTimeLabel;
    juce::Label delayTime2Label;
    juce::Label feedbackLabel;
    juce::Label drywetLabel;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> delayTimeValue;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> delayTime2Value;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> feedbackValue;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> drywetValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleDelayAudioProcessorEditor)
};
