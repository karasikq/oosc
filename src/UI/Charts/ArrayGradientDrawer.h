//===------------------- ArrayGradientDrawer.h -------------------*- C++-*-===//
//===------------ ArrayGradientDrawer class definition --------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ArrayGradientDrawer class, which
/// is used to draw gradient, i.e. shadow.
///
//===----------------------------------------------------------------------===//

#ifndef ARRAYGRADIENTDRAWER_H
#define ARRAYGRADIENTDRAWER_H

#include <QPainter>

/// ArrayGradientDrawer
/// Used for draw gradient
class ArrayGradientDrawer {
public:
  ArrayGradientDrawer();

  enum GradientDirection {
    TopToBottom = 0x01,
    FromCenterHorizontal = 0x02,
    BottomToTop = 0x04,
    LeftToRight = 0x08,
    FromCenterVertical = 0x16,
    RightToLeft = 0x32
  };

  void drawGradient(QPainter *painter,
                    const std::vector<QPointF> &polygon,
                    const QRectF &drawableRect,
                    GradientDirection direction);
  void drawGradient(QPainter *painter,
                    const QRectF &drawableRect,
                    GradientDirection direction);
  /// Sets gradient from QML's array
  void gradientFromQmlStops(const QVariantList &stops);
  /// Sets gradient from stops
  void setGradientStops(const QGradientStops &stops);

private:
  /// Gradient
  QLinearGradient linearGradient;
};

#endif // ARRAYGRADIENTDRAWER_H
