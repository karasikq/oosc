#include "LFO.h"

float LFO::Value(float time) {
  return 0.5f + 0.5f * WaveShape::Value(time, shape);
}

float LFO::Value(float time, Shape _shape) {
  return 0.5f + 0.5f * WaveShape::Value(time, _shape);
}
