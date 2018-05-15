/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#include "polyline.h"

//! constructor - create a QT drawable line 1D
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
//! \param xPoints 
PolyLine::PolyLine(QPaintDevice* device,
         int                xId,
         QColor             xPenColor,
         qreal              xPenWidth,
         Qt::PenStyle       xPenStyle,
         Qt::PenCapStyle    xPenCapStyle,
         Qt::PenJoinStyle   xPenJoinStyle,
         const std::vector<QPoint> &xPoints)
   : Shape1D(device, xId, shapeType::Polyline,
                  xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle)
{
   // object specific transform from points supplied to bounding points
    qreal minX = 0.0;
    qreal maxX = 0.0;
    qreal minY = 0.0;
    qreal maxY = 0.0;

    points = xPoints;

    for(std::vector<QPoint>::iterator i=points.begin();i!=points.end()-1;++i)
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

//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
PolyLine::~PolyLine() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream
//!
//! \return std::ostream&amp; 
std::ostream& PolyLine::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void PolyLine::draw(QPaintDevice* device)
{
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    const QPoint *qpptr = &(*points.begin());
    paint.drawPolyline(qpptr,points.size());
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate line to new upper left coordinate 
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void PolyLine::move(QPoint &newUpperLeft)
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

//! update - force redraw of object
//!
//! \author edt (5/13/18)
//!
//! \param void 
void PolyLine::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double 
double PolyLine::calcPerimeter() const
{
    return 0;
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double PolyLine::calcArea() const
{
    return 0;
}
