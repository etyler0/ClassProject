/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/
#include "circle.h"

//! Constructor - create a QT drawable circle 2D
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
//! \param xBrushColor
//! \param xBrushStyle
//! \param xTopLeftX
//! \param xTopLeftY
//! \param xDiameter
Circle::Circle(QPaintDevice* device,
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
             int                xDiameter)
       : Shape2D(device, xId, shapeType::Circle,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                      xBrushColor, xBrushStyle)
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    QPoint lr(xTopLeftX+xDiameter, xTopLeftY+xDiameter);
    lowerright = lr;
}

//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
Circle::~Circle() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream
//!
//! \return std::ostream&amp; 
std::ostream& Circle::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void Circle::draw(QPaintDevice* device)
{
    QRect rect1(upperleft, lowerright);
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.setBrush(brush);
    paint.drawEllipse(rect1);
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate circle to new upper left coordinate 
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Circle::move(QPoint &newUpperLeft)
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
void Circle::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Circle::calcPerimeter() const
{
    return ( (M_PI) * (lowerright.x()-upperleft.x()) );
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Circle::calcArea() const
{
    return ( pow( ( (lowerright.x()-upperleft.x()) /2) ,2 ) * M_PI);
}
