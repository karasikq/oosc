#include "SubGenerator.h"
#include "src/Utils/WaveShape.h"

#include <iostream>

SubGenerator::SubGenerator(unsigned int generatorID) : AGenerator(generatorID) {
  waveTable =
      std::shared_ptr<WaveTable>(new WaveTable(WaveShape::Shape::SIN, 2048));
  envelope = std::shared_ptr<ADSREnvelope>(new ADSREnvelope());
}

SubGenerator::~SubGenerator() {}

std::pair<float, float> SubGenerator::Value(GeneratorNote &note) {
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
  float wvValue = waveTable->Value(
      M_PI_2M * NoteUtils::NoteToFreq(note.note + octaveOffset) * note.time);
  wvValue *= envelopeValue * level * note.velocity;
  return {wvValue * (1.0f - pan), wvValue * pan};
}

void SubGenerator::setPan(float value) { pan = value; }

void SubGenerator::setLevel(float value) { level = value; }

void SubGenerator::setOctaveOffset(int value) { octaveOffset = value * 12; }

void SubGenerator::setShape(int value) {
  shape = (WaveShape::Shape)value;
  waveTable->SetTable(shape);
}
