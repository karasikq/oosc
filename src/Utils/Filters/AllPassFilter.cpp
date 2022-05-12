#include "AllPassFilter.h"

AllPassFilter::AllPassFilter(unsigned int bufferSize) {
  buffer.resize(bufferSize);
  clear();
}

void AllPassFilter::clear() { std::fill(buffer.begin(), buffer.end(), 0.0f); }

float AllPassFilter::process(float input) {
  const float bufferedValue = buffer[bufferIndex];
  float temp = input + (bufferedValue * 0.5f);
  buffer[bufferIndex] = temp;
  bufferIndex = (bufferIndex + 1) % buffer.size();
  return bufferedValue - input;
}
