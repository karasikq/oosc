#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QPointF>

struct BezierCurve
{
public:
    QPointF firstPoint;
    QPointF secondPoint;
    QPointF quadraticPoint;
    BezierCurve() { }
    BezierCurve(QPointF _firstPoint, QPointF _secondPoint, QPointF _quadraticPoint);
    QPointF getPointAt(float position);
    QPointF getPointAt(QPointF _firstPoint, QPointF _secondPoint, QPointF _quadraticPoint, float position);
private:
    QPointF getPoint(QPointF &_firstPoint, QPointF &_secondPoint, float position);
    void SetPoints(QPointF &_firstPoint, QPointF &_secondPoint, QPointF &_quadraticPoint);
};

#endif // BEZIERCURVE_H
