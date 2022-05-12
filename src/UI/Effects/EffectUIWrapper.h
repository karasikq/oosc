//===-------------------- EffectUIWrapper.h ----------------------*- C++-*-===//
//===------------ EffectUIWrapper class definition-------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the EffectUIWrapper class,
/// which is the base class for all effect UI wrappers.
///
//===----------------------------------------------------------------------===//

#ifndef EFFECTUIWRAPPER_H
#define EFFECTUIWRAPPER_H

#include "src/Effects/Effect.h"
#include "src/Utils/WaveShape.h"
#include <QQuickItem>
#include <map>
#include <qtmetamacros.h>

/// Macro that create changeable parameter for effect property
#define registerChangeableParameter(type, name, Name)                          \
private:                                                                       \
  Q_PROPERTY(IChangeableParameter *name READ get##Name CONSTANT)               \
protected:                                                                     \
  ChangeableParameter<type> name;                                              \
                                                                               \
public:                                                                        \
  IChangeableParameter *get##Name() { return &name; }

/// EffectUIWrapper class,
/// Base class for all effect UI wrappers.
class EffectUIWrapper : public QQuickItem {
  Q_OBJECT
  Q_PROPERTY(Effect *effect READ getEffect CONSTANT)
public:
  EffectUIWrapper();
  ~EffectUIWrapper();

  /// Returns this casted to Effect *
  Effect *getEffect();

  /// Converts casted to int InterpolationType to QString
  Q_INVOKABLE QString interpolationToString(int value);
  /// Converts casted to int LfoShape to QString
  Q_INVOKABLE QString lfoShapeToString(int value);

protected:
  std::unique_ptr<Effect> effect;

private:
  const std::map<InterpolationType, QString> interpolationStrings = {
      {InterpolationType::NearestNeighbour, "Nearest"},
      {InterpolationType::Linear, "Linear"},
      {InterpolationType::Cubic, "Cubic"}};
  const std::map<WaveShape::Shape, QString> lfoShapeStrings = {
      {WaveShape::Shape::SIN, "Sine"},
      {WaveShape::Shape::SQUARE, "Square"},
      {WaveShape::Shape::SAW, "Saw"},
      {WaveShape::Shape::SAW2, "Saw 2"}};
};

#endif // EFFECTUIWRAPPER_H
