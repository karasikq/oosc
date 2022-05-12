//===-------------------- ChorusUIWrapper.h ----------------------*- C++-*-===//
//===----------- ChorusUIWrapper class definition--------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ChorusUIWrapper class,
/// which is contains changeable parameters for effect and ready to connect
/// to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef CHORUSUIWRAPPER_H
#define CHORUSUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Effects/Chorus.h"
#include "src/Parametrs/ChangeableParameter.h"

/// ChorusUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class ChorusUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  ChorusUIWrapper();
  ~ChorusUIWrapper();

  registerChangeableParameter(uint8_t, voices, Voices);
  registerChangeableParameter(float, delay, Delay);
  registerChangeableParameter(float, sweepWidth, SweepWidth);
  registerChangeableParameter(float, depth, Depth);
  registerChangeableParameter(float, rate, Rate);
  registerChangeableParameter(float, phase, Phase);
};

#endif // CHORUSUIWRAPPER_H
