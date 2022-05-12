#include "WaveShape.h"
#include <math.h>

float WaveShape::Value(float time) { return Value(time, shape); }

float WaveShape::Value(float time, Shape _shape) {
  float mod = 0.0;
  switch (_shape) {
  case Shape::SIN:
    return sin(time);
    break;
  case Shape::SQUARE:
    mod = (float)fmod(time, M_PI_2M);
    if (mod < M_PIf32) {
      return 1.0f;
    } else {
      return -1.0f;
    }
    break;
  case Shape::SAW:
    mod = (float)(fmod(time, M_PI_2M) - M_PIf32);
    return mod / M_PIf32;
    break;
  case Shape::SAW2:
    mod = (float)(fmod(time, M_PI_2M) - M_PIf32);
    return 1.0f - 2.0f * abs(mod) / M_PIf32;
    break;
  default:
    return 0.0f;
  }
}
