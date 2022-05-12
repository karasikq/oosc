//===------------------------ MidiPlayback.h ---------------------*- C++-*-===//
//===------------------ MidiPlayback class definition ---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the MidiPlayback class, which is
/// used for receive parsed midi-file, then send noteOn and noteOff events
/// to Synthesizer.
///
//===----------------------------------------------------------------------===//

#ifndef MIDIPLAYBACK_H
#define MIDIPLAYBACK_H

#include <QObject>
#include <mutex>
#include <thread>

#include "MidiFile.h"
#include "ThirdParty/midifile/include/MidiFile.h"
#include "src/UI/SynthesizerControls/SynthesizerControl.h"

class MidiPlayback : public QObject {
  Q_OBJECT
public:
  MidiPlayback();
  MidiPlayback(smf::MidiFile &midiFile);

  void play();
  void stop();
  void pause();
  void check(float time);
  void checkAsync(float time);
  bool isPaused();
  float getPlaybackTime();

  void attachSynthesizer(SynthesizerControl *synth);
  void attachMidiFile(std::unique_ptr<smf::MidiFile> &&midiFile);

  uint32_t BPM = 120;

signals:
  void started();
  void stoped();
  void paused();
  void ended();
  void checked();

protected:
  std::unique_ptr<smf::MidiFile> midiFile;
  SynthesizerControl *synthesizer;

  std::thread midiThread;
  std::mutex midiMutex;

  bool pauseState;
  void setCalledState(bool state);
  float playbackTime;
};

#endif // MIDIPLAYBACK_H
