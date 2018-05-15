/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#include "line.h"

//! line constructor - create QT drawable object
//!
//! \author edt (5/13/18)
//!
//! \param device - QPaintDevice
//! \param xId - shape ID
//! \param xPenColor
//! \param xPenWidth
//! \param xPenStyle
//! \param xPenCapStyle
//! \param xPenJoinStyle
//! \param xTopLeftX
//! \param xTopLeftY
//! \param xBotRightX
//! \param xBotRightY
Line::Line(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xBotRightX,
             int                xBotRightY)
       : Shape1D(device, xId, shapeType::Line,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle)
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    points.push_back(ul);
    QPoint lr(xBotRightX, xBotRightY);
    lowerright = lr;
    points.push_back(lr);
}
    
    
//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
Line::~Line() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream pointer
//!
//! \return std::ostream&amp; 
std::ostream& Line::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void Line::draw(QPaintDevice* device)
{
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.drawLine(upperleft, lowerright);
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate circle to new upper left coordinate
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft  - new location of upper left of enclosing rectangle
void Line::move(QPoint &newUpperLeft)
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
//!
//! \param void 
void Line::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Line::calcPerimeter() const
{
    return 0;
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Line::calcArea() const
{
    return 0;
}

