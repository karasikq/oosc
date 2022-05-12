//===-------------------- SubGeneratorKnobs.h --------------------*- C++-*-===//
//===-------------- SubGeneratorKnobs class definition --------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the SubGeneratorKnobs class, which
/// is used for connect generator changeable parameters to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef SUBGENERATORKNOBS_H
#define SUBGENERATORKNOBS_H

#include "../Controls/Knob.h"
#include "GeneratorControl.h"
#include "src/UI/SynthesizerControls/SubGeneratorControl.h"
#include <QQuickItem>

/// SubGeneratorKnobs class
/// Used for connect generator changeable parameters to knobs
class SubGeneratorKnobs : public QQuickItem {
  Q_OBJECT
  Q_PROPERTY(SubGeneratorControl *generatorControl WRITE setGeneratorControl)
  Q_PROPERTY(Knob *panKnob READ getPanKnob WRITE setPanKnob NOTIFY knobAttached)
  Q_PROPERTY(
      Knob *gainKnob READ getGainKnob WRITE setGainKnob NOTIFY knobAttached)
  Q_PROPERTY(
      Knob *shapeKnob READ getShapeKnob WRITE setShapeKnob NOTIFY knobAttached)
public:
  SubGeneratorKnobs(QQuickItem *parent = 0);
  ~SubGeneratorKnobs();

  /// Should be called after all knobs are setted
  Q_INVOKABLE void attachKnobs();

  void setGeneratorControl(SubGeneratorControl *control);
  void setPanKnob(Knob *knob);
  void setGainKnob(Knob *knob);
  void setShapeKnob(Knob *knob);

  Knob *getPanKnob();
  Knob *getGainKnob();
  Knob *getShapeKnob();
signals:
  void knobAttached();

private:
  SubGeneratorControl *generatorControl;
  Knob *pan;
  Knob *gain;
  Knob *shape;
};

#endif // SUBGENERATORKNOBS_H
