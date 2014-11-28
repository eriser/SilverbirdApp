/*
  ==============================================================================

    Synth.cpp
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Source.h"
#include "Sound.h"

Source::Source(MidiKeyboardState& keyState)
: keyboardState (keyState)
{
    
    // KICK
	const int numKicks = 5;
    MemoryInputStream* kicks[numKicks] = {
        new MemoryInputStream (BinaryData::kick1_aif, BinaryData::kick1_aifSize, false),
        new MemoryInputStream (BinaryData::kick2_aif, BinaryData::kick2_aifSize, false),
        new MemoryInputStream (BinaryData::kick3_aif, BinaryData::kick3_aifSize, false),
        new MemoryInputStream (BinaryData::kick4_aif, BinaryData::kick4_aifSize, false),
        new MemoryInputStream (BinaryData::kick5_aif, BinaryData::kick5_aifSize, false)
    };
    addTrack(trackIndex::kick, 36, numKicks, kicks);
    
    // SNARE
	const int numSnares = 5;
    MemoryInputStream* snares[numSnares] = {
        new MemoryInputStream (BinaryData::snare1_aif, BinaryData::snare1_aifSize, false),
        new MemoryInputStream (BinaryData::snare2_aif, BinaryData::snare2_aifSize, false),
        new MemoryInputStream (BinaryData::snare3_aif, BinaryData::snare3_aifSize, false),
        new MemoryInputStream (BinaryData::snare4_aif, BinaryData::snare4_aifSize, false),
        new MemoryInputStream (BinaryData::snare5_aif, BinaryData::snare5_aifSize, false)
    };
    addTrack(trackIndex::snare, 38, numSnares, snares);
    
    // HI HAT
	const int numHihats = 5;
    MemoryInputStream* hihats[numHihats] = {
        new MemoryInputStream (BinaryData::hihat1_aif, BinaryData::hihat1_aifSize, false),
        new MemoryInputStream (BinaryData::hihat2_aif, BinaryData::hihat2_aifSize, false),
        new MemoryInputStream (BinaryData::hihat3_aif, BinaryData::hihat3_aifSize, false),
        new MemoryInputStream (BinaryData::hihat4_aif, BinaryData::hihat4_aifSize, false),
        new MemoryInputStream (BinaryData::hihat5_aif, BinaryData::hihat5_aifSize, false)
    };
    addTrack(trackIndex::hihat, 42, numHihats, hihats);
    
}

Source::~Source() {
}



void Source::addTrack(int index, int note, int numSounds, MemoryInputStream* streams[]) {
    
    Track* track = &tracks[index];
    
    track->setTrackIndex(index);
    track->setNote(note);
    track->setNumberOfSounds(numSounds);
    track->clearSounds();
    
    AiffAudioFormat aifFormat;
    ScopedPointer<AudioFormatReader> sampleReader;
    
    for(int i = 0; i < numSounds; i++) {
        sampleReader = aifFormat.createReaderFor (streams[i], true);
        track->addSound(new Sound ("sound", note, i, *sampleReader));
    }
}


Track* Source::getTrackByIndex(int index) {

    if (index < 0 || index >= maxTracks) {
        return nullptr;
    }
    
	return &tracks[index];
}


void Source::updateSampleRate(int sampleRate) {
    for(int i = 0; i < trackIndex::maxTracks; i++){
    	tracks[i].setCurrentPlaybackSampleRate(sampleRate);
    }
}

void Source::renderNextBlock (AudioSampleBuffer outputAudio, const MidiBuffer inputMidi, int startSample, int numSamples) {
    for(int i = 0; i < trackIndex::maxTracks; i++){
        tracks[i].renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
    }
    outputAudio.applyGain(gain);
}

void Source::noteOn (int midiChannel, int midiNoteNumber, float velocity) {
    for(int i = 0; i < trackIndex::maxTracks; i++){
        std::cout << " source-playnote ";
        tracks[i].noteOn(midiChannel, midiNoteNumber, velocity);
    }
}

void Source::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    midiCollector.reset (sampleRate);
    updateSampleRate(sampleRate);
}

void Source::releaseResources()
{
}

void Source::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // the synth always adds its output to the audio buffer, so we have to clear it
    // first..
    bufferToFill.clearActiveBufferRegion();
    
    // fill a midi buffer with incoming messages from the midi input.
    MidiBuffer incomingMidi;
    midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);
    
    // pass these messages to the keyboard state so that it can update the component
    // to show on-screen which keys are being pressed on the physical midi keyboard.
    // This call will also add midi messages to the buffer which were generated by
    // the mouse-clicking on the on-screen keyboard.
    keyboardState.processNextMidiBuffer (incomingMidi, 0, bufferToFill.numSamples, true);
    
    // and now get the synth to process the midi events and generate its output.
    renderNextBlock (*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
}


void Source::setMaster (float value) {
    gain = value;
}
