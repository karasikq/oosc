#include "Compressor.h"

Compressor::Compressor() { this->previousGain = 0.0f; }

Compressor::~Compressor() = default;

Compressor::Compressor(float threshold,
                       float ratio,
                       float attack,
                       float release,
                       float gain) {
  this->threshold = threshold;
  this->ratio = ratio;
  this->attack = attack;
  this->release = release;
  this->gain = gain;
  this->previousGain = 0.0f;
}

void Compressor::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  float alphaA = expTime(attack);
  float alphaR = expTime(release);

  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    for (unsigned int sample = 0; sample < audioChannel.getSamplesPerChannel();
         ++sample) {
      float in = audioChannel.getChannelBuffer(channelIndex)->at(sample);
      float squaredInput = powf(in, 2.0f);
      float xgain =
          (squaredInput <= 1e-6f) ? -60.0f : 10.0f * log10f(squaredInput);
      float ygain = 0.0f;
      if (xgain < threshold)
        ygain = xgain;
      else
        ygain = threshold + (xgain - threshold) / ratio;

      float xdiff = xgain - ygain;
      float ydiff = 0.0f;

      if (xdiff > previousGain)
        ydiff = alphaA * previousGain + (1.0f - alphaA) * xdiff;
      else
        ydiff = alphaR * previousGain + (1.0f - alphaR) * xdiff;

      float correction = powf(10.0f, (this->gain - ydiff) * 0.05f);
      previousGain = ydiff;
      audioChannel.getChannelBuffer(channelIndex)->at(sample) = in * correction;
    }
  }
}
