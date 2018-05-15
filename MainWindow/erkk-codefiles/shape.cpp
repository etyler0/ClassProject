
/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#include <iostream>
#include <math.h>
#include "shape.h"

using namespace std;
//using namespace nserkk::shapes;

//! getID - fetch shape ID
//!
//! \author edt (5/14/18)
//!
//! \return int 
int Shape::getId() const
{
    return shapeId;
}

//! getShapeType - fetch type as specified in enum shapeType 
//!
//! \author edt (5/14/18)
//!
//! \return Shape::shapeType 
Shape::shapeType Shape::getShapeType() const
{
    return typeShape;
}

//! getQPainter - fetch QPainter rendering engine
//!
//! \author edt (5/14/18)
//!
//! \return QPainter&
QPainter& Shape::get_qPainter() // Function that returns the shape painter
{
    return painter;
}

//! get_qPaintDevice - fetch base class of paintable object
//!
//! \author edt (5/14/18)
//!
//! \param void 
//!
//! \return QPaintDevice* 
QPaintDevice *Shape::get_qPaintDevice(void) const
{
    return device;
}

// non-class members
//! operator<< - overloaded operator to enable generic printing of shapes
//!
//! \author edt (5/14/18)
//!
//! \param os - output stream to append to
//! \param s - reference to a shape or derived object
//!
//! \return std::ostream&amp; - output stream
std::ostream& operator<<(std::ostream& os, const Shape& s)
{
    return os << " Id:" << s.getId() << " P:" << s.calcPerimeter() << " A:" << s.calcArea();
}

//! operator<< - overloaded operator to enable generic printing of shapes
//!
//! \author edt (5/14/18)
//!
//! \param os - output stream to append to
//! \param s - pointer to a shape or derived object 
//!
//! \return std::ostream&amp; - output stream
std::ostream& operator<<(std::ostream& os, const Shape* s)
{
    return s->print(os);
}
