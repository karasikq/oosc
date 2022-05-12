//===---------------------- LfoController.h ----------------------*- C++-*-===//
//===-------------- LfoController class definition ------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the LfoController class, which
/// is the Qt Quick wrapper for LFO.
///
//===----------------------------------------------------------------------===//

#ifndef LFOCONTROLLER_H
#define LFOCONTROLLER_H

#include "src/Generator/Synthesizer.h"
#include "src/MixerOutput.h"
#include "src/Parametrs/ChangeableParameter.h"
#include "src/Utils/ITimeReceiver.h"
#include "src/Utils/LFO.h"
#include "GeneratorControl.h"
#include "src/Parametrs/AValueSender.h"
#include <QQuickItem>
#include <QVariant>
#include <map>
#include <memory>

/// LfoController class
/// The Qt Quick wrapper for LFO
class LfoController : public QQuickItem,
                      public ITimeReceiver,
                      public AValueSender {
  Q_OBJECT
  Q_PROPERTY(IChangeableParameter *phase READ getPhase CONSTANT)
  Q_PROPERTY(IChangeableParameter *frequency READ getFrequency CONSTANT)
  Q_PROPERTY(IChangeableParameter *waveshape READ getWaveshape CONSTANT)
  Q_PROPERTY(AValueSender *sender READ getValueSender CONSTANT)
  Q_PROPERTY(ADataReceiver *drawer WRITE setDrawer)
  Q_PROPERTY(ITimeReceiver *timeReceiver READ getTimeReceiver CONSTANT)
public:
  LfoController();
  /// Called when MixerOutput starts processing new block
  void UpdateTime(float time) override;
  void processValue(float value) override;

  /// Used for synchronize lfo frequency to BPM
  enum SyncTime { p1_16, p1_8, p1_4, p1_2, p1, p2, p4 };

  IChangeableParameter *getPhase() { return &phaseParameter; }
  IChangeableParameter *getFrequency() { return &frequencyParameter; }
  IChangeableParameter *getWaveshape() { return &waveshapeParameter; }
  AValueSender *getValueSender() { return static_cast<AValueSender *>(this); }

  void setDrawer(ADataReceiver *drawer);
signals:
  void lfoValueChanged(float value);
  void lfoShapeChanged(const std::vector<float> &data,
                       std::vector<float>::const_iterator from,
                       std::vector<float>::const_iterator to);

private:
  LFO lfo;
  ChangeableParameter<float> phaseParameter;
  ChangeableParameter<float> frequencyParameter;
  ChangeableParameter<int> waveshapeParameter;

  float phase;
  float frequency;
  WaveShape::Shape waveshape;
  void setPhase(float value);
  void setFrequency(float value);
  void setWaveshape(int value);

  WaveTable wavetable;
};

#endif // LFOCONTROLLER_H
