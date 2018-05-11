#ifndef SHAPE1D_H
#define SHAPE1D_H
#include "shape.h"


// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

class Shape1D: public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.
    QPen pen;
    QPoint upperleft;
    QPoint lowerright;
    std::vector<QPoint> points;

    Shape1D(QPaintDevice* device,
                 int                xId,
                 shapeType          xType,
                 QColor             xPenColor,
                 qreal              xPenWidth,
                 Qt::PenStyle       xPenStyle,
                 Qt::PenCapStyle    xPenCapStyle,
                 Qt::PenJoinStyle   xPenJoinStyle)
           : Shape(device, xId, xType)
    {
        pen.setColor(xPenColor);
        pen.setWidth(xPenWidth);
        pen.setStyle(xPenStyle);
        pen.setCapStyle(xPenCapStyle);
        pen.setJoinStyle(xPenJoinStyle);
    }

    Shape1D() = delete;
    Shape1D& operator=(const Shape1D&) = delete;  // Disallow copying
    Shape1D(const Shape1D&) = delete;
    virtual ~Shape1D() {}

    virtual std::ostream& print(std::ostream& os) const = 0;
};

#endif // SHAPE1D_H
