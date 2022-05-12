#include "Synthesizer.h"
#include "../Utils/AudioFile.h"
#include "GeneratorsThreadPool.h"
#include "src/Generator/AGenerator.h"
#include "src/Generator/Generator.h"
#include "src/Generator/SubGenerator.h"
#include <QVector>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

template <size_t T>
Synthesizer<T>::Synthesizer() {
  audioChannel =
      std::unique_ptr<AudioChannel>(new AudioChannel(2, bufferSize / 2));
  rawData = new float[bufferSize];
  setupGenerators();
}

template <size_t T>
Synthesizer<T>::~Synthesizer() {
  delete[] rawData;
}

template <size_t T>
void Synthesizer<T>::setupGenerators() {}

template <size_t T>
void Synthesizer<T>::attachEffect(Effect *effect) {
  if (std::none_of(effects.begin(), effects.end(), [&](Effect *lhs) {
        return lhs == effect;
      })) {
    effects.push_back(effect);
  }
}

template <size_t T>
void Synthesizer<T>::detachEffect(Effect *effect) {
  effects.remove(effect);
}

template <size_t T>
void Synthesizer<T>::addNote(unsigned char note, unsigned char vel) {
  Note<T> newNote(note, vel);
  newNote.freezeState = ADSREnvelope::State::DECAY;
  newNote.time = 0;
  noteMap[note].emplace_back(newNote);
  lastNote = std::prev(noteMap[note].end());
  notesEndIterator = noteMap[note].end();
}

template <size_t T>
void Synthesizer<T>::noteOn(unsigned char note, unsigned char vel) {
  std::unique_lock<std::mutex> lck(noteMutex);
  if (noteMap.count(note)) {
    bool notePlaying = false;
    auto &notes = noteMap[note];
    for (auto i = notes.begin(); i != notes.end(); i++) {
      auto &cnote = *i;
      for (size_t i = 0; i < T; i++) {
        if (cnote.state[i] != ADSREnvelope::State::RELEASE &&
            cnote.state[i] != ADSREnvelope::State::OFF) {
          notePlaying = true;
          break;
        }
      }
      if (notePlaying) {
        std::fill(cnote.envelopeTime.begin(), cnote.envelopeTime.end(), 0.0f);
        lastNote = i;
        notesEndIterator = notes.end();
        return;
      }
    }
  }
  addNote(note, vel);
}

template <size_t T>
void Synthesizer<T>::noteOff(unsigned char note) {
  std::unique_lock<std::mutex> lck(noteMutex);
  if (noteMap.count(note)) {
    auto &notes = noteMap[note];
    for (auto i = notes.begin(); i != notes.end(); i++) {
      auto &cnote = *i;
      for (size_t i = 0; i < T; i++) {
        cnote.envelopeTime[i] =
            generators[i]->getEnvelope()->AbsoluteDecayTime();
      }
      cnote.freezeState = ADSREnvelope::State::OFF;
    }
  }
}

template <size_t T>
void Synthesizer<T>::allNoteOff() {
  for (auto &note : noteMap) {
    noteOff(note.first);
  }
}

template <size_t T>
float *Synthesizer<T>::getRawOutput() {
  uint32_t numSamples = bufferSize / 2;

  for (unsigned int sample = 0; sample < bufferSize; sample++) {
    rawData[sample] = 0;
  }
  for (size_t gId = 0; gId < T; gId++) {
    generators[gId]->clear();
  }

  {
    std::unique_lock<std::mutex> lck(noteMutex);
    for (auto &pair : noteMap) {
      auto &notes = pair.second;
      for (auto noteIt = notes.begin(); noteIt != notes.end();) {
        auto &note = *noteIt;
        note.time += (float)numSamples / AudioSettings::SAMPLE_RATE;
        currentNote = note;
        generatorsThreadPool->executeAndWait();
        note = currentNote;
        bool offState = false;
        for (size_t i = 0; i < T; i++) {
          if (note.state[i] == ADSREnvelope::State::OFF) {
            offState = true;
            break;
          }
        }

        if (offState) {
          noteIt = notes.erase(noteIt);
          continue;
        } else {
          noteIt++;
        }
      }
    }
  }

  for (unsigned int sample = 0; sample < numSamples; sample++) {
    float left = 0.f, right = 0.f;
    for (size_t gId = 0; gId < T; gId++) {
      left += generators[gId]->getChannel()->getSample(0, sample);
      right += generators[gId]->getChannel()->getSample(1, sample);
    }
    audioChannel->getChannelBuffer(0)->at(sample) = left;
    audioChannel->getChannelBuffer(1)->at(sample) = right;
  }

  for (Effect *effect : effects) {
    effect->Apply(*audioChannel);
  }

  audioChannel->mix();
  auto leftChannel = audioChannel->getChannelBuffer(0);
  auto rightChannel = audioChannel->getChannelBuffer(1);
  auto mixChannel = audioChannel->getChannelBuffer(2);
  uint32_t buffIndex = 0;
  for (unsigned int sample = 0; sample < numSamples; sample++) {
    rawData[buffIndex] = leftChannel->at(sample) * masterVolume;
    rawData[buffIndex + 1] = rightChannel->at(sample) * masterVolume;
    buffIndex += 2;
  }
  leftDataCallback(*leftChannel, leftChannel->begin(), leftChannel->end());
  rightDataCallback(*rightChannel, rightChannel->begin(), rightChannel->end());
  mixedDataCallback(*mixChannel, mixChannel->begin(), mixChannel->end());
  channelDataCallback(audioChannel.get());
  if (lastNote != notesEndIterator) {
    lastPlayedNoteCallback(*lastNote);
  }
  return rawData;
}

template <size_t T>
void Synthesizer<T>::generatorThread(unsigned int gID) {
  auto id = generators[gID]->getId();
  uint32_t numSamples = bufferSize / 2;
  auto genNote = GeneratorNote::fromNote(currentNote, id);
  float time = genNote.time;
  float env = genNote.envelopeTime;
  for (unsigned int sample = 0; sample < numSamples; sample++) {
    genNote.time = time + (float)sample / AudioSettings::SAMPLE_RATE;
    genNote.envelopeTime = env + (float)sample / AudioSettings::SAMPLE_RATE;
    if (!generators[gID]->isBypass()) {
      generators[gID]->addSample(generators[gID]->Value(genNote), sample);
    }
  }
  currentNote.state[id] = genNote.state;
  currentNote.envelopeTime[id] = genNote.envelopeTime;
}

template <size_t T>
void Synthesizer<T>::setMasterVolume(float value) {
  masterVolume = value;
}
