#include "Delay.h"
#include <cstring>
#include <iostream>
#include <math.h>

Delay::Delay(unsigned int _numSamples, const MinMax<float> &timeRange) {
  this->timeRange = timeRange;
  time = timeRange.getCurrent();
  delayTimeSampled = time * AudioSettings::SAMPLE_RATE;
  bufferSize = round(timeRange.max * AudioSettings::SAMPLE_RATE);
  numSamples = _numSamples;
  bufferPosition = 0;
  delayBuffer = std::unique_ptr<AudioChannel>(new AudioChannel(2, bufferSize));
}

Delay::~Delay() {}

void Delay::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  unsigned int localWritePosition = 0;

  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    localWritePosition = bufferPosition;
    for (unsigned int sample = 0; sample < numSamples; ++sample) {
      const float in = audioChannel.getChannelBuffer(channelIndex)->at(sample);
      float out = 0.0f;

      float readPosition = fmodf((float)localWritePosition - delayTimeSampled +
                                     (float)bufferSize,
                                 bufferSize);
      unsigned int localReadPosition = floorf(readPosition);

      if (localReadPosition != localWritePosition) {
        float fraction = readPosition - (float)localReadPosition;
        float delayed1 = delayBuffer->getChannelBuffer(channelIndex)
                             ->at(localReadPosition + 0);
        float delayed2 = delayBuffer->getChannelBuffer(channelIndex)
                             ->at((localReadPosition + 1) % bufferSize);
        out = delayed1 + fraction * (delayed2 - delayed1);

        audioChannel.getChannelBuffer(channelIndex)->at(sample) =
            in + mix * (out - in);
        delayBuffer->getChannelBuffer(channelIndex)->at(localWritePosition) =
            in + out * feedback;
      }

      if (++localWritePosition >= bufferSize)
        localWritePosition -= bufferSize;
    }
  }
  bufferPosition = localWritePosition;
}

void Delay::setTime(float value) {
  time = value;
  delayTimeSampled = time * AudioSettings::SAMPLE_RATE;
}
