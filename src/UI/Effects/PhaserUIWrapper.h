//===--------------------- PhaserUIWrapper.h ---------------------*- C++-*-===//
//===------------- PhaserUIWrapper class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the PhaserUIWrapper class, which is
/// contains changeable parameters for effect and ready to connect to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef PHASERUIWRAPPER_H
#define PHASERUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Parametrs/ChangeableParameter.h"

/// PhaserUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class PhaserUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  PhaserUIWrapper();
  ~PhaserUIWrapper();

  registerChangeableParameter(int, lfoShape, LfoShape);
  registerChangeableParameter(float, phaseWidth, PhaseWidth);
  registerChangeableParameter(float, depth, Depth);
  registerChangeableParameter(int, numberOfFilters, NumberOfFilters);
  registerChangeableParameter(float, lfoFrequency, LfoFrequency);
  registerChangeableParameter(float, filterFrequency, FilterFrequency);
  registerChangeableParameter(float, feedback, Feedback);

private:
  /// Sets number of filters to associated phaser effect
  void setNumberOfFilters(int value);
  /// Casts @param value to WaveShape::Shape and sets lfoShape
  void setLfoShape(int value);
};

#endif // PHASERUIWRAPPER_H
