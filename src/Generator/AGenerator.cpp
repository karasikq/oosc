#include "AGenerator.h"

AGenerator::AGenerator(unsigned int generatorID) {
  this->generatorID = generatorID;
  this->bypass = false;
}

AGenerator::~AGenerator() {}

std::pair<float, float> AGenerator::Value(GeneratorNote &note) {
  (void)(note);
  return {0.f, 0.f};
}

void AGenerator::clear() { audioChannel.clear(); }

void AGenerator::addSample(const std::pair<float, float> &data,
                           uint32_t sample) {
  audioChannel.getChannelBuffer(0)->at(sample) += data.first;
  audioChannel.getChannelBuffer(1)->at(sample) += data.second;
}

unsigned int AGenerator::getId() { return generatorID; }

void AGenerator::setWavetable(const std::shared_ptr<WaveTable> &waveTable) {
  this->waveTable = waveTable;
}

void AGenerator::setEnvelope(const std::shared_ptr<ADSREnvelope> &envelope) {
  this->envelope = envelope;
}

void AGenerator::setBypass(bool value) { this->bypass = value; }

WaveTable *AGenerator::getWaveTable() { return waveTable.get(); }

ADSREnvelope *AGenerator::getEnvelope() { return envelope.get(); }
