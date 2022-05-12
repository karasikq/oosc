#include "CombFilter.h"

CombFilter::CombFilter(unsigned int bufferSize) {
  bufferIndex = 0;
  last = 0;
  buffer.resize(bufferSize);
  clear();
}

CombFilter::~CombFilter() {}

void CombFilter::clear() { std::fill(buffer.begin(), buffer.end(), 0.0f); }

float CombFilter::process(const float &input,
                          const float &damp,
                          const float &feedback) {
  const float output = buffer[bufferIndex];
  last = (output * (1.0f - damp)) + (last * damp);

  float temp = input + (last * feedback);
  buffer[bufferIndex] = temp;
  bufferIndex = (bufferIndex - 1) % buffer.size();
  return output;
}
