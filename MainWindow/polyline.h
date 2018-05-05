#ifndef POLYLINE_H
#define POLYLINE_H
/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device=nullptr,
             int xId = -1,
             QPen xPen = Qt::NoPen,
             QBrush xBrush = Qt::NoBrush,
             const vector<QPoint> &pSource = vector<QPoint>()):
             Shape(device,xId,Shape::shape::Polyline,xPen,xBrush){points = pSource;}

    void draw(QPaintDevice* device)
    {
         QPainter& pPaint = getPainter();
         pPaint.begin(device);
         pPaint.setPen(this->getPen());
         pPaint.drawPolyline(points.begin(),points.size());
         pPaint.setPen(QPen());
         pPaint.drawText(points.begin()->x()-5,points.begin()->y()-5,QString::number(this->getId()));
         pPaint.end();
    }

    vector<QPoint> &getPoints()
    {
        return points;
    }

    void move(Shape* source)
    {
        this->points = source->getPoints();
    }

    double calcPerimeter()
    {
        return 0;
    }

    double calcArea()
    {
        return 0;
    }


private:
    vector<QPoint> points;
};

#endif // POLYLINE_H
