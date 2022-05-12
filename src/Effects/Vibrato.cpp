#include "Vibrato.h"

Vibrato::Vibrato(const MinMax<float> &timeRange) {
  this->lfoPhase = 0.0f;
  this->timeRange = timeRange;
  delayTimeSampled = timeRange.getCurrent() * AudioSettings::SAMPLE_RATE;
  bufferSize = round(timeRange.max * AudioSettings::SAMPLE_RATE) + 1;
  bufferPosition = 0;
  delayBuffer = std::unique_ptr<AudioChannel>(new AudioChannel(2, bufferSize));
  delayBuffer->clear();
}

Vibrato::~Vibrato() = default;

void Vibrato::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  unsigned int localWritePosition = 0;
  float phase = 0;
  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    auto channel = audioChannel.getChannelBuffer(channelIndex);
    auto delay = delayBuffer->getChannelBuffer(channelIndex);
    localWritePosition = bufferPosition;
    phase = lfoPhase;
    for (unsigned int sample = 0; sample < audioChannel.getSamplesPerChannel();
         sample++) {
      float in = channel->at(sample);
      float out = 0.f;

      float localDelayTime = width * lfo.Value(M_PI_2M * phase, lfoShape) *
                             audioChannel.getSampleRate();

      float readPosition = fmodf((float)localWritePosition - localDelayTime +
                                     (float)bufferSize - 1.0f,
                                 bufferSize);
      int localReadPosition = floorf(readPosition);

      switch (interpolation) {
      case NearestNeighbour: {
        float closestSample = delay->at(localReadPosition % bufferSize);
        out = closestSample;
        break;
      }
      case Linear: {
        float fraction = readPosition - (float)localReadPosition;
        float delayed0 = delay->at(localReadPosition + 0);
        float delayed1 = delay->at((localReadPosition + 1) % bufferSize);
        out = delayed0 + fraction * (delayed1 - delayed0);
        break;
      }
      case Cubic: {
        float fraction = readPosition - (float)localReadPosition;
        float fractionSqrt = fraction * fraction;
        float fractionCube = fractionSqrt * fraction;

        float sample1 = delay->at((localReadPosition + 0));
        float sample0 =
            delay->at((localReadPosition - 1 + bufferSize) % bufferSize);
        float sample2 = delay->at((localReadPosition + 1) % bufferSize);
        float sample3 = delay->at((localReadPosition + 2) % bufferSize);

        float a0 =
            -0.5f * sample0 + 1.5f * sample1 - 1.5f * sample2 + 0.5f * sample3;
        float a1 = sample0 - 2.5f * sample1 + 2.0f * sample2 - 0.5f * sample3;
        float a2 = -0.5f * sample0 + 0.5f * sample2;
        float a3 = sample1;
        out = a0 * fractionCube + a1 * fractionSqrt + a2 * fraction + a3;
        break;
      }
      }
      channel->at(sample) = out;
      delay->at(localWritePosition) = in;

      if (++localWritePosition >= bufferSize) {
        localWritePosition -= bufferSize;
      }

      phase += lfoFrequency / audioChannel.getSampleRate();
    }
  }
  bufferPosition = localWritePosition;
  lfoPhase = phase;
}
