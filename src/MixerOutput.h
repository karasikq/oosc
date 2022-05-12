//===----------------------- MixerOutput.h -----------------------*- C++-*-===//
//===--------------- MixerOutput class definition -------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Singleton MixerOutput class. It's
/// a portaudio wrapper which parse midi events and gets output from
/// synthesizer.
///
//===----------------------------------------------------------------------===//

#ifndef MIXEROUTPUT_H
#define MIXEROUTPUT_H

#include <QDebug>
#include <list>
#include <mutex>
#include <portaudio.h>

#include "MIDI/MidiPlayback.h"
#include "Utils/ITimeReceiver.h"
#include "src/Generator/BasicSynthesizer.h"

class MixerOutput {
public:
  static MixerOutput *Instance();
  ~MixerOutput();

  void Initialize();
  void addMidiPlayback(MidiPlayback *playback);
  void removeMidiPlayback(MidiPlayback *playback);
  void addSynthesizer(BasicSynthesizer *synthesizer);
  void removeSynthesizer(BasicSynthesizer *synthesizer);
  void addTimeReceiver(ITimeReceiver *receiver);
  void removeTimeReceiver(ITimeReceiver *receiver);

  /// Returns absolude time in seconds
  inline float Time() const { return wvTime; }
  /// Returns MIDI BPM
  inline float BPM() const { return bpm; }

protected:
  MixerOutput();
  static MixerOutput *instance;

private:
  static std::mutex initMutex;
  PaStreamParameters outputParameters;
  PaStream *stream;

  float bpm;
  float wvTime;
  std::list<MidiPlayback *> midiPlaybacks;
  std::list<BasicSynthesizer *> synthesizers;
  std::list<ITimeReceiver *> timeReceivers;

  /// Portaudio callback
  static int OutputCallback(const void *inputBuffer,
                            void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void *userData);
};

#endif // MIXEROUTPUT_H
