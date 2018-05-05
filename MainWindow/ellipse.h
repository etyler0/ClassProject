#ifndef ELLIPSE_H
#define ELLIPSE_H
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

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device,
            int xId=-1,
            Shape::shape s=shape::Ellipse,
            QPen xPen=Qt::NoPen,
            QBrush xBrush=Qt::NoBrush,
            QPoint xOrigin=QPoint(0,0),
            int x_Rx=0,
            int x_Ry=0):
            Shape(device,xId,s,xPen,xBrush),origin(xOrigin),rx(x_Rx),ry(x_Ry){}

    // Gets x radius value
    int getRx()
    {
        return rx;
    }

    // Gets y radius value
    int getRy()
    {
        return ry;
    }

    QPoint getOrigin()
    {
        return origin;
    }

    void setOrigin(QPoint norigin)
    {
        origin = norigin;
    }

    void setRx(int xRx)
    {
        rx = xRx;
    }

    void setRy(int xRy)
    {
        ry = xRy;
    }

    void draw(QPaintDevice* device)
    {
        QPainter& ePaint = getPainter();
        ePaint.begin(device);
        ePaint.setPen(this->getPen());
        ePaint.setBrush(this->getBrush());
        ePaint.drawEllipse(getOrigin(),rx,ry);
        ePaint.setPen(QPen());
        ePaint.drawText(getOrigin().x()-rx,getOrigin().y()-ry,QString::number(this->getId()));
        ePaint.end();
    }

    void move(Shape* source)
    {
        setOrigin(source->getOrigin());
        setRx(source->getRx());
        setRy(source->getRy());
    }

    double calcPerimeter()
    {
        int a = getRx();
        int b = getRy();

        return 2*M_PI*sqrt((pow(a,2) + pow(b,2))/2);
    }

    double calcArea()
    {
        int a = getRx();
        int b = getRy();

        return a*b*M_PI; // returns A * B * Pi
    }

private:
    QPoint origin;

    int rx; // X radius value
    int ry; // Y radius value
};

#endif // ELLIPSE_H
