/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

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

 /*************************************************************************************************************
  * Rectangle Base Class (Inherits from Shape2D.h)
  *
  * Basic 2D drawing example link - http://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html
  *************************************************************************************************************/


class Rectangle : public Shape2D
{
private:
    Rectangle() {}; // Default constructor - never used - all fields must be explictly set
    
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Rectangle(QPaintDevice* device,
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
             int                xWidth,
             int                xHeight)
       : Shape2D(device, xId, shapeType::Rectangle,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                      xBrushColor, xBrushStyle)
    {
        // object specific transform from points supplied to bounding points
        QPoint ul(xTopLeftX,xTopLeftY);
        upperleft = ul;
        QPoint lr(xTopLeftX+xWidth, xTopLeftY+xHeight);
        lowerright = lr;
    }
    
    ~Rectangle() {};

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
    void move(QPoint &newUpperLeft)
    {
        int deltaX = (newUpperLeft.x() - upperleft.x());
        int deltaY = (newUpperLeft.y() - upperleft.y());

        upperleft = newUpperLeft;
        lowerright.setX(lowerright.x() + deltaX);
        lowerright.setY(lowerright.y() + deltaY);
    }

    void update(void)
    {
        draw((get_qPaintDevice()));
        return;
    }

    // calcPerimeter() function from shape base class
    double calcPerimeter()
    {
        return ( ((upperleft.x()-lowerright.x()) * 2) + ((upperleft.y()-lowerright.y()) * 2));
    }

    // calcArea() function from shape base class
    double calcArea()
    {
        return ( (upperleft.x()-lowerright.x()) * (upperleft.y()-lowerright.y()));
    }

};

#endif // RECTANGLE_H
