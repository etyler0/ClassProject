/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#ifndef SHAPE2D_H
#define SHAPE2D_H
#include "shape.h"


// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

class Shape2D: public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.
    QPen pen;           ///< Pen used to draw shape outline
    QBrush brush;       ///< Brush used to fill 2D object interior
    QPoint upperleft;   ///< Lower right anchor for bounding rectangle               
    QPoint lowerright;  ///< vector containing endpints and vertices of line objects 

    //! Constructor - abstract class for 2D (circle, square, etc) objects
    //!
    //! \author edt (5/14/18)
    //!
    //! \param device - QPaintDevice
    //! \param xId - shape ID
    //! \param xType 
    //! \param xPenColor 
    //! \param xPenWidth 
    //! \param xPenStyle 
    //! \param xPenCapStyle 
    //! \param xPenJoinStyle 
    //! \param xBrushColor 
    //! \param xBrushStyle 
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

    Shape2D() = delete;         // default constructor never used
    Shape2D& operator=(const Shape&) = delete;  // Disallow copying
    Shape2D(const Shape&) = delete;

    //! Destructor - simply free the object space
    //!
    //! \author edt (5/13/18)
    virtual ~Shape2D() {}

    //! print - print limited information about derived instance for debugging
    //!
    //! \author edt (5/13/18)
    //!
    //! \param os - output stream
    //!
    //! \return std::ostream&amp; 
    virtual std::ostream& print(std::ostream& os) const = 0;
};

#endif // SHAPE2D_H
