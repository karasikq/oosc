//===------------------------- TextKnob.h ------------------------*- C++-*-===//
//===------------------ TextKnob class definition -------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the TextKnob class, which
/// is used to create vertical controlled knob. Text is drawn in QML.
///
//===----------------------------------------------------------------------===//

#ifndef TEXTKNOB_H
#define TEXTKNOB_H

#include <QPen>
#include <QQuickPaintedItem>

#include "AKnob.h"

/// TextKnob class
/// Creates vertical controlled knob. Text is drawn in QML, not here
class TextKnob : public AKnob {
  Q_OBJECT
public:
  TextKnob(QQuickItem *parent = 0);
  ~TextKnob();
  void paint(QPainter *painter) override;

private:
  void postChangedAction() override;
};
#endif // TEXTKNOB_H
