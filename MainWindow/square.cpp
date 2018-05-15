/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#include "square.h"

//! Constructor - create a QT drawable square 2D
//!
//! \author edt (5/14/18)
//!
//! \param device - QPaintDevice
//! \param xId - shape ID
//! \param xPenColor 
//! \param xPenWidth 
//! \param xPenStyle 
//! \param xPenCapStyle 
//! \param xPenJoinStyle 
//! \param xBrushColor 
//! \param xBrushStyle 
//! \param xTopLeftX 
//! \param xTopLeftY 
//! \param xSide 
Square::Square(QPaintDevice* device,
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

//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
Square::~Square() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream
//!
//! \return std::ostream&amp; 
std::ostream& Square::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void Square::draw(QPaintDevice* device)
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

//! move - relocate square to new upper left coordinate 
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Square::move(QPoint &newUpperLeft)
{
    int deltaX = (newUpperLeft.x() - upperleft.x());
    int deltaY = (newUpperLeft.y() - upperleft.y());

    upperleft = newUpperLeft;
    lowerright.setX(lowerright.x() + deltaX);
    lowerright.setY(lowerright.y() + deltaY);
}

//! update - force redraw of object
//!
//! \author edt (5/13/18)
void Square::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Square::calcPerimeter() const
{
    return ( ((lowerright.x()-upperleft.x()) * 2) + ((lowerright.y()-upperleft.y()) * 2));
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Square::calcArea() const
{
    return ( (lowerright.x()-upperleft.x()) * (lowerright.y()-upperleft.y()));
}
