#ifndef POLYGON_H
#define POLYGON_H
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



class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* device,
            int xId=-1,
            QPen xPen=Qt::NoPen,
            QBrush xBrush=Qt::NoBrush,
            const vector<QPoint> &source=vector<QPoint>()):
            Shape(device,xId,Shape::shape::Polygon,xPen,xBrush){points = source;}

    void draw(QPaintDevice* device)
    {
        QPainter& plyPaint = getPainter();
        plyPaint.begin(device);
        plyPaint.setPen(this->getPen());
        plyPaint.setBrush(this->getBrush());
        plyPaint.drawPolygon(points.begin(),points.size());
        plyPaint.setPen(QPen());
        plyPaint.drawText(points.begin()->x()-5,points.begin()->y()-5,QString::number(this->getId()));
        plyPaint.end();
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

        double perimeter = 0;
        for(vector<QPoint>::iterator i=points.begin();i<points.end()-1;++i)
        {
            perimeter += sqrt((pow((i->x()-((i+1)->x())),2)+pow((i->y()-(i+1)->y()),2)));
        }
        return perimeter;
    }


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

private:
    vector<QPoint> points;
};

#endif // POLYGON_H
