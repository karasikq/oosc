#include "ArrayGradientDrawer.h"
#include <qvariant.h>

ArrayGradientDrawer::ArrayGradientDrawer() {}

void ArrayGradientDrawer::drawGradient(QPainter *painter,
                                       const std::vector<QPointF> &polygon,
                                       const QRectF &drawableRect,
                                       GradientDirection direction) {
  if (direction < GradientDirection::LeftToRight) {
    linearGradient.setStart(0.0, 0.0);
    linearGradient.setFinalStop(0.0, drawableRect.height());
  } else {
    linearGradient.setStart(0.0, 0.0);
    linearGradient.setFinalStop(drawableRect.width(), 0.0);
  }

  painter->setPen(QPen(Qt::NoPen));
  painter->setBrush(QBrush(linearGradient));
  painter->drawPolygon(polygon.data(), polygon.size());
}

void ArrayGradientDrawer::drawGradient(QPainter *painter,
                                       const QRectF &drawableRect,
                                       GradientDirection direction) {
  if (direction < GradientDirection::LeftToRight) {
    linearGradient.setStart(0.0, 0.0);
    linearGradient.setFinalStop(0.0, drawableRect.height());
  } else {
    linearGradient.setStart(0.0, 0.0);
    linearGradient.setFinalStop(drawableRect.width(), 0.0);
  }

  painter->setPen(QPen(Qt::NoPen));
  painter->setBrush(QBrush(linearGradient));
  painter->drawRect(drawableRect);
}

void ArrayGradientDrawer::setGradientStops(const QGradientStops &stops) {
  linearGradient.setStops(stops);
}

void ArrayGradientDrawer::gradientFromQmlStops(const QVariantList &stops) {
  QVector<QGradientStop> grStops;
  for (const auto &stop : stops) {
    QMap<QString, QVariant> stopValue = stop.toMap();
    grStops.push_back(
        QPair<qreal, QColor>(stopValue.value("position").toReal(),
                             QColor(stopValue.value("color").toString())));
  }
  setGradientStops(grStops);
}
