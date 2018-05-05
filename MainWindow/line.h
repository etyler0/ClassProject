#ifndef LINE_H
#define LINE_H
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


// Line class, derived form the shape base class

class Line : public Shape
{
public:
    Line(QPaintDevice* device = nullptr,
         int xId=-1,
         QPen xPen=Qt::NoPen,
         QBrush xBrush=Qt::NoBrush,
         QPoint startPt=QPoint(0,0), // Starting point
         QPoint endPt=QPoint(0,0)):  // Ending point
         Shape(device,xId,
         Shape::shape::Line,xPen,xBrush),
         start(startPt),
         end(endPt){}

    void draw(QPaintDevice* device)
    {
        QPainter& lPaint = getPainter();
        lPaint.begin(device);
        lPaint.setPen(this->getPen());
        lPaint.drawLine(start,end);
        lPaint.setPen(QPen());
        lPaint.drawText(start.x()-5,start.y()-5,QString::number(this->getId()));
        lPaint.end();
    }

    void move(Shape *shapeSource)
    {
        if(this != shapeSource)
        {
            this->start = shapeSource->getStart();
            this->end   = shapeSource->getEnd();
        }
    }

    QPoint getStart()
    {
        return start;
    }

    QPoint getEnd()
    {
        return end;
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
    QPoint start; // Start point
    QPoint end;   // End point
};


#endif // LINE_H
