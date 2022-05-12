//===--------------------- CubicBezierCurve.h --------------------*- C++-*-===//
//===------------ CubicBezierCurve class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the CubicBezierCurve class, which
/// is the used for create 3rd order bezier curves.
///
//===----------------------------------------------------------------------===//

#ifndef CUBICBEZIERCURVE_H
#define CUBICBEZIERCURVE_H

#include <QPointF>
#include <math.h>

struct CubicBezierCurve {
public:
  CubicBezierCurve() {}
  CubicBezierCurve(const QPointF &p0,
                   const QPointF &p1,
                   const QPointF &p2,
                   const QPointF &p3);
  /// Points buffer
  std::array<QPointF, 4> points;
  QPointF getPointAt(float position);
  QPointF getPointAt(const QPointF &p0,
                     const QPointF &p1,
                     const QPointF &p2,
                     const QPointF &p3,
                     float position);

private:
  void setPoints(const QPointF &p0,
                 const QPointF &p1,
                 const QPointF &p2,
                 const QPointF &p3);
};

#endif // CUBICBEZIERCURVE_H
