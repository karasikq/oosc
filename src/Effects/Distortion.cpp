#include "Distortion.h"

Distortion::Distortion(uint8_t channelsCount) {
  filters.clear();
  filters.insert(filters.begin(), channelsCount, IIRFilter());
  updateFilters();
}

Distortion::~Distortion() = default;

void Distortion::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    float out = 0.f;
    auto channel = audioChannel.getChannelBuffer(channelIndex);
    for (unsigned int sample = 0; sample < audioChannel.getSamplesPerChannel();
         ++sample) {
      float in = channel->at(sample) * inputGain;

      switch (distortionType) {
      case FullWave: {
        out = fabsf(in);
        break;
      }
      case HalfWave: {
        if (in > 0.0f)
          out = in;
        else
          out = 0.0f;
        break;
      }
      case HardClipping: {
        float threshold = 0.5f;
        if (in > threshold)
          out = threshold;
        else if (in < -threshold)
          out = -threshold;
        else
          out = in;
        break;
      }
      case SoftClipping: {
        float threshold1 = 1.0f / 3.0f;
        float threshold2 = 2.0f / 3.0f;
        if (in > threshold2)
          out = 1.0f;
        else if (in > threshold1)
          out = 1.0f - powf(2.0f - 3.0f * in, 2.0f) / 3.0f;
        else if (in < -threshold2)
          out = -1.0f;
        else if (in < -threshold1)
          out = -1.0f + powf(2.0f + 3.0f * in, 2.0f) / 3.0f;
        else
          out = 2.0f * in;
        out *= 0.5f;
        break;
      }
      case Exponential: {
        if (in > 0.0f)
          out = 1.0f - expf(-in);
        else
          out = -1.0f + expf(in);
        break;
      }
      }

      float filteredOutput = filters[channelIndex].process(out);
      channel->at(sample) = filteredOutput * outputGain;
    }
  }
}

void Distortion::updateFilters() {
  IIRCoefficients coefs = distortionCoefficients(0.0314159265f, tone);
  for (auto &filter : filters) {
    filter.setCoefficients(coefs);
  }
}

IIRCoefficients Distortion::distortionCoefficients(float freq, float gain) {
  float tan_half_wc = tanf(freq * 0.5f);
  float sqrt_gain = sqrtf(gain);
  return IIRCoefficients(sqrt_gain * tan_half_wc + gain,
                         sqrt_gain * tan_half_wc - gain,
                         0.0f,
                         sqrt_gain * tan_half_wc + 1.0f,
                         sqrt_gain * tan_half_wc - 1.0f,
                         0.0f);
}
