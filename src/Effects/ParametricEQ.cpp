#include "ParametricEQ.h"

#include <memory>

ParametricEQ::ParametricEQ(FilterType _type, uint32_t _numSamples) {
  type = _type;
  numSamples = _numSamples;
  sampleRate = AudioSettings::SAMPLE_RATE;
  cutoffFrequency = 1000.0f;
  QFactor = M_SQRT1_2f32;
  gain = FtoD(12.0f);
  createFilter();
}

ParametricEQ::ParametricEQ(FilterType _type,
                           float _cutoff,
                           float _q,
                           float _gain,
                           uint32_t _numSamples) {
  type = _type;
  cutoffFrequency = _cutoff;
  QFactor = _q;
  gain = ParametricEQ::FtoD(_gain);
  numSamples = _numSamples;
  sampleRate = AudioSettings::SAMPLE_RATE;
  createFilter();
}

ParametricEQ::ParametricEQ(uint32_t _numSamples) {
  type = FilterType::AllPass;
  numSamples = _numSamples;
  sampleRate = AudioSettings::SAMPLE_RATE;
  cutoffFrequency = 1000.0f;
  QFactor = M_SQRT1_2f32;
  gain = FtoD(12.0f);
  createFilter();
}

ParametricEQ::~ParametricEQ() = default;

void ParametricEQ::setFilterType(FilterType _type) {
  type = _type;
  updateCoefficients();
}

void ParametricEQ::setFrequency(float _frequency) {
  cutoffFrequency = _frequency;
  updateCoefficients();
}

void ParametricEQ::setQ(float _q) {
  QFactor = _q;
  updateCoefficients();
}

void ParametricEQ::setGain(float _gain) {
  gain = FtoD(_gain);
  updateCoefficients();
}

void ParametricEQ::createFilter() {
  iirLeft = std::make_unique<IIRFilter>();
  iirRight = std::make_unique<IIRFilter>();
  updateCoefficients();
}

void ParametricEQ::updateCoefficients() {
  switch (type) {
  case FilterType::LowPass:
    iirLeft->setCoefficients(
        IIRCoefficients::makeLowPass(sampleRate, cutoffFrequency, QFactor));
    iirRight->setCoefficients(
        IIRCoefficients::makeLowPass(sampleRate, cutoffFrequency, QFactor));
    break;
  case FilterType::HighPass:
    iirLeft->setCoefficients(
        IIRCoefficients::makeHighPass(sampleRate, cutoffFrequency, QFactor));
    iirRight->setCoefficients(
        IIRCoefficients::makeHighPass(sampleRate, cutoffFrequency, QFactor));
    break;
  case FilterType::LowShelf:
    iirLeft->setCoefficients(IIRCoefficients::makeLowShelf(
        sampleRate, cutoffFrequency, QFactor, gain));
    iirRight->setCoefficients(IIRCoefficients::makeLowShelf(
        sampleRate, cutoffFrequency, QFactor, gain));
    break;
  case FilterType::HighShelf:
    iirLeft->setCoefficients(IIRCoefficients::makeHighShelf(
        sampleRate, cutoffFrequency, QFactor, gain));
    iirRight->setCoefficients(IIRCoefficients::makeHighShelf(
        sampleRate, cutoffFrequency, QFactor, gain));
    break;
  case FilterType::BandPass:
    iirLeft->setCoefficients(
        IIRCoefficients::makeBandPass(sampleRate, cutoffFrequency, QFactor));
    iirRight->setCoefficients(
        IIRCoefficients::makeBandPass(sampleRate, cutoffFrequency, QFactor));
    break;
  case FilterType::BandStop:
    iirLeft->setCoefficients(
        IIRCoefficients::makeBandStop(sampleRate, cutoffFrequency, QFactor));
    iirRight->setCoefficients(
        IIRCoefficients::makeBandStop(sampleRate, cutoffFrequency, QFactor));
    break;
  case FilterType::AllPass:
    iirLeft->setCoefficients(
        IIRCoefficients::makeAllPass(sampleRate, cutoffFrequency, QFactor));
    iirRight->setCoefficients(
        IIRCoefficients::makeAllPass(sampleRate, cutoffFrequency, QFactor));
    break;
  case FilterType::Notch:
    iirLeft->setCoefficients(
        IIRCoefficients::makeNotch(sampleRate, cutoffFrequency, QFactor));
    iirRight->setCoefficients(
        IIRCoefficients::makeNotch(sampleRate, cutoffFrequency, QFactor));
    break;
  case FilterType::Peak:
    iirLeft->setCoefficients(IIRCoefficients::makePeakFilter(
        sampleRate, cutoffFrequency, QFactor, gain));
    iirRight->setCoefficients(IIRCoefficients::makePeakFilter(
        sampleRate, cutoffFrequency, QFactor, gain));
    break;
  default:
    iirLeft->setCoefficients(
        IIRCoefficients::makeHighPass(sampleRate, cutoffFrequency));
    iirRight->setCoefficients(
        IIRCoefficients::makeLowPass(sampleRate, cutoffFrequency));
    break;
  }
}

void ParametricEQ::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  iirLeft->process(*audioChannel.getChannelBuffer(0));
  if (audioChannel.getNumberOfChannels() == 2) {
    iirRight->process(*audioChannel.getChannelBuffer(1));
  }
}
