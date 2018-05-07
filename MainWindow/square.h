#ifndef SQUARE_H
#define SQUARE_H
/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>

#include "shape.h"
#include "shape2d.h"
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane


class Square : public Shape2D
{
private:
    Square() {}; // Default constructor - never used - all fields must be explictly set
    
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Square(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             QColor             xBrushColor,
             Qt::BrushStyle     xBrushStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xSide)
       : Shape2D(device, xId, shapeType::Square,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                      xBrushColor, xBrushStyle)
    {
        // object specific transform from points supplied to bounding points
        QPoint ul(xTopLeftX,xTopLeftY);
        upperleft = ul;
        QPoint lr(xTopLeftX+xSide, xTopLeftY+xSide);
        lowerright = lr;
    }
    
    ~Square() {};

    // draw() function from shape base class
    void draw(QPaintDevice* device)
    {
        QRect rect1(upperleft, lowerright);
        QPainter& paint = get_qPainter();
        paint.begin(device);
        paint.setPen(pen);
        paint.setBrush(brush);
        paint.drawRect(rect1);
        paint.setPen(QPen());
        paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
        paint.end();
    }

    // move() function from shape base class
    void move(Shape* source)
    {
        //this->setUpperLeft(source->getUpperLeft());
        //this->setWidth(source->getWidth());
        //this->setHeight(source->getHeight());
    }

    void update(void)
    {
        draw((get_qPaintDevice()));
        return;
    }

    // calcPerimeter() function from shape base class
    double calcPerimeter()
    {
        return 0; //((getWidth()*2)+(getHeight()*2));
    }

    // calcArea() function from shape base class
    double calcArea()
    {
        return 0;//(getWidth()*getHeight());
    }

};
#endif // SQUARE_H
