#include "ArrayDrawer.h"
#include "src/UI/Charts/ADataReceiver.h"
#include "src/UI/Charts/ArrayGradientDrawer.h"

#include <cmath>
#include <QQuickPaintedItem>

ArrayDrawer::ArrayDrawer(QQuickItem *parent)
    : QQuickPaintedItem(parent) {
  receiver = std::make_unique<ArrayDrawerSlots>(this);
  gradientDirection =
      ArrayGradientDrawer::GradientDirection::FromCenterHorizontal;
  lineGradient.setColorAt(0.0, QColor(255, 255, 255));
  lineGradient.setColorAt(1.0, QColor(255, 255, 255));
  centerLineColor = QColor(5, 44, 50);
  dataSize = 0;

  valueRange = MinMax<float>(-1.f, 1.f, 0.f);

  drawGradient = true;
  QVector<QGradientStop> stops;
  stops.push_back(
      QPair<qreal, QColor>(1.0, QColor::fromRgb(255, 255, 255, 90)));
  stops.push_back(QPair<qreal, QColor>(0.5, QColor::fromRgb(255, 255, 255, 0)));
  stops.push_back(
      QPair<qreal, QColor>(0.0, QColor::fromRgb(255, 255, 255, 90)));
  gradientDrawer.setGradientStops(stops);

  padding.setX(0.f);
  padding.setY(1.f);

  connect(this, &ArrayDrawer::rawDataChanged, this, &QQuickItem::update);
  connect(this, &ArrayDrawer::lineColorChanged, this, &QQuickItem::update);
  connect(this, &ArrayDrawer::lineGradientChanged, this, &QQuickItem::update);
  connect(
      this, &ArrayDrawer::backgroundColorChanged, this, &QQuickItem::update);
  connect(
      this, &ArrayDrawer::backgroundGradientChanged, this, &QQuickItem::update);
  connect(
      this, &ArrayDrawer::centerLineColorChanged, this, &QQuickItem::update);
}

ArrayDrawer::~ArrayDrawer() {}

void ArrayDrawer::paint(QPainter *painter) {
  painterInitialization(painter);
  drawCenterLine(painter);

  calculateDrawData();

  if (data != nullptr) {
    updatePolylineData();
    drawArrayGradient(painter);
    drawPolyline(painter);
  }
}

void ArrayDrawer::setRawData(const std::vector<float> &data,
                             std::vector<float>::const_iterator from,
                             std::vector<float>::const_iterator to) {
  this->data = &data;
  this->dataStart = from;
  this->dataEnd = to;
  auto dataSizeNew = std::distance(from, to);

  if (dataSize != dataSizeNew) {
    dataSize = dataSizeNew;
    polyline.clear();
    polyline.resize(dataSize + 3);
    for (uint32_t i = 0; i < dataSize + 3; i++) {
      polyline[i] = QPointF(0.f, 0.f);
    }
  }
  this->update();
}

void ArrayDrawer::painterInitialization(QPainter *painter) {
  if (!isVisible()) {
    return;
  }

  rect = this->boundingRect();
  lineGradient.setStart(0.0f, rect.height() / 2);
  lineGradient.setFinalStop(rect.width(), rect.height() / 2);

  painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
  painter->setRenderHint(QPainter::Antialiasing, true);
}

void ArrayDrawer::calculateDrawData() {
  drawableRect.setWidth(rect.width() - padding.x() * 2);
  drawableRect.setHeight(rect.height() - padding.y() * 2);
  partWidth = drawableRect.width() / dataSize;
}

void ArrayDrawer::drawCenterLine(QPainter *painter) {
  linePen = QPen(centerLineColor, 1);
  painter->setPen(linePen);
  painter->drawLine(padding.x(),
                    rect.height() / 2,
                    rect.width() - padding.x(),
                    rect.height() / 2);
}

void ArrayDrawer::updatePolylineData() {
  auto start = dataStart;
  for (unsigned int i = 0; i < dataSize; i++) {
    polyline[i].setX(padding.x() + i * partWidth);
    polyline[i].setY(padding.y() + drawableRect.height() *
                                       valueRange.percentToMin(*(start + i)));
  }

  switch (gradientDirection) {
  case ArrayGradientDrawer::GradientDirection::TopToBottom:
    polyline[dataSize] = QPointF(padding.x() + drawableRect.width(), 0.0f);
    polyline[dataSize + 1] = QPointF(padding.x(), 0.0f);
    polyline[dataSize + 2] = polyline[0];
    break;
  case ArrayGradientDrawer::GradientDirection::FromCenterHorizontal:
    polyline[dataSize] = QPointF(padding.x() + drawableRect.width(),
                                 padding.y() + drawableRect.height() * 0.5f);
    polyline[dataSize + 1] =
        QPointF(padding.x(), padding.y() + drawableRect.height() * 0.5f);
    polyline[dataSize + 2] = polyline[0];
    break;
  case ArrayGradientDrawer::GradientDirection::BottomToTop:
    polyline[dataSize] = QPointF(padding.x() + drawableRect.width(),
                                 padding.y() + drawableRect.height());
    polyline[dataSize + 1] =
        QPointF(padding.x(), padding.y() + drawableRect.height());
    polyline[dataSize + 2] = polyline[0];
    break;
  case ArrayGradientDrawer::LeftToRight:
    break;
  case ArrayGradientDrawer::RightToLeft:
    break;
  case ArrayGradientDrawer::FromCenterVertical:
    break;
  }
}

void ArrayDrawer::drawPolyline(QPainter *painter) {
  linePen = QPen(QBrush(lineGradient), 1.1f);
  linePen.setCapStyle(Qt::RoundCap);
  painter->setPen(linePen);
  painter->drawPolyline(polyline.data(), polyline.size() - 3);
}

void ArrayDrawer::drawArrayGradient(QPainter *painter) {
  if (drawGradient) {
    gradientDrawer.drawGradient(
        painter, polyline, drawableRect, gradientDirection);
  }
}

void ArrayDrawer::setLineColor(QColor lineColor) {
  lineGradient = QLinearGradient();
  this->lineColor = lineColor;
  lineGradient.setColorAt(0.0, lineColor);
  lineGradient.setColorAt(1.0, lineColor);
  emit lineColorChanged();
}

QColor ArrayDrawer::getLineColor() { return lineColor; }

void ArrayDrawer::setLineGradient(const QVariantList &stops) {
  lineGradient = QLinearGradient();
  for (const auto &stop : stops) {
    QMap<QString, QVariant> stopValue = stop.toMap();
    lineGradient.setColorAt(stopValue.value("position").toReal(),
                            QColor(stopValue.value("color").toString()));
  }
  emit lineGradientChanged();
}

void ArrayDrawer::setBackgroundColor(QColor backgroundColor) {
  this->backgroundColor = backgroundColor;
  QVector<QGradientStop> stops;
  int r = backgroundColor.red(), g = backgroundColor.green(),
      b = backgroundColor.blue(), a = backgroundColor.alpha();
  stops.push_back(QPair<qreal, QColor>(1.0, QColor::fromRgb(r, g, b, a)));
  stops.push_back(QPair<qreal, QColor>(0.5, QColor::fromRgb(r, g, b, 0)));
  stops.push_back(QPair<qreal, QColor>(0.0, QColor::fromRgb(r, g, b, a)));
  gradientDrawer.setGradientStops(stops);
  emit backgroundColorChanged();
}

QColor ArrayDrawer::getBackgroundColor() { return backgroundColor; }

void ArrayDrawer::setBackgroundGradient(const QVariantList &stops) {
  gradientDrawer.gradientFromQmlStops(stops);
  emit backgroundGradientChanged();
}

void ArrayDrawer::setCenterLineColor(QColor lineColor) {
  centerLineColor = lineColor;
  emit centerLineColorChanged();
}

QColor ArrayDrawer::getCenterLineColor() { return centerLineColor; }

void ArrayDrawer::setDrawGradient(bool state) { drawGradient = state; }

void ArrayDrawerSlots::dataUpdate(const std::vector<float> &data,
                                  std::vector<float>::const_iterator from,
                                  std::vector<float>::const_iterator to) {
  static_cast<ArrayDrawer *>(object)->setRawData(data, from, to);
}
