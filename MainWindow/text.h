#ifndef TEXT_H
#define TEXT_H
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


class Text : public Rectangle
{
public:
    Text(QPaintDevice* device,
         int xId=-1,
         QPen xPen=Qt::NoPen,
         QBrush xBrush=Qt::NoBrush,
         QPoint xUpperLeft=QPoint(0,0),
         int xWidth=0,
         int xHeight=0,
         QString qText=""):
         Rectangle(device,xId,Shape::shape::Text,xPen,xBrush,xUpperLeft,xWidth,xHeight),objText(qText){}

    void draw(QPaintDevice* device)
    {
        QPainter& tPaint = getPainter();
        tPaint.begin(device);
        tPaint.setPen(this->getPen());
        tPaint.setBrush(this->getBrush());
        tPaint.drawText((getUpperLeft()).x(),getUpperLeft().y(),objText);
        tPaint.setPen(QPen());
        tPaint.drawText(getUpperLeft().x()-7,getUpperLeft().y()-7,QString::number(this->getId()));
        tPaint.end();
    }

    void move(Shape* source)
    {
        this->Rectangle::move(source);
    }

    QString getText()
    {
        return objText;
    }

    void setFont(QFont &source)
    {
        QPainter &paint = getPainter();
        paint.setFont(source);
    }

    double calcArea()
    {
        return 0;
    }

    double calcPerimeter()
    {
        return 0;
    }

    void setText(QString source)
    {
        objText = source;
    }

private:
    QString objText;
};

#endif // TEXT_H
