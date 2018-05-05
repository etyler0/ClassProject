#ifndef SQUARE_H
#define SQUARE_H
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

class Square : public Rectangle
{
public:
    Square(QPaintDevice* device,
           int xId=-1,
           QPen xPen=Qt::NoPen,
           QBrush xBrush=Qt::NoBrush,
           QPoint xUpperLeftPt=QPoint(0,0),
           int side=0):
           Rectangle(device,xId,Shape::shape::Square,xPen,xBrush,xUpperLeftPt,side,side){}

    void move(Shape* source)
    {
        this->Rectangle::move(source);
    }
};

#endif // SQUARE_H
