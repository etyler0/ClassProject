#ifndef CIRCLE_H
#define CIRCLE_H
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

class Circle : public Ellipse
{
public:
    Circle(QPaintDevice* device,
           int xId=-1,
           QPen xPen=Qt::NoPen,
           QBrush xBrush=Qt::NoBrush,
           QPoint xOrigin=QPoint(0,0),
           int xR=0):
           Ellipse(device,xId,Shape::shape::Circle,xPen,xBrush,xOrigin,xR,xR){}

    void move(Shape* source)
    {
        this->Ellipse::move(source);
    }

};

#endif // CIRCLE_H
