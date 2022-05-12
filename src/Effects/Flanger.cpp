#include "Flanger.h"
#include <iostream>
#include <math.h>
#include <string>

Flanger::Flanger(unsigned int _numSamples, const MinMax<float> &delay) {
  this->delay = delay;
  flangerTimeSampled = delay.getCurrent() * AudioSettings::SAMPLE_RATE;
  bufferSize = round(delay.max * AudioSettings::SAMPLE_RATE + 1);
  numSamples = _numSamples;
  bufferPosition = 0;
  lfoPhase = 0.0f;
  flangerBuffer =
      std::unique_ptr<AudioChannel>(new AudioChannel(2, bufferSize));
}

Flanger::~Flanger() {}

void Flanger::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  unsigned int localWritePosition = 0;
  float phase = 0.0f;
  float startPhase = 0.0f;
  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    auto channel = audioChannel.getChannelBuffer(channelIndex);
    auto flanger = flangerBuffer->getChannelBuffer(channelIndex);
    localWritePosition = bufferPosition;
    phase = lfoPhase;
    if (channelIndex > 0) {
      phase += 0.2617f;
    }
    for (unsigned int sample = 0; sample < audioChannel.getSamplesPerChannel();
         sample++) {
      float in = channel->at(sample);
      float out = 0.f;

      float localDelayTime =
          (delay.getCurrent() + width * lfo.Value(M_PI_2M * phase, lfoShape)) *
          audioChannel.getSampleRate();

      float readPosition = fmodf((float)localWritePosition - localDelayTime +
                                     (float)bufferSize - 1.0f,
                                 bufferSize);
      int localReadPosition = floorf(readPosition);

      switch (interpolation) {
      case NearestNeighbour: {
        float closestSample = flanger->at(localReadPosition % bufferSize);
        out = closestSample;
        break;
      }
      case Linear: {
        float fraction = readPosition - (float)localReadPosition;
        float flangered0 = flanger->at(localReadPosition + 0);
        float flangered1 = flanger->at((localReadPosition + 1) % bufferSize);
        out = flangered0 + fraction * (flangered1 - flangered0);
        break;
      }
      case Cubic: {
        float fraction = readPosition - (float)localReadPosition;
        float fractionSqrt = fraction * fraction;
        float fractionCube = fractionSqrt * fraction;

        float sample1 = flanger->at((localReadPosition + 0));
        float sample0 =
            flanger->at((localReadPosition - 1 + bufferSize) % bufferSize);
        float sample2 = flanger->at((localReadPosition + 1) % bufferSize);
        float sample3 = flanger->at((localReadPosition + 2) % bufferSize);

        float a0 =
            -0.5f * sample0 + 1.5f * sample1 - 1.5f * sample2 + 0.5f * sample3;
        float a1 = sample0 - 2.5f * sample1 + 2.0f * sample2 - 0.5f * sample3;
        float a2 = -0.5f * sample0 + 0.5f * sample2;
        float a3 = sample1;
        out = a0 * fractionCube + a1 * fractionSqrt + a2 * fraction + a3;
        break;
      }
      }

      float inverted = (invertedMode) ? -1.f : 1.f;
      channel->at(sample) = in + out * depth * inverted;
      flanger->at(localWritePosition) = in + out * feedback;

      if (++localWritePosition >= bufferSize) {
        localWritePosition -= bufferSize;
      }

      phase += lfoFrequency / audioChannel.getSampleRate();
    }
    if (channelIndex == 0)
      startPhase = phase;
  }
  bufferPosition = localWritePosition;
  lfoPhase = startPhase;
}

void Flanger::setDelay(float value) { delay.setCurrent(value); }
