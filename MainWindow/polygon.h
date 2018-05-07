#ifndef POLYGON_H
#define POLYGON_H
/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
#include "shape2d.h"
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

class Polygon : public Shape2D
{
private:
    Polygon() {}; // Default constructor - never used - all fields must be explictly set

    vector<QPoint> points;
    
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Polygon(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             QColor             xBrushColor,
             Qt::BrushStyle     xBrushStyle,
             const vector<QPoint> &source)
       : Shape2D(device, xId, shapeType::Polygon,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                      xBrushColor, xBrushStyle), points{source}
    {
        // object specific transform from points supplied to bounding points

        qreal minX = 0.0;
        qreal maxX = 0.0;
        qreal minY = 0.0;
        qreal maxY = 0.0;

        for(vector<QPoint>::iterator i=points.begin();i!=points.end()-1;++i)
        {
            if (i->x() < minX)
            {
                minX = i->x();
            }
            if (i->x() > maxX)
            {
                maxX = i->x();
            }

            if (i->y() < minY)
            {
                minY = i->y();
            }
            if (i->y() > maxY)
            {
                maxY = i->y();
            }
        }

        upperleft.setX(minX);
        upperleft.setY(minY);
        lowerright.setX(maxX);
        lowerright.setY(maxY);
    }
    
    ~Polygon() {};

    // draw() function from shape base class
    void draw(QPaintDevice* device)
    {
        QPainter& paint = get_qPainter();
        paint.begin(device);
        paint.setPen(pen);
        paint.setBrush(brush);
        QPoint *qpptr = &(*points.begin());
        paint.drawPolygon(qpptr,points.size());
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

        for(vector<QPoint>::iterator i=points.begin();i!=points.end()-1;++i)
        {
            i->setX(i->x() + deltaX);
            i->setY(i->y() + deltaY);
        }
    }

    void update(void)
    {
        draw((get_qPaintDevice()));
        return;
    }

    // calcPerimeter() function from shape base class
    double calcPerimeter()
    {
        double perimeter = 0;
        for(vector<QPoint>::iterator i=points.begin();i<points.end()-1;++i)
        {
            perimeter += sqrt((pow((i->x()-((i+1)->x())),2)+pow((i->y()-(i+1)->y()),2)));
        }
        return perimeter;
    }

    // calcArea() function from shape base class
    double calcArea()
    {
        vector<QPoint>::iterator i=points.begin();
        double area = ((calcPerimeter())*
                       ((sqrt((pow((i->x()-((i+1)->x())),2)+
                               pow((i->y()-(i+1)->y()),2))))/
                        (2*tan(180/points.size()))))/
                         2;
        return area;
    }

};
#endif // POLYGON_H
