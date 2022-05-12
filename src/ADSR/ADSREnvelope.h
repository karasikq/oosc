//===-- ADSREnvelope.h - ADSR class definition ---------  -------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ADSREnvelope class, which is
/// used for Attack-Decay-Sustain-Release enveloping with Bezier curves.
///
//===----------------------------------------------------------------------===//

#ifndef ADSRENVELOPE_H
#define ADSRENVELOPE_H

#include "src/Utils/CubicBezierCurve.h"
#include <vector>

/// Attack-Decay-Sustain-Release Envelope class
class ADSREnvelope {
public:
  /// Default constructor, all time properties are zero
  ADSREnvelope();

  /// ADSR constructor, all time properties should be in seconds
  ADSREnvelope(float attackTime,
               float decayTime,
               float releaseTime,
               float initialAmplitude,
               float peakAmplitude,
               float sustainAmplitude);

  /// ADSR constructor, all time properties should be in seconds
  /// @cubicPoints should contains 6 QPointF elements
  ADSREnvelope(float attackTime,
               float decayTime,
               float releaseTime,
               float initialAmplitude,
               float peakAmplitude,
               float sustainAmplitude,
               const std::vector<QPointF> &cubicPoints);

  /// Default destructor
  ~ADSREnvelope() = default;

  /// Envelope state
  enum State { OFF, ATTACK, DECAY, RELEASE };

  /// Returns state of envelope at @time
  State getState(float time);
  /// Returns sustain
  float getSustain();
  /// Returns sustain at [0..1] range, that means percent
  /// from @initialAmplitude to @peakAmplitude
  float getSustainPercent();
  /// Returns attack time in seconds
  float getAttack();
  /// Returns decay time
  float getDecay();
  /// Returns release time
  float getRelease();
  /// Returns absolute attack time in seconds, that means
  /// time from zero to end of attack
  float AbsoluteAttackTime();
  /// Returns absolute decay time in seconds, that means
  /// time from zero to end of decay
  float AbsoluteDecayTime();
  /// Returns absolute release time in seconds, that means
  /// time from zero to end of release
  float AbsoluteReleaseTime();

  /// Set all time properties, and construct Bezier
  /// curves that equal to linear transition
  void setParametrs(float attackTime,
                    float decayTime,
                    float releaseTime,
                    float initialAmplitude,
                    float peakAmplitude,
                    float sustainAmplitude);

  /// Set attack time, @attackTime should be in seconds
  void setAttack(float attackTime);
  /// Set decay time, @decayTime should be in seconds
  void setDecay(float decayTime);
  /// Set release time, @releaseTime should be in seconds
  void setRelease(float releaseTime);
  /// Set initial amplitude
  void setInitialAmplitude(float initialAmplitude);
  /// Set peak amplitude
  void setPeakAmplitude(float peakAmplitude);
  /// Set sustain amplitude
  void setSustain(float sustainPercent);
  /// Set Zero-Attack Bezier point
  /// @index define second or third point of Cubic Bezier curve
  /// @index should be 0(second point) or 1(third point)
  void setZAPoint(const QPointF &zaPoint, int index);
  /// Set Attack-Decay Bezier point
  /// @index define second or third point of Cubic Bezier curve
  /// @index should be 0(second point) or 1(third point)
  void setADPoint(const QPointF &adPoint, int index);
  /// Set Decay-Release Bezier point
  /// @index define second or third point of Cubic Bezier curve
  /// @index should be 0(second point) or 1(third point)
  void setDRPoint(const QPointF &drPoint, int index);

  /// Returns an enveloped amplitude at time
  /// @state stored Envelope state at time
  float Envelope(float time, State &state);
  /// Returns amplitude for end of @state
  float PeakValue(State state);

  /// Returns second Cubic Bezier point for Zero-Attack
  QPointF DefaultZA0Point();
  /// Returns third Cubic Bezier point for Zero-Attack
  QPointF DefaultZA1Point();
  /// Returns second Cubic Bezier point for Attack-Decay
  QPointF DefaultAD0Point();
  /// Returns third Cubic Bezier point for Attack-Decay
  QPointF DefaultAD1Point();
  /// Returns second Cubic Bezier point for Decay-Release
  QPointF DefaultDR0Point();
  /// Returns third Cubic Bezier point for Decay-Release
  QPointF DefaultDR1Point();

private:
  /// Attack time in seconds
  float attackTime;
  /// Decay time in seconds
  float decayTime;
  /// Release time in seconds
  float releaseTime;

  /// Initial amplitude
  float initialAmplitude;
  /// Peak amplitude
  float peakAmplitude;
  /// Sustain amplitude
  float sustain;

  /// Zero-Attack curve
  CubicBezierCurve zaCurve;
  /// Update first and fourth Cubic Beizer points for Zero-Attack
  void UpdateZACurve();
  /// Attack-Decay curve
  CubicBezierCurve adCurve;
  /// Update first and fourth Cubic Beizer points for Attack-Decay
  void UpdateADCurve();
  /// Decay-Release curve
  CubicBezierCurve drCurve;
  /// Update first and fourth Cubic Beizer points for Decay-Release
  void UpdateDRCurve();

  /// Update first and fourth Cubic Beizer points for all
  void UpdateBezierCurves();

  /// Set all time properties, that should be in seconds
  /// @cubicPoints should contains 6 QPointF elements
  void setParametrs(float attackTime,
                    float decayTime,
                    float releaseTime,
                    float initialAmplitude,
                    float peakAmplitude,
                    float sustainAmplitude,
                    const std::vector<QPointF> &cubicPoints);
};

#endif // ADSRENVELOPE_H
