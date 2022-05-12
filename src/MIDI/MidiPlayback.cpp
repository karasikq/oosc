#include "MidiPlayback.h"
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <string>

MidiPlayback::MidiPlayback() {
  playbackTime = 0.0f;
  pauseState = true;
  midiFile = nullptr;
}

MidiPlayback::MidiPlayback(smf::MidiFile &midiFile) {
  this->midiFile = std::unique_ptr<smf::MidiFile>(new smf::MidiFile(midiFile));
  playbackTime = 0.0f;
  pauseState = true;
}

void MidiPlayback::play() {
  pauseState = false;
  emit started();
}

void MidiPlayback::stop() {
  playbackTime = 0.0f;
  setCalledState(false);
  pauseState = true;
  synthesizer->allNoteOff();
  emit stoped();
}

void MidiPlayback::pause() {
  pauseState = true;
  synthesizer->allNoteOff();
  emit paused();
}

bool MidiPlayback::isPaused() { return pauseState; }

float MidiPlayback::getPlaybackTime() { return playbackTime; }

void MidiPlayback::attachSynthesizer(SynthesizerControl *synth) {
  synthesizer = synth;
}

void MidiPlayback::attachMidiFile(std::unique_ptr<smf::MidiFile> &&midiFile) {
  this->midiFile = std::move(midiFile);
}

void MidiPlayback::checkAsync(float time) {
  auto fut = std::async(std::launch::async, [&] { return check(time); });
}

void MidiPlayback::check(float time) {
  if (pauseState || midiFile == nullptr) {
    return;
  }
  bool ended = true;
  playbackTime += time;
  time = playbackTime;

  for (int track = 0; track < midiFile->getTrackCount(); track++) {
    for (int event = 0; event < (*midiFile)[track].size(); event++) {
      std::unique_lock<std::mutex> mlck(midiMutex);
      smf::MidiEvent *ev = &(*midiFile)[track][event];
      if (ev->seconds <= time && !ev->called) {
        if ((*midiFile)[track][event].isNoteOn()) {
          synthesizer->noteOn(ev->getKeyNumber(), ev->getVelocity());
          (*midiFile)[track][event].called = true;
        }
        if ((*midiFile)[track][event].isNoteOff()) {
          synthesizer->noteOff(ev->getKeyNumber());
          (*midiFile)[track][event].called = true;
        }
      }
      ended = false;
    }
  }
  emit checked();
  if (ended) {
    play();
  }
}

void MidiPlayback::setCalledState(bool state) {
  if (midiFile == nullptr)
    return;
  for (int track = 0; track < midiFile->getTrackCount(); track++) {
    for (int event = 0; event < (*midiFile)[track].size(); event++) {
      std::unique_lock<std::mutex> mlck(midiMutex);
      smf::MidiEvent *ev = &(*midiFile)[track][event];
      ev->called = state;
    }
  }
}
