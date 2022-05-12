#include "Generator.h"

#include <iostream>

Generator::Generator(unsigned int generatorID) : AGenerator(generatorID) {
  waveTable =
      std::shared_ptr<WaveTable>(new WaveTable(WaveShape::Shape::SIN, 2048));
  envelope = std::shared_ptr<ADSREnvelope>(new ADSREnvelope());

  gen = std::mt19937(unisonSeed);
  fineRange = std::uniform_int_distribution<>(5, 100);
  panRange = std::uniform_int_distribution<>(0, 50);
  levelRange = std::uniform_int_distribution<>(15, 60);
  int mult = -1;
  float maxFine = 1.0f;
  for (unsigned int i = 0; i < maxUnisonVoices; i++) {
    if (i == maxUnisonVoices / 2) {
      mult = 1;
      maxFine = 1.059463094;
    }
    computedUnison.push_back({0.f, 0.f, 0.f});
    float upan = static_cast<float>(panRange(gen)) / 100,
          ulevel = static_cast<float>(levelRange(gen)) / 100,
          ufine = powf(2.f, static_cast<float>(fineRange(gen) * mult) / 1200);
    unisonRange.push_back({{0.5f - upan, 0.5f + upan, 0.0f},
                           {0, ulevel, 0.0f},
                           {ufine, maxFine, 0.0f}});
  }
  calculateUnison();
}

Generator::~Generator() {}

std::pair<float, float> Generator::Value(GeneratorNote &note) {
  std::pair<float, float> voiceValue(0.f, 0.f);
  float envelopeValue = 0.0f;
  if (note.freezeState != ADSREnvelope::OFF) {
    if (note.envelopeTime > envelope->AbsoluteDecayTime()) {
      envelopeValue = envelope->PeakValue(note.freezeState);
    } else {
      envelopeValue = envelope->Envelope(note.envelopeTime, note.state);
    }
  } else {
    envelopeValue = envelope->Envelope(note.envelopeTime, note.state);
  }
  float freq = M_PI_2M *
               NoteUtils::NoteToFreq(note.note + octaveOffset + semitone) *
               note.time * cents;
  for (unsigned int i = 0; i < unisonVoices; i++) {
    float wvValue = waveTable->Value(freq * computedUnison[i].fine + phase);
    voiceValue.first +=
        wvValue * (1.0f - computedUnison[i].pan) * computedUnison[i].level;
    voiceValue.second +=
        wvValue * computedUnison[i].pan * computedUnison[i].level;
  }
  float env = envelopeValue * level * note.velocity;
  return {voiceValue.first * env * (1.0f - pan), voiceValue.second * env * pan};
}

void Generator::calculateUnison() {
  int pos = maxUnisonVoices / 2;
  int direction = -1;
  for (unsigned int i = 0; i < unisonVoices; i++) {
    if (i == unisonVoices / 2) {
      pos = maxUnisonVoices / 2 + 1;
      direction = 1;
      if (unisonVoices % 2 != 0) {
        computedUnison[i] = {0.5f, 1.0f, 1.0f};
        continue;
      }
    }
    auto &range = unisonRange[pos - 1];
    computedUnison[i] = {
        range.pan.value(unisonPan),
        range.level.value(unisonLevel),
        range.fine.value((direction == 1) ? 1.0f - unisonFine : unisonFine)};
    pos += direction;
  }
}

void Generator::setPan(float value) { pan = value; }

void Generator::setLevel(float value) { level = value; }

void Generator::setOctaveOffset(int value) { octaveOffset = value * 12; }

void Generator::setSemitoneOffset(int value) { semitone = value; }

void Generator::setPhase(float value) { phase = value; }

void Generator::setCents(int value) {
  cents = powf(2.f, static_cast<float>(value) / 1200);
}

void Generator::setUnisonVoices(unsigned int value) {
  if (unisonVoices == value) {
    return;
  }
  unisonVoices = value;
  calculateUnison();
}

void Generator::setUnisonPan(float value) {
  unisonPan = value;
  calculateUnison();
}

void Generator::setUnisonLevel(float value) {
  unisonLevel = value;
  calculateUnison();
}

void Generator::setUnisonFine(float value) {
  unisonFine = value;
  calculateUnison();
}
