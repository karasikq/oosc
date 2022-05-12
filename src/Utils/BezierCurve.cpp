#include "BezierCurve.h"

BezierCurve::BezierCurve(QPointF _firstPoint,
                         QPointF _secondPoint,
                         QPointF _quadraticPoint) {
  SetPoints(_firstPoint, _secondPoint, _quadraticPoint);
}

QPointF BezierCurve::getPointAt(float position) {
  QPointF Q0 = getPoint(firstPoint, quadraticPoint, position);
  QPointF Q1 = getPoint(quadraticPoint, secondPoint, position);
  return getPoint(Q0, Q1, position);
}

QPointF BezierCurve::getPointAt(QPointF _firstPoint,
                                QPointF _secondPoint,
                                QPointF _quadraticPoint,
                                float position) {
  SetPoints(_firstPoint, _secondPoint, _quadraticPoint);
  return getPointAt(position);
}

QPointF BezierCurve::getPoint(QPointF &_firstPoint,
                              QPointF &_secondPoint,
                              float position) {
  QPointF difference = _secondPoint - _firstPoint;
  return _firstPoint + (difference * position);
}

void BezierCurve::SetPoints(QPointF &_firstPoint,
                            QPointF &_secondPoint,
                            QPointF &_quadraticPoint) {
  firstPoint = _firstPoint;
  secondPoint = _secondPoint;
  quadraticPoint = _quadraticPoint;
}
