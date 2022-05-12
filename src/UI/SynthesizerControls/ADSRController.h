//===---------------------- ADSRController.h ---------------------*- C++-*-===//
//===-------------- ADSRController class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ADSRController class, which is
/// the QtQuick wrapper for ADSREnvelope with changeable parameters and 
/// ADSR drawer control.
///
//===----------------------------------------------------------------------===//

#ifndef ADSRCONTROLLER_H
#define ADSRCONTROLLER_H

#include "src/Parametrs/AValueSender.h"
#include "src/UI/Charts/ADSRDrawer.h"
#include "src/UI/Charts/ADataReceiver.h"
#include <QQuickItem>
#include <QVariant>
#include <map>
#include <memory>

/// Slots for ADSRController
class ADSRSlots;

/// ADSRController class
/// The QtQuick wrapper for ADSREnvelope with changeable parameters and 
/// ADSR drawer control.
class ADSRController : public QQuickItem,
                       public AValueSender,
                       public ADataReceiver {
  Q_OBJECT
  Q_PROPERTY(IChangeableParameter *attack READ getAttack CONSTANT)
  Q_PROPERTY(IChangeableParameter *decay READ getDecay CONSTANT)
  Q_PROPERTY(IChangeableParameter *sustain READ getSustain CONSTANT)
  Q_PROPERTY(IChangeableParameter *release READ getRelease CONSTANT)
  Q_PROPERTY(
      ADSRDrawer *drawer READ getDrawer WRITE setDrawer NOTIFY drawerChanged)
  Q_PROPERTY(AValueSender *sender READ getValueSender CONSTANT)
  Q_PROPERTY(ADataReceiver *dataReceiver READ getDataReceiver CONSTANT)
public:
  friend class ADSRSlots;
  ADSRController();

  /// Returns associated envelope
  std::shared_ptr<ADSREnvelope> getEnvelope() { return envelope; }
  IChangeableParameter *getAttack() { return &attackParameter; }
  IChangeableParameter *getDecay() { return &decayParameter; }
  IChangeableParameter *getSustain() { return &sustainParameter; }
  IChangeableParameter *getRelease() { return &releaseParameter; }
  /// Returns associated ADSRDrawer
  ADSRDrawer *getDrawer() { return drawer; }
  AValueSender *getValueSender() { return static_cast<AValueSender *>(this); }

signals:
  void envelopeChanged();
  void drawerChanged(ADSRDrawer *drawer);

private:
  ChangeableParameter<float> attackParameter;
  ChangeableParameter<float> decayParameter;
  ChangeableParameter<float> sustainParameter;
  ChangeableParameter<float> releaseParameter;

  std::shared_ptr<ADSREnvelope> envelope;

  void setAttack(float value);
  void setDecay(float value);
  void setSustain(float value);
  void setRelease(float value);
  void setDrawer(ADSRDrawer *drawer);

  /// Pointer to drawer
  ADSRDrawer *drawer;
  /// Called when @see ADSRSlots recieve signal
  void notePlayed(const Note<3> &note);
};

class ADSRSlots : public ADataReceiverSlots {
  Q_OBJECT
public:
  ADSRSlots(QObject *object) : ADataReceiverSlots(object){};
public slots:
  /// Called when synthesizer starts playing note
  void lastNoteReceived(const Note<3> &note) override;
};

#endif // ADSRCONTROLLER_H
