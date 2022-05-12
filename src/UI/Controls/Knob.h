//===--------------------------- Knob.h --------------------------*- C++-*-===//
//===-------------------- Knob class definition ---------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Knob class, which
/// is used to draw circular mouse-contolled knob.
///
//===----------------------------------------------------------------------===//

#ifndef KNOB_H
#define KNOB_H

#include <QQuickPaintedItem>

#include "AKnob.h"
#include "src/Parametrs/ChangeableParameter.h"
#include "src/UI/SynthesizerControls/LfoController.h"
#include "src/Utils/MinMax.h"

/// Knob class
/// Draws circular mouse-contolled knob
class Knob : public AKnob {
  Q_OBJECT
  Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle NOTIFY
                 startAngleChanged)
  Q_PROPERTY(
      float endAngle READ getEndAngle WRITE setEndAngle NOTIFY endAngleChanged)
  Q_PROPERTY(float outerStroke READ getOuterStroke WRITE setOuterStroke NOTIFY
                 outerStrokeChanged)
  Q_PROPERTY(float pinRadius READ getPinRadius WRITE setPinRadius NOTIFY
                 pinRadiusChanged)
  Q_PROPERTY(QColor outerColor READ getOuterColor WRITE setOuterColor NOTIFY
                 outerColorChanged)
  Q_PROPERTY(QPoint mouseWheelDelta WRITE setMouseWheelDelta)
public:
  Knob(QQuickItem *parent = 0);
  ~Knob();
  /// Draws circular knob and automatization arc
  void paint(QPainter *painter) override;

  /// Returns angle from which knob's arc starts draw
  int getStartAngle();
  /// Returns length of arc in degrees
  float getEndAngle();
  /// Width of the arc stroke
  float getOuterStroke();
  /// Returns circle indicator radius
  float getPinRadius();
  /// Returns color of arc
  QColor getOuterColor();

  void setStartAngle(int angle);
  void setEndAngle(float angle);
  void setOuterStroke(float value);
  void setPinRadius(float value);
  void setOuterColor(QColor color);
  void setMouseWheelDelta(QPoint point);

public slots:
  void updateAngles();
signals:
  void startAngleChanged();
  void endAngleChanged();
  void dialWidthChanged();
  void outerColorChanged();
  void outerStrokeChanged();
  void pinRadiusChanged();

private:
  /// Angles of automatization range
  MinMax<float> automationAngles;
  /// Angle from which knob's arc starts draw
  int startAngle;
  /// Length of arc in degrees
  float endAngle;
  /// Angle of current value
  float currentAngle;

  QPen ringPen;
  /// Automatization color
  QColor innerColor;
  /// Width of the arc stroke
  float outerStroke;
  /// Circle indicator radius
  float pinRadius;
  /// Color of arc
  QColor outerColor;

  /// Called after value ranges calculated
  void postChangedAction() override;
};
#endif // KNOB_H
