#include "ADSREnvelope.h"
#include <QDebug>
#include <iostream>

ADSREnvelope::ADSREnvelope() { setParametrs(0.0, 0.0, 0.0, 0.0, 0.0, 0.0); }

ADSREnvelope::ADSREnvelope(float attackTime,
                           float decayTime,
                           float releaseTime,
                           float initialAmplitude,
                           float peakAmplitude,
                           float sustain) {
  setParametrs(attackTime,
               decayTime,
               releaseTime,
               initialAmplitude,
               peakAmplitude,
               sustain);
}

ADSREnvelope::ADSREnvelope(float attackTime,
                           float decayTime,
                           float releaseTime,
                           float initialAmplitude,
                           float peakAmplitude,
                           float sustain,
                           const std::vector<QPointF> &cubicPoints) {
  setParametrs(attackTime,
               decayTime,
               releaseTime,
               initialAmplitude,
               peakAmplitude,
               sustain,
               cubicPoints);
}

void ADSREnvelope::setParametrs(float attackTime,
                                float decayTime,
                                float releaseTime,
                                float initialAmplitude,
                                float peakAmplitude,
                                float sustain) {
  this->attackTime = attackTime;
  this->decayTime = decayTime;
  this->releaseTime = releaseTime;
  this->initialAmplitude = initialAmplitude;
  this->peakAmplitude = peakAmplitude;
  this->sustain = sustain;
  setZAPoint(DefaultZA0Point(), 0);
  setZAPoint(DefaultZA1Point(), 1);
  setADPoint(DefaultAD0Point(), 0);
  setADPoint(DefaultAD1Point(), 1);
  setDRPoint(DefaultDR0Point(), 0);
  setDRPoint(DefaultDR1Point(), 1);
  this->UpdateBezierCurves();
}

void ADSREnvelope::setParametrs(float attackTime,
                                float decayTime,
                                float releaseTime,
                                float initialAmplitude,
                                float peakAmplitude,
                                float sustain,
                                const std::vector<QPointF> &cubicPoints) {
  this->attackTime = attackTime;
  this->decayTime = decayTime;
  this->releaseTime = releaseTime;
  this->initialAmplitude = initialAmplitude;
  this->peakAmplitude = peakAmplitude;
  this->sustain = sustain;
  setZAPoint(cubicPoints[0], 0);
  setZAPoint(cubicPoints[1], 1);
  setADPoint(cubicPoints[2], 0);
  setADPoint(cubicPoints[3], 1);
  setDRPoint(cubicPoints[4], 0);
  setDRPoint(cubicPoints[5], 1);
  UpdateBezierCurves();
}

float ADSREnvelope::getSustain() {
  return initialAmplitude + sustain * (peakAmplitude - initialAmplitude);
}

float ADSREnvelope::getSustainPercent() { return sustain; }

float ADSREnvelope::getAttack() { return attackTime; }

float ADSREnvelope::AbsoluteAttackTime() { return attackTime; }

float ADSREnvelope::AbsoluteDecayTime() { return attackTime + decayTime; }

float ADSREnvelope::AbsoluteReleaseTime() {
  return attackTime + decayTime + releaseTime;
}

float ADSREnvelope::getDecay() { return decayTime; }

float ADSREnvelope::getRelease() { return releaseTime; }

ADSREnvelope::State ADSREnvelope::getState(float time) {
  if (time < AbsoluteAttackTime())
    return State::ATTACK;
  else if (time < AbsoluteDecayTime())
    return State::DECAY;
  else if (time < AbsoluteReleaseTime())
    return State::RELEASE;
  else
    return State::OFF;
}

float ADSREnvelope::Envelope(float time, State &state) {
  state = getState(time);

  switch (state) {
  case State::ATTACK:
    if (time < attackTime) {
      return zaCurve.getPointAt(time / attackTime).y();
    }
    break;
  case State::DECAY:
    if (time - attackTime < decayTime) {
      return adCurve.getPointAt((time - attackTime) / decayTime).y();
    }
    break;
  case State::RELEASE:
    if (time - attackTime - decayTime < releaseTime) {
      return drCurve.getPointAt((time - attackTime - decayTime) / releaseTime)
          .y();
    }
    break;
  case State::OFF:
    return initialAmplitude;
    break;
  }
  return 0;
}

float ADSREnvelope::PeakValue(State state) {
  switch (state) {
  case State::ATTACK:
    return peakAmplitude;
    break;
  case State::DECAY:
    return getSustain();
    break;
  case State::RELEASE:
    return initialAmplitude;
    break;
  case State::OFF:
    return initialAmplitude;
    break;
  }
  return 0;
}

void ADSREnvelope::setAttack(float attackTime) {
  this->attackTime = attackTime;
  UpdateBezierCurves();
}

void ADSREnvelope::setDecay(float decayTime) {
  this->decayTime = decayTime;
  UpdateBezierCurves();
}

void ADSREnvelope::setSustain(float sustainPercent) {
  this->sustain = sustainPercent;
  UpdateBezierCurves();
}

void ADSREnvelope::setRelease(float releaseTime) {
  this->releaseTime = releaseTime;
  UpdateBezierCurves();
}

void ADSREnvelope::setInitialAmplitude(float initialAmplitude) {
  this->initialAmplitude = initialAmplitude;
  UpdateBezierCurves();
}

void ADSREnvelope::setPeakAmplitude(float peakAmplitude) {
  this->peakAmplitude = peakAmplitude;
  UpdateBezierCurves();
}

void ADSREnvelope::setZAPoint(const QPointF &zaQuadraticPoint, int index) {
  this->zaCurve.points[1 + index] = zaQuadraticPoint;
}

void ADSREnvelope::setADPoint(const QPointF &adQuadraticPoint, int index) {
  this->adCurve.points[1 + index] = adQuadraticPoint;
}

void ADSREnvelope::setDRPoint(const QPointF &drQuadraticPoint, int index) {
  this->drCurve.points[1 + index] = drQuadraticPoint;
}

void ADSREnvelope::UpdateZACurve() {
  zaCurve.points[0] = QPointF(0.0, initialAmplitude);
  zaCurve.points[3] = QPointF(attackTime, peakAmplitude);
}

void ADSREnvelope::UpdateADCurve() {
  adCurve.points[0] = QPointF(attackTime, peakAmplitude);
  adCurve.points[3] = QPointF(AbsoluteDecayTime(), getSustain());
}

void ADSREnvelope::UpdateDRCurve() {
  drCurve.points[0] = QPointF(AbsoluteDecayTime(), getSustain());
  drCurve.points[3] = QPointF(AbsoluteReleaseTime(), initialAmplitude);
}

void ADSREnvelope::UpdateBezierCurves() {
  UpdateZACurve();
  UpdateADCurve();
  UpdateDRCurve();
}

QPointF ADSREnvelope::DefaultZA0Point() {
  return QPointF(attackTime * 0.333f,
                 initialAmplitude +
                     0.333f * (peakAmplitude - initialAmplitude));
}

QPointF ADSREnvelope::DefaultZA1Point() {
  return QPointF(attackTime * 0.666f,
                 initialAmplitude +
                     0.666f * (peakAmplitude - initialAmplitude));
}

QPointF ADSREnvelope::DefaultAD0Point() {
  return QPointF(attackTime,
                 0.666f * peakAmplitude +
                     0.333f * sustain * (peakAmplitude - initialAmplitude));
}

QPointF ADSREnvelope::DefaultAD1Point() {
  return QPointF(attackTime + decayTime * 0.666f,
                 0.333f * peakAmplitude +
                     0.666f * sustain * (peakAmplitude - initialAmplitude));
}

QPointF ADSREnvelope::DefaultDR0Point() {
  return QPointF(attackTime + decayTime + releaseTime * 0.333f,
                 initialAmplitude +
                     0.666f * sustain * (peakAmplitude - initialAmplitude));
}

QPointF ADSREnvelope::DefaultDR1Point() {
  return QPointF(attackTime + decayTime + releaseTime * 0.666f,
                 initialAmplitude +
                     0.333f * sustain * (peakAmplitude - initialAmplitude));
}
