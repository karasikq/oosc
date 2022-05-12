#include "CubicBezierCurve.h"

CubicBezierCurve::CubicBezierCurve(const QPointF &p0,
                                   const QPointF &p1,
                                   const QPointF &p2,
                                   const QPointF &p3) {
  setPoints(p0, p1, p2, p3);
}

QPointF CubicBezierCurve::getPointAt(float t) {
  float t1 = 1.0f - t;
  return (t1 * t1 * t1) * points[0] + (3.0f * t1 * t1 * t) * points[1] +
         (3.0f * t1 * t * t) * points[2] + (t * t * t) * points[3];
}

QPointF CubicBezierCurve::getPointAt(const QPointF &p0,
                                     const QPointF &p1,
                                     const QPointF &p2,
                                     const QPointF &p3,
                                     float position) {
  setPoints(p0, p1, p2, p3);
  return getPointAt(position);
}

void CubicBezierCurve::setPoints(const QPointF &p0,
                                 const QPointF &p1,
                                 const QPointF &p2,
                                 const QPointF &p3) {
  points[0] = p0;
  points[1] = p1;
  points[2] = p2;
  points[3] = p3;
}
