#ifndef SHAPE2D_H
#define SHAPE2D_H
#include "shape.h"

class Shape2D: public Shape
{
public:
    Shape2D() {} // Default constructor never used - all elements must be explictly set
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.
    QPen pen;
    QBrush brush;
    QPoint upperleft;
    QPoint lowerright;

    Shape2D(QPaintDevice* device,
                 int                xId,
                 shapeType          xType,
                 QColor             xPenColor,
                 qreal              xPenWidth,
                 Qt::PenStyle       xPenStyle,
                 Qt::PenCapStyle    xPenCapStyle,
                 Qt::PenJoinStyle   xPenJoinStyle,
                 QColor             xBrushColor,
                 Qt::BrushStyle     xBrushStyle)
           : Shape(device, xId, xType)
    {
        pen.setColor(xPenColor);
        pen.setWidth(xPenWidth);
        pen.setStyle(xPenStyle);
        pen.setCapStyle(xPenCapStyle);
        pen.setJoinStyle(xPenJoinStyle);

        brush.setColor(xBrushColor);
        brush.setStyle(xBrushStyle);
    }

    virtual ~Shape2D() {}
};

#endif // SHAPE2D_H
