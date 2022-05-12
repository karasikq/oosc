#include "ADSRDrawer.h"
#include <iostream>

ADSRDrawer::ADSRDrawer(QQuickItem *parent) : ArrayDrawer(parent) {
  envelope = nullptr;
  setSamplesCount(200);
  valueRange = MinMax<float>(0.0f, 1.0f, 0.f);
  gradientDirection = ArrayGradientDrawer::GradientDirection::BottomToTop;

  QVector<QGradientStop> stops;
  stops.push_back(QPair<qreal, QColor>(1.0, QColor::fromRgb(255, 255, 255, 0)));
  stops.push_back(
      QPair<qreal, QColor>(0.0, QColor::fromRgb(255, 255, 255, 90)));
  gradientDrawer.setGradientStops(stops);
}

ADSRDrawer::~ADSRDrawer() {}

void ADSRDrawer::paint(QPainter *painter) {
  painterInitialization(painter);
  calculateDrawData();

  if (data != nullptr) {
    updatePolylineData();
    drawArrayGradient(painter);
    drawPolyline(painter);
  }
}

void ADSRDrawer::setBackgroundColor(QColor backgroundColor) {
  this->backgroundColor = backgroundColor;
  QVector<QGradientStop> stops;
  int r = backgroundColor.red(), g = backgroundColor.green(),
      b = backgroundColor.blue(), a = backgroundColor.alpha();
  stops.push_back(QPair<qreal, QColor>(1.0, QColor::fromRgb(r, g, b, 0)));
  stops.push_back(QPair<qreal, QColor>(0.0, QColor::fromRgb(r, g, b, a)));
  gradientDrawer.setGradientStops(stops);
  emit backgroundColorChanged();
}

void ADSRDrawer::setEnvelope(ADSREnvelope *env) {
  envelope = env;
  float timeStep = envelope->AbsoluteReleaseTime() / samplesCount;
  for (int i = 0; i < samplesCount; i++) {
    ADSREnvelope::State st;
    envelopeData[i] = envelope->Envelope(timeStep * i, st);
  }
  setRawData(envelopeData, envelopeData.begin(), envelopeData.end());
}

void ADSRDrawer::setSamplesCount(int value) {
  samplesCount = value;
  envelopeData.clear();
  envelopeData.resize(value);
  if (envelope != nullptr) {
    setEnvelope(envelope);
  } else {
    setRawData(envelopeData, envelopeData.begin(), envelopeData.end());
  }
}

void ADSRDrawer::envelopeChanges() {
  setEnvelope(envelope);
  update();
}

int ADSRDrawer::getSamplesCount() { return samplesCount; }
