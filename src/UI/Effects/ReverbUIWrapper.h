//===--------------------- ReverbUIWrapper.h ---------------------*- C++-*-===//
//===------------- ReverbUIWrapper class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ReverbUIWrapper class, which is
/// contains changeable parameters for effect and ready to connect to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef REVERBUIWRAPPER_H
#define REVERBUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Effects/Reverb.h"
#include "src/Parametrs/ChangeableParameter.h"

/// ReverbUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class ReverbUIWrapper : public EffectUIWrapper {
public:
  Q_OBJECT
public:
  ReverbUIWrapper();
  ~ReverbUIWrapper();

  registerChangeableParameter(float, reverbWidth, ReverbWidth);
  registerChangeableParameter(float, damping, Damping);
  registerChangeableParameter(float, roomSize, RoomSize);
  registerChangeableParameter(float, wet, Wet);
  registerChangeableParameter(float, dry, Dry);
};

#endif // REVERBUIWRAPPER_H
