//===------------------ GeneratorKnobsControl.h ------------------*- C++-*-===//
//===--------- GeneratorKnobsControl class definition ---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the GeneratorKnobsControl class, which
/// is used for connect generator changeable parameters to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef GENERATORKNOBSCONTROL_H
#define GENERATORKNOBSCONTROL_H

#include "../Controls/Knob.h"
#include "GeneratorControl.h"
#include <QQuickItem>

/// GeneratorKnobsControl class
/// Used for connect generator changeable parameters to knobs
class GeneratorKnobsControl : public QQuickItem {
  Q_OBJECT
  Q_PROPERTY(GeneratorControl *generatorControl WRITE setGeneratorControl)
  Q_PROPERTY(Knob *posKnob READ getPosKnob WRITE setPosKnob NOTIFY knobAttached)
  Q_PROPERTY(Knob *panKnob READ getPanKnob WRITE setPanKnob NOTIFY knobAttached)
  Q_PROPERTY(
      Knob *gainKnob READ getGainKnob WRITE setGainKnob NOTIFY knobAttached)
  Q_PROPERTY(
      Knob *phaseKnob READ getPhaseKnob WRITE setPhaseKnob NOTIFY knobAttached)
  Q_PROPERTY(Knob *unisonVoicesKnob READ getUnisonVoicesKnob WRITE
                 setUnisonVoicesKnob NOTIFY knobAttached)
  Q_PROPERTY(Knob *unisonPanKnob READ getUnisonPanKnob WRITE setUnisonPanKnob
                 NOTIFY knobAttached)
  Q_PROPERTY(Knob *unisonLevelKnob READ getUnisonLevelKnob WRITE
                 setUnisonLevelKnob NOTIFY knobAttached)
  Q_PROPERTY(Knob *unisonFineKnob READ getUnisonFineKnob WRITE setUnisonFineKnob
                 NOTIFY knobAttached)
public:
  GeneratorKnobsControl(QQuickItem *parent = 0);
  ~GeneratorKnobsControl();

  /// Should be called after all knobs are setted
  Q_INVOKABLE void attachKnobs();

  void setGeneratorControl(GeneratorControl *control);
  void setPosKnob(Knob *knob);
  void setPanKnob(Knob *knob);
  void setGainKnob(Knob *knob);
  void setPhaseKnob(Knob *knob);
  void setUnisonVoicesKnob(Knob *knob);
  void setUnisonPanKnob(Knob *knob);
  void setUnisonLevelKnob(Knob *knob);
  void setUnisonFineKnob(Knob *knob);

  Knob *getPosKnob();
  Knob *getPanKnob();
  Knob *getGainKnob();
  Knob *getPhaseKnob();
  Knob *getUnisonVoicesKnob();
  Knob *getUnisonPanKnob();
  Knob *getUnisonLevelKnob();
  Knob *getUnisonFineKnob();
signals:
  void knobAttached();

private:
  GeneratorControl *generatorControl;
  Knob *pos;
  Knob *pan;
  Knob *gain;
  Knob *phase;
  Knob *unisonVoices;
  Knob *unisonPan;
  Knob *unisonLevel;
  Knob *unisonFine;
};

#endif // GENERATORKNOBSCONTROL_H
