#include <QPainter>
#include <QTime>
#include <iostream>
#include <math.h>

#include "Knob.h"
#include "src/UI/Controls/AKnob.h"

Knob::Knob(QQuickItem *parent) : AKnob(parent) {
  startAngle = 0;
  endAngle = 180;
  currentAngle = startAngle;
  outerStroke = 2;
  outerColor = QColor(0, 0, 0);
  innerColor = QColor(255, 255, 255);
  pinRadius = 2;

  connect(this, &Knob::startAngleChanged, this, &QQuickItem::update);
  connect(this, &Knob::endAngleChanged, this, &QQuickItem::update);
  connect(this, &Knob::outerStrokeChanged, this, &QQuickItem::update);
  connect(this, &Knob::outerColorChanged, this, &QQuickItem::update);
}

Knob::~Knob() {}

void Knob::paint(QPainter *painter) {
  painter->setRenderHint(QPainter::Antialiasing);

  ringPen.setColor(Qt::black);

  QRectF arcRect = this->boundingRect().adjusted(
      outerStroke, outerStroke, -outerStroke, -outerStroke);
  // Draw outer dial
  ringPen.setWidth(outerStroke);
  ringPen.setColor({"#302c2c"});
  ringPen.setCapStyle(Qt::RoundCap);
  painter->setPen(ringPen);
  float drawStartAngle = -90 - startAngle;
  painter->drawArc(arcRect, drawStartAngle * 16, -(endAngle)*16);

  float str = outerStroke / 2;
  if (automationConnected) {
    ringPen.setWidth(str);
    ringPen.setColor({"#8fb573"});
    painter->setPen(ringPen);
    QRectF arcRect2 = arcRect.adjusted(str + 4, str + 4, -str - 4, -str - 4);
    painter->drawArc(arcRect2, automationAngles.min, automationAngles.max);
  }

  QPen pen(outerColor, outerStroke);
  pen.setCapStyle(Qt::RoundCap);
  painter->setPen(pen);
  float currentAngle4;
  if (automationConnected)
    currentAngle4 = valueRange.percentToMax(endRange.getCurrent()) * endAngle;
  else
    currentAngle4 = valueRange.percentToMax(valueRange.getCurrent()) * endAngle;
  painter->drawArc(arcRect, drawStartAngle * 16, -(currentAngle4)*16);

  // Draw circle
  painter->setPen(Qt::NoPen);
  painter->setBrush(QBrush(innerColor));
  float pinWidth = pinRadius * 2;
  float yOffset = (automationConnected) ? -str - 8 : -6;
  painter->translate(width() / 2, height() / 2);
  painter->rotate(startAngle + currentAngle4);
  painter->drawEllipse(-outerStroke / 2,
                       height() / 2 - outerStroke - pinWidth + yOffset,
                       pinWidth,
                       pinWidth);
}

void Knob::updateAngles() {}

void Knob::postChangedAction() {
  automationAngles.min =
      (-90.0f - startAngle - valueRange.percentToMax(endRange.min) * endAngle) *
      16.0f;
  automationAngles.max = (valueRange.percentToMax(endRange.min) -
                          valueRange.percentToMax(endRange.max)) *
                         endAngle * 16.0f;

  changeableParameter->setValue(valueRange.getCurrent());
  emit valueChanged(valueRange.getCurrent());
  updateValues();
}

void Knob::setMouseWheelDelta(QPoint point) {
  if (automationConnected) {
    float distance = static_cast<float>(point.y()) / 960.f;
    float current = automationRangeLeft.getCurrent();
    automationRangeLeft.setCurrent(current +
                                   distance * automationRangeLeft.difference());
    current = automationRangeRight.getCurrent();
    automationRangeRight.setCurrent(
        current + distance * automationRangeRight.difference());
    changeCurrent(valueRange.getCurrent());
  }
}

int Knob::getStartAngle() { return startAngle; }

float Knob::getEndAngle() { return endAngle; }

float Knob::getOuterStroke() { return outerStroke; }

float Knob::getPinRadius() { return pinRadius; }

QColor Knob::getOuterColor() { return outerColor; }

void Knob::setStartAngle(int angle) {
  startAngle = angle;
  this->updateValues();
  this->update();
}

void Knob::setEndAngle(float angle) {
  endAngle = angle;
  this->updateValues();
  this->update();
}

void Knob::setOuterStroke(float value) {
  outerStroke = value;
  this->update();
}

void Knob::setPinRadius(float value) {
  pinRadius = value;
  this->update();
}

void Knob::setOuterColor(QColor color) {
  outerColor = color;
  this->update();
}
