#include "LinearIndicator.h"
#include <iostream>

LinearIndicator::LinearIndicator(QQuickItem *parent)
    : QQuickPaintedItem(parent) {
  gradientDirection =
      ArrayGradientDrawer::GradientDirection::FromCenterHorizontal;
  direction = LinearDirection::Vertical;

  valueRange = MinMax<float>(-1.f, 1.f, 0.f);
  inputRange = {
      valueRange.min - valueRange.max, valueRange.min - valueRange.max, 0.0f};
  polyline.insert(polyline.begin(), 4, {0.f, 0.f});

  setForegroundColor({255, 255, 255});
  setBackgroundColor({255, 255, 255});

  connect(this, &LinearIndicator::rawDataChanged, this, &QQuickItem::update);
  connect(this,
          &LinearIndicator::backgroundColorChanged,
          this,
          &QQuickItem::update);
  connect(this,
          &LinearIndicator::backgroundGradientChanged,
          this,
          &QQuickItem::update);
}

LinearIndicator::~LinearIndicator() {}

void LinearIndicator::paint(QPainter *painter) {
  painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
  painter->setRenderHint(QPainter::Antialiasing, true);
  rect = this->boundingRect();

  backgroundGradient.drawGradient(painter, rect, gradientDirection);

  float maxPercent = valueRange.percentToMax(inputRange.max);
  float minPercent = valueRange.percentToMin(inputRange.min);

  switch (direction) {
  case LinearDirection::Direction::Vertical:
    polyline[0] = {0.0f, rect.height() * (1.0f - maxPercent)};
    polyline[1] = {rect.width(), rect.height() * (1.0f - maxPercent)};
    polyline[2] = {rect.width(), rect.height() * minPercent};
    polyline[3] = {0.0f, rect.height() * minPercent};
    break;
  case LinearDirection::Direction::Horizontal:
    polyline[0] = {rect.width() * (1.0f - maxPercent), 0.0f};
    polyline[1] = {rect.width() * (1.0f - maxPercent), rect.height()};
    polyline[2] = {rect.width() * minPercent, rect.height()};
    polyline[3] = {rect.width() * minPercent, 0.0f};
    break;
  }

  foregroundGradient.drawGradient(painter, polyline, rect, gradientDirection);
}

void LinearIndicator::dataUpdate(MinMax<float> range) {
  inputRange = range;
  this->update();
}

void LinearIndicator::setBackgroundColor(QColor color) {
  this->backgroundColor = color;
  QVector<QGradientStop> stops;
  stops.push_back(QPair<qreal, QColor>(1.0, color));
  stops.push_back(QPair<qreal, QColor>(0.0, color));
  backgroundGradient.setGradientStops(stops);
  emit backgroundColorChanged();
}

void LinearIndicator::setForegroundColor(QColor color) {
  this->foregroundColor = color;
  QVector<QGradientStop> stops;
  stops.push_back(QPair<qreal, QColor>(1.0, color));
  stops.push_back(QPair<qreal, QColor>(0.0, color));
  foregroundGradient.setGradientStops(stops);
  emit foregroundColorChanged();
}

QColor LinearIndicator::getForegroundColor() { return foregroundColor; }

QColor LinearIndicator::getBackgroundColor() { return backgroundColor; }

void LinearIndicator::setBackgroundGradient(const QVariantList &stops) {
  backgroundGradient.gradientFromQmlStops(stops);
  emit backgroundGradientChanged();
}

void LinearIndicator::setForegroundGradient(const QVariantList &stops) {
  foregroundGradient.gradientFromQmlStops(stops);
  emit foregroundGradientChanged();
}
