#include <QPainter>
#include <QTime>
#include <iostream>
#include <math.h>

#include "TextKnob.h"

TextKnob::TextKnob(QQuickItem *parent) : AKnob(parent) {}

TextKnob::~TextKnob() {}

void TextKnob::paint(QPainter *painter) {
  Q_UNUSED(painter);
   /*! TODO: Paint
    *  \todo Paint automatization
    */
}

void TextKnob::postChangedAction() {
  changeableParameter->setValue(valueRange.getCurrent());
  emit valueChanged(valueRange.getCurrent());
  updateValues();
}
