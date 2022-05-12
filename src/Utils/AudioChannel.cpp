#include "AudioChannel.h"

AudioChannel::AudioChannel(uint8_t channelsCount,
                           uint32_t _samplesPerChannel,
                           uint32_t _sampleRate) {
  numOfChannels = channelsCount;
  samplesPerChannel = _samplesPerChannel;
  sampleRate = _sampleRate;
  extrema.insert(extrema.begin(), channelsCount + 1, {1.f, -1.f, 0.f});
  for (auto i = 0; i < channelsCount + 1; i++) {
    channelsData.emplace_back();
    channelsData.at(i).resize(samplesPerChannel, 0.f);
  }
}

AudioChannel::~AudioChannel() = default;

std::vector<float> *AudioChannel::getChannelBuffer(uint8_t channelIndex) {
  return &channelsData[channelIndex];
}

void AudioChannel::clear() {
  for (uint32_t channelIndex = 0; channelIndex < numOfChannels;
       channelIndex++) {
    std::fill(channelsData[channelIndex].begin(),
              channelsData[channelIndex].end(),
              0.0f);
  }
}

void AudioChannel::clear(uint8_t channelIndex) {
  std::fill(channelsData[channelIndex].begin(),
            channelsData[channelIndex].end(),
            0.0f);
}

void AudioChannel::mix() {
  std::fill(extrema.begin(), extrema.end(), MinMax<float>(1.0f, -1.0f, 0.0f));
  for (uint32_t sample = 0; sample < samplesPerChannel; sample++) {
    float mixedValue = 0.0f;
    for (auto channel = 0; channel < numOfChannels; channel++) {
      float value = channelsData[channel][sample];
      if (value < extrema[channel].min) {
        extrema[channel].min = value;
      }
      if (value > extrema[channel].max) {
        extrema[channel].max = value;
      }
      mixedValue += value;
    }
    if (mixedValue < extrema.back().min) {
      extrema.back().min = mixedValue;
    }
    if (mixedValue > extrema.back().max) {
      extrema.back().max = mixedValue;
    }
    channelsData[numOfChannels][sample] = mixedValue;
  }
}

MinMax<float> AudioChannel::getExtrema(uint8_t channelIndex) const {
  return extrema[channelIndex];
}
