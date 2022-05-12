#include "PolarVectorscope.h"
#include <memory>

PolarVectorscope::PolarVectorscope() {
  receiver = std::make_unique<VectroscopeDrawerSlots>(this);
  channel = nullptr;
}

PolarVectorscope::~PolarVectorscope() = default;

void PolarVectorscope::paint(QPainter *painter) {
  if (channel == nullptr) {
    return;
  }
  if (!isVisible()) {
    return;
  }

  QPen mp = QPen(QColor(64, 64, 64));
  mp.setWidth(1);
  painter->setPen(mp);
  QRectF rect = this->boundingRect().adjusted(1.1f, 1.1f, -1.1f, -1.1f);
  QRectF visualRect = rect.adjusted(15.0f, 15.0f, -15.0f, -15.0f);
  painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
  painter->setRenderHint(QPainter::Antialiasing, true);

  MinMax<float> audioRange = MinMax<float>(0, 1.4142135623731f, 0.0f);
  QPointF centerPoint =
      QPointF(1.1f + rect.width() / 2, 1.1f + rect.height() / 2);

  mp.setWidthF(1.1f);
  painter->setPen(mp);
  painter->drawEllipse(visualRect);
  mp.setStyle(Qt::DotLine);
  painter->setPen(mp);
  QPointF arcPoint0(0.707106781 * visualRect.width() / 2,
                    0.707106781 * visualRect.height() / 2);
  painter->drawLine(centerPoint, centerPoint - arcPoint0);
  painter->drawLine(centerPoint,
                    centerPoint -
                        QPointF(-0.707106781 * visualRect.width() / 2,
                                0.707106781 * visualRect.height() / 2));
  painter->drawLine(centerPoint, centerPoint + arcPoint0);
  painter->drawLine(centerPoint,
                    centerPoint +
                        QPointF(-0.707106781 * visualRect.width() / 2,
                                0.707106781 * visualRect.height() / 2));

  mp.setWidth(1);
  painter->setPen(mp);
  mp.setColor(QColor("#de5d68"));
  mp.setStyle(Qt::SolidLine);
  painter->setPen(mp);
  for (unsigned int i = 0; i < channel->getSamplesPerChannel(); i++) {
    float leftIn = channel->getChannelBuffer(0)->at(i);
    float rightIn = channel->getChannelBuffer(1)->at(i);
    float radius = sqrt(leftIn * leftIn + rightIn * rightIn);
    float angle = atan2(rightIn, leftIn) + M_PI_4;

    QPointF samplePoint =
        QPointF(1.1f + audioRange.percentToMax(radius * cos(angle)) *
                           visualRect.width() / 2,
                1.1f + audioRange.percentToMax(radius * sin(angle)) *
                           visualRect.height() / 2);
    samplePoint = centerPoint - samplePoint;
    polyline[i] = samplePoint;
  }
  painter->drawPolyline(polyline.data(), polyline.size());
}

void PolarVectorscope::drawVectorscope(AudioChannel *channel) {
  this->channel = channel;
  if (polyline.size() != channel->getSamplesPerChannel()) {
    polyline.clear();
    polyline.resize(channel->getSamplesPerChannel());
  }
  this->update();
}

void VectroscopeDrawerSlots::dataUpdateChannel(AudioChannel *channel) {
  static_cast<PolarVectorscope *>(object)->drawVectorscope(channel);
}
