//===-------------------- VibratoUIWrapper.h ---------------------*- C++-*-===//
//===------------ VibratoUIWrapper class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the VibratoUIWrapper class, which is
/// contains changeable parameters for effect and ready to connect to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef VIBRATOUIWRAPPER_H
#define VIBRATOUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Effects/Flanger.h"
#include "src/Parametrs/ChangeableParameter.h"

/// VibratoUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class VibratoUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  VibratoUIWrapper();
  ~VibratoUIWrapper();

  registerChangeableParameter(float, vibratoWidth, VibratoWidth);
  registerChangeableParameter(float, lfoFrequency, LfoFrequency);
  registerChangeableParameter(int, interpolation, Interpolation);
  registerChangeableParameter(int, lfoShape, LfoShape);

private:
  /// Casts @param value to InterpolationType and sets interpolation
  void setInterpolationType(int value);
  /// Casts @param value to WaveShape::Shape and sets lfoShape
  void setLfoShape(int value);
};

#endif // VIBRATOUIWRAPPER_H
