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
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

// Custom libraries/directives
//!!!!    Custom vector class goes here   !!!!


 /*************************************************************************************************************
  * Rectangle Base Class (Inherits from Shape.h)
  *
  * Basic 2D drawing example link - http://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html
  *************************************************************************************************************/


class Rectangle : public Shape
{
public:
    // Default constructor
    Rectangle(QPaintDevice* device,
              int xId = -1,
              shape sRec = shape::Rectangle,
              QPen xPen = Qt::NoPen,
              QBrush xBrush = Qt::NoBrush,
              QPoint xUL = QPoint(0,0),
              int xWidth = 0,int xheight = 0):
              Shape(device, xId, sRec, xPen, xBrush), upperLeft(xUL), width(xWidth), height(xheight){}

    // draw() function from shape base class
    void draw(QPaintDevice* device)
    {
        QPainter& paint = getPainter();
        paint.begin(device);
        paint.setPen(this->getPen());
        paint.setBrush(this->getBrush());
        paint.drawRect((getUpperLeft()).x(),(getUpperLeft()).y(),getWidth(),getHeight());
        paint.setPen(QPen());
        paint.drawText(getUpperLeft().x()-5,getUpperLeft().y()-5,QString::number(this->getId()));
        paint.end();
    }

    // move() function from shape base class
    void move(Shape* source)
    {
        this->setUpperLeft(source->getUpperLeft());
        this->setWidth(source->getWidth());
        this->setHeight(source->getHeight());
    }

    // calcPerimeter() function from shape base class
    double calcPerimeter()
    {
        return ((getWidth()*2)+(getHeight()*2));
    }

    // calcArea() function from shape base class
    double calcArea()
    {
        return (getWidth()*getHeight());
    }


    void setUpperLeft(QPoint xRecUL)
    {
        upperLeft = xRecUL;
    }
    //Mutator: sets the upperleft coordinate

    void setWidth(int recW)
    {
        width = recW;
    }
    //Mutator: sets the width of the rectangle

    void setHeight(int recH)
    {
        height = recH;
    }
    //Mutator: sets the height of the rectangle

    QPoint getUpperLeft()
    {
        return upperLeft;
    }
    //Accessor: reutrns the upper left coordinate

    int getWidth()
    {
        return width;
    }
    //Accessor: returns the rectangle's width

    int getHeight()
    {
        return height;
    }
    //Accessor: returns the rectangl's height

private:
    QPoint upperLeft;
    //Holds the rectangle's upper left coordinate

    int width, height;
    //Holds the rectangle's width and height


};

#endif // RECTANGLE_H
