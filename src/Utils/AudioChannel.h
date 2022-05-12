//===------------------------- AudioChannel.h --------------------*- C++-*-===//
//===---------------- AudioChannel class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AudioChannel class, which
/// is the used for storing audio data in 32-bit float type.
///
//===----------------------------------------------------------------------===//

#ifndef AUDIOCHANNEL_H
#define AUDIOCHANNEL_H

#include <algorithm>
#include <cinttypes>
#include <vector>

#include "src/AudioSettings.h"
#include "src/Utils/MinMax.h"

class AudioChannel {
public:
  explicit AudioChannel(
      uint8_t channelsCount = 2,
      uint32_t _samplesPerChannel = AudioSettings::BUFFER_SIZE,
      uint32_t _sampleRate = AudioSettings::SAMPLE_RATE);
  ~AudioChannel();

  /// Fills all buffers with zeros
  void clear();
  /// Fills @param channelIndex buffer with zeros
  void clear(uint8_t channelIndex);
  /// Returns @param channelIndex buffer
  std::vector<float> *getChannelBuffer(uint8_t channelIndex);
  /// Returns minimum and maximum value at @param channelIndex
  MinMax<float> getExtrema(uint8_t channelIndex) const;
  /// Returns count of audio channel except of mixed
  inline uint8_t getNumberOfChannels() const { return numOfChannels; }
  /// Returns samples per channel
  inline uint32_t getSamplesPerChannel() const { return samplesPerChannel; }
  /// Returns channel's sample rate
  inline uint32_t getSampleRate() const { return sampleRate; }
  /// Returns sample from @param channel and @param sample offset
  inline float getSample(uint8_t channel, uint32_t sample) const {
    return channelsData[channel][sample];
  }
  /// Mix channels to mixed buffer
  void mix();

private:
  uint8_t numOfChannels;
  uint32_t samplesPerChannel;
  uint32_t sampleRate;
  /// Channels buffer
  std::vector<std::vector<float>> channelsData;
  /// Buffer of extremas
  std::vector<MinMax<float>> extrema;
};

#endif // AUDIOCHANNEL_H
