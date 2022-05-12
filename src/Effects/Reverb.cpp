#include "Reverb.h"

Reverb::Reverb(unsigned int sampleRate) {
  static const short combTunings[] = {
      1116, 1188, 1277, 1356, 1422, 1491, 1557, 1617}; // (at 44100Hz)
  static const short allPassTunings[] = {556, 441, 341, 225};
  const int stereoSpread = 23;

  allPassFilters.resize(2);
  for (size_t i = 0; i < allPassCount; i++) {
    allPassFilters[0].emplace_back(
        AllPassFilter((sampleRate * allPassTunings[i]) / 44100));
    allPassFilters[1].emplace_back(AllPassFilter(
        (sampleRate * (allPassTunings[i] + stereoSpread)) / 44100));
  }

  combFilters.resize(2);
  for (size_t i = 0; i < combsCount; i++) {
    combFilters[0].emplace_back(
        CombFilter((sampleRate * combTunings[i]) / 44100));
    combFilters[1].emplace_back(
        CombFilter((sampleRate * (combTunings[i] + stereoSpread)) / 44100));
  }
  setWet(wet);
  setDry(dry);
  setFreeze(freeze);
}

Reverb::~Reverb() {}

void Reverb::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  auto left = audioChannel.getChannelBuffer(0);
  auto right = audioChannel.getChannelBuffer(1);

  for (unsigned int i = 0; i < audioChannel.getSamplesPerChannel(); i++) {
    const float input = (left->at(i) + right->at(i)) * gain;
    float outL = 0, outR = 0;

    for (size_t i = 0; i < combsCount; ++i) {
      outL += combFilters[0][i].process(input, damping, feedback);
      outR += combFilters[1][i].process(input, damping, feedback);
    }

    for (size_t i = 0; i < allPassCount; i++) {
      outL = allPassFilters[0][i].process(outL);
      outR = allPassFilters[1][i].process(outR);
    }

    left->at(i) = outL * wetGainL + outR * wetGainR + left->at(i) * dryGain;
    right->at(i) = outR * wetGainL + outL * wetGainR + right->at(i) * dryGain;
  }
}

void Reverb::setDamping(float value) {
  damping = value;
  const float dampScaleFactor = 0.4f;
  if (freeze) {
    currentDamping = 0.0f;
  } else {
    currentDamping = damping * dampScaleFactor;
  }
}

void Reverb::setRoomSize(float value) {
  roomSize = value;
  const float roomScaleFactor = 0.28f;
  const float roomOffset = 0.7f;

  if (freeze) {
    feedback = 1.0f;
  } else {
    feedback = roomSize * roomScaleFactor + roomOffset;
  }
}

void Reverb::setWet(float value) {
  wet = value;
  const float wetScaleFactor = 3.0f;
  const float scaledWet = wet * wetScaleFactor;
  wetGainL = 0.5f * scaledWet * (1.0f + width);
  wetGainR = 0.5f * scaledWet * (1.0f - width);
}

void Reverb::setWidth(float value) {
  width = value;
  setWet(wet);
}

void Reverb::setDry(float value) {
  dry = value;
  const float dryScaleFactor = 2.0f;
  dryGain = dry * dryScaleFactor;
}

void Reverb::setFreeze(int value) {
  freeze = value;
  setWet(wet);
  setDry(dry);
  gain = freeze ? 0.0f : 0.015f;
  setDamping(damping);
  setRoomSize(roomSize);
}
