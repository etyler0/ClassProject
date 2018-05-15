/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/
#include "ellipse.h"

//! ellipse constructor - create QT drawable object
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
//! \param xWidth 
//! \param xHeight 
Ellipse::Ellipse(QPaintDevice* device,
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
         int                xWidth,
         int                xHeight)
   : Shape2D(device, xId, shapeType::Ellipse,
                  xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                  xBrushColor, xBrushStyle)
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    QPoint lr(xTopLeftX+xWidth, xTopLeftY+xHeight);
    lowerright = lr;
}
    
//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
Ellipse::~Ellipse() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream pointer
//!
//! \return std::ostream&amp; 
std::ostream& Ellipse::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void Ellipse::draw(QPaintDevice* device)
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
//! \param newUpperLeft  - new location of upper left of enclosing rectangle
void Ellipse::move(QPoint &newUpperLeft)
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
void Ellipse::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length using Ramanujan Forumla #1
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Ellipse::calcPerimeter() const
{
    double len = ((lowerright.x()-upperleft.x()));
    double ht = ((lowerright.y()-upperleft.y()));

    // Ramanujan Forumla #1
    return ( (M_PI) * (3*(len-ht) ) - 
              (sqrt( ((3*len)+ht) * (len+(3*ht)) ) ) );
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Ellipse::calcArea() const
{
    return ( ( (lowerright.x()-upperleft.x()) / 2) * ( (lowerright.y()-upperleft.y()) / 2) * M_PI);
}
