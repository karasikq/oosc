#include "Phaser.h"
#include <iostream>
#include <math.h>
#include <string>

Phaser::Phaser(unsigned int sampleRate) {
  this->sampleRate = sampleRate;
  lfoPhase = 0.0f;
  updateCounter = 0;
  updateInterval = 32;
  filters.insert(filters.begin(), numberOfFilters * 2, IIRFilter());
  outputs.insert(outputs.begin(), 2, 0.0f);
}

Phaser::~Phaser() {}

void Phaser::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  float phase = 0.0f;
  float startPhase = 0.0f;
  unsigned int sampleCounter = 0;
  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    auto channel = audioChannel.getChannelBuffer(channelIndex);
    sampleCounter = updateCounter;
    phase = lfoPhase;
    if (channelIndex > 0) {
      phase += 0.2617f;
    }
    for (unsigned int sample = 0; sample < audioChannel.getSamplesPerChannel();
         sample++) {
      float in = channel->at(sample);

      float centreFrequency = lfo.Value(M_PI_2M * phase, lfoShape);
      centreFrequency *= width;
      centreFrequency += filterFrequency;

      phase += lfoFrequency / sampleRate;

      if (sampleCounter++ % updateInterval == 0)
        updateFilters(centreFrequency);

      float filtered = in + feedback * outputs[channelIndex];
      for (int i = 0; i < numberOfFilters; ++i) {
        filtered =
            filters[channelIndex * numberOfFilters + i].process(filtered);
      }

      outputs[channelIndex] = filtered;
      channel->at(sample) = in + depth * (filtered - in) * 0.5f;
    }
    if (channelIndex == 0)
      startPhase = phase;
  }
  updateCounter = sampleCounter;
  lfoPhase = startPhase;
}

void Phaser::updateFilters(float freq) {
  IIRCoefficients coefs = phaserCoefficients(freq);
  for (auto &filter : filters) {
    filter.setCoefficients(coefs);
  }
}

IIRCoefficients Phaser::phaserCoefficients(float freq) {
  double wc = fminf(freq, M_PIf32 * 0.99f);
  double tan_half_wc = tanf(wc * 0.5f);

  return IIRCoefficients(tan_half_wc - 1.0,
                         tan_half_wc + 1.0,
                         0.0,
                         tan_half_wc + 1.0,
                         tan_half_wc - 1.0,
                         0.0);
}

void Phaser::setNumberOfFilters(int value) {
  if (numberOfFilters == value)
    return;

  numberOfFilters = value;
  filters.clear();
  filters.insert(filters.begin(), numberOfFilters * 2, IIRFilter());
}
