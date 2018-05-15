/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/
 #include "polygon.h"

//! constructor - create a QT drawable polygon 2D
//!
//! \author edt (5/14/18)
//!
//! \param device 
//! \param xId 
//! \param xPenColor 
//! \param xPenWidth 
//! \param xPenStyle 
//! \param xPenCapStyle 
//! \param xPenJoinStyle 
//! \param xBrushColor 
//! \param xBrushStyle 
//! \param xPoints 
Polygon::Polygon(QPaintDevice* device,
        int                xId,
        QColor             xPenColor,
        qreal              xPenWidth,
        Qt::PenStyle       xPenStyle,
        Qt::PenCapStyle    xPenCapStyle,
        Qt::PenJoinStyle   xPenJoinStyle,
        QColor             xBrushColor,
        Qt::BrushStyle     xBrushStyle,
        const std::vector<QPoint> &xPoints)
  : Shape2D(device, xId, shapeType::Polygon,
                 xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                 xBrushColor, xBrushStyle), points{xPoints}
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

//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
Polygon::~Polygon() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
std::ostream& Polygon::print(std::ostream& os) const
{
   return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
}

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void Polygon::draw(QPaintDevice* device)
{
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.setBrush(brush);
    const QPoint *qpptr = &(*points.begin());
    paint.drawPolygon(qpptr,points.size());
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}


//! move - relocate polygon to new upper left coordinate 
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Polygon::move(QPoint &newUpperLeft)
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
void Polygon::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Polygon::calcPerimeter() const
{
    double perimeter = 0;
    for(std::vector<QPoint>::const_iterator i=points.begin();i<points.end()-1;++i)
    {

        perimeter += sqrt((pow((i->x()-((i+1)->x())),2)+pow((i->y()-(i+1)->y()),2)));
    }
    return perimeter;
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Polygon::calcArea() const
{
    std::vector<QPoint>::const_iterator i=points.begin();
    double area = ((calcPerimeter())*
                   ((sqrt((pow((i->x()-((i+1)->x())),2)+
                           pow((i->y()-(i+1)->y()),2))))/
                    (2*tan(180/points.size()))))/
                     2;
    return area;
}
