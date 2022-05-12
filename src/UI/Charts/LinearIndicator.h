//===--------------------- LinearIndicator.h ---------------------*- C++-*-===//
//===-------------- LinearIndicator class definition ----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the LinearIndicator class, which
/// is used to indicate current value in range.
///
//===----------------------------------------------------------------------===//

#ifndef LINEARINDICATOR_H
#define LINEARINDICATOR_H

#include <QQuickPaintedItem>
#include <vector>

#include "src/Utils/MinMax.h"
#include "ArrayGradientDrawer.h"

/// Linear Direction class
/// Class used for define enum as meta object 
class LinearDirection : public QObject {
  Q_OBJECT;
public:
  LinearDirection() : QObject() {}

  /// Define indicator diretion
  enum Direction { Vertical, Horizontal };
  Q_ENUM(Direction)
};

/// Linear Indicator class
class LinearIndicator : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(QColor foregroundColor READ getForegroundColor WRITE
                 setForegroundColor NOTIFY foregroundColorChanged)
  Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE
                 setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(QVariantList foregroundGradient WRITE setForegroundGradient NOTIFY
                 foregroundGradientChanged)
  Q_PROPERTY(QVariantList backgroundGradient WRITE setBackgroundGradient NOTIFY
                 backgroundGradientChanged)
public:
  LinearIndicator(QQuickItem *parent = 0);
  ~LinearIndicator();
  virtual void paint(QPainter *painter);
  /// Sets foreground color, i.e. line color
  virtual void setForegroundColor(QColor color);
  /// Sets background color
  virtual void setBackgroundColor(QColor color);
  /// Sets foreground gradient, i.e. gradient for indicator line
  virtual void setForegroundGradient(const QVariantList &gradient);
  /// Sets background gradient
  virtual void setBackgroundGradient(const QVariantList &gradient);

  QColor getForegroundColor();
  QColor getBackgroundColor();
  ArrayGradientDrawer::GradientDirection gradientDirection;
signals:
  void foregroundColorChanged();
  void backgroundColorChanged();
  void foregroundGradientChanged();
  void backgroundGradientChanged();
  void rawDataChanged();
public slots:
  /// Receive input and update
  void dataUpdate(MinMax<float> range);

protected:
  /// Define range of input value
  MinMax<float> valueRange;
  /// Input value
  MinMax<float> inputRange;
  /// Indicator direction
  LinearDirection::Direction direction;

  /// Contains rectangle points
  std::vector<QPointF> polyline;

  /// Painter rectangle
  QRectF rect;

  QColor foregroundColor;
  QColor backgroundColor;
  ArrayGradientDrawer backgroundGradient;
  ArrayGradientDrawer foregroundGradient;
  QPen linePen;
};

#endif // LINEARINDICATOR_H
