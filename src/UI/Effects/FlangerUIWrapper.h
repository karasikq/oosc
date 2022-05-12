//===-------------------- FlangerUIWrapper.h ---------------------*- C++-*-===//
//===------------ FlangerUIWrapper class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the FlangerUIWrapper class, which is
/// contains changeable parameters for effect and ready to connect to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef FLANGERUIWRAPPER_H
#define FLANGERUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Effects/Flanger.h"
#include "src/Parametrs/ChangeableParameter.h"

/// FlangerUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class FlangerUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  FlangerUIWrapper();
  ~FlangerUIWrapper();

  registerChangeableParameter(float, delay, Delay);
  registerChangeableParameter(float, flangerWidth, FlangerWidth);
  registerChangeableParameter(float, depth, Depth);
  registerChangeableParameter(float, feedback, Feedback);
  registerChangeableParameter(bool, invertedMode, InvertedMode);
  registerChangeableParameter(float, lfoFrequency, LfoFrequency);
  registerChangeableParameter(int, interpolation, Interpolation);
  registerChangeableParameter(int, lfoShape, LfoShape);

private:
  /// Casts @param value to InterpolationType and sets interpolation
  void setInterpolationType(int value);
  /// Casts @param value to WaveShape::Shape and sets lfoShape
  void setLfoShape(int value);
};

#endif // FLANGERUIWRAPPER_H
