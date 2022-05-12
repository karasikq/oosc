//===-------------------------- AKnob.h --------------------------*- C++-*-===//
//===------------------- AKnob class definition ---------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AKnob class, which
/// is the base class for user controls.
///
//===----------------------------------------------------------------------===//

#ifndef AKNOB_H
#define AKNOB_H

#include "src/Parametrs/AValueSender.h"
#include "src/Parametrs/ChangeableParameter.h"
#include "src/UI/SynthesizerControls/LfoController.h"
#include "src/Utils/MinMax.h"

/// Knob Interpolation class
/// Class used for define enum as meta object
class KnobInterpolation : public QObject {
  Q_OBJECT
public:
  KnobInterpolation() : QObject() {}

  enum KnobInterpolationMethod { Linear, Exponential };
  Q_ENUM(KnobInterpolationMethod)
};

/// Knob Direction class
/// Class used for define enum as meta object
class KnobDirection : public QObject {
  Q_OBJECT
public:
  KnobDirection() : QObject() {}

  enum KnobDirectionMethod { Vertical, Horizontal };
  Q_ENUM(KnobDirectionMethod)
};

/// AKnob class
/// Base class for user controls
class AKnob : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(float currentValue READ getCurrentValue NOTIFY valueChanged)
  Q_PROPERTY(QPoint mousePosition READ getMousePosition WRITE setMousePosition)
  Q_PROPERTY(bool trackMouse READ getTrackMouse WRITE setMouseTrack NOTIFY
                 mouseTrackChanged)
  Q_PROPERTY(QPoint startMousePosition READ getStartMousePosition WRITE
                 setStartMousePosition NOTIFY startMousePositionChanged)
  Q_PROPERTY(
      KnobInterpolation::KnobInterpolationMethod interpolation READ
          getInterpolation WRITE setInterpolation NOTIFY interpolationChanged)
  Q_PROPERTY(KnobDirection::KnobDirectionMethod direction READ getDirection
                 WRITE setDirection NOTIFY directionChanged)
  Q_PROPERTY(
      IChangeableParameter *changeableParametr WRITE setChangeableParametr)
public:
  AKnob(QQuickItem *parent = 0);
  virtual ~AKnob();

  /// Sets @param value to connected changeableParametr
  Q_INVOKABLE void changeParametr(QVariant value) {
    changeableParameter->setValue(value);
  }
  /// Connects @param sender to changeableParametr, known as automatization
  Q_INVOKABLE void connectValueSender(AValueSender *sender);
  /// Disconects sender, cancels automatization
  Q_INVOKABLE void disconnectSender();
  /// Returns current value
  inline float getCurrentValue() { return valueRange.getCurrent(); }
  QPoint getMousePosition() { return mousePosition; }
  QPoint getStartMousePosition() { return startMousePosition; }
  bool getTrackMouse() { return trackMouse; }
  inline KnobInterpolation::KnobInterpolationMethod getInterpolation() {
    return interpolation;
  }
  inline KnobDirection::KnobDirectionMethod getDirection() { return direction; }

  /// Sets changeable parametr, a necessary condition for knob work
  Q_INVOKABLE void setChangeableParametr(IChangeableParameter *parametr);
  /// Sets mouse position then change changeableParametr
  void setMousePosition(QPoint point) { mousePosition = point; }
  /// If @param state is true knob controlled by mouse
  void setMouseTrack(bool state) { trackMouse = state; }
  /// Sets start mouse position then calculate difference & change
  /// changeableParametr
  void setStartMousePosition(QPoint point) {
    startMousePosition = point;
    this->update();
  }
  void setInterpolation(KnobInterpolation::KnobInterpolationMethod method) {
    interpolation = method;
    emit interpolationChanged();
  }
  void setDirection(KnobDirection::KnobDirectionMethod method) {
    direction = method;
    emit directionChanged();
  }

public slots:
  void mouseMove();
  void trackMouseState(bool state);
  void updateChangeableParameter();
  void updateAutomation(float value);
signals:
  void valueChanged(float value);
  void mousePositionChanged();
  void startMousePositionChanged();
  void mouseTrackChanged(bool value);
  void mouseStartPositionChanged();
  void interpolationChanged();
  void directionChanged();

protected:
  /// Associated changebleParametr
  IChangeableParameter *changeableParameter = nullptr;
  /// Range of changeableParametr value
  MinMax<float> valueRange;
  /// Changes changeableParametr current value
  void changeCurrent(float value);
  KnobInterpolation::KnobInterpolationMethod interpolation;
  KnobDirection::KnobDirectionMethod direction;
  /// Returns exponential value of x E [0, 1]
  inline static float exponentialGrowth(float value, float coef = 1000.0f) {
    return (powf(coef, value) - 1.0f) / (coef - 1.0f);
  }
  /// Range of coefficients, used for diffetent response when user change value
  MinMax<float> coefRange = {5.0f, 50.0f, 50.f};

  /// Automated parameter, associated with @see changeAutomatedCurrent
  ChangeableParameter<float> automatedParameter;
  /// Left range for automatization
  MinMax<float> automationRangeLeft;
  /// Right range for automatization
  MinMax<float> automationRangeRight;
  /// From min automated value to max
  MinMax<float> endRange;
  /// Sets current for @see automatedParameter
  void changeAutomatedCurrent(float value);
  /// True if knob automatized
  bool automationConnected;

  QPoint mousePosition;
  QPoint startMousePosition;
  bool trackMouse;

  /// Called after value ranges calculated
  virtual void postChangedAction();
  void updateValues();
};
#endif // Knob_H
