
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


int Shape::getId() const
{
    return shapeId;
}

Shape::shapeType Shape::getShapeType() const
{
    return typeShape;
}

double Shape::calcPerimeter(void) const
{
    return 0.0;   // default to zero for text and line
};

double Shape::calcArea(void) const
{
    return 0.0; // default to zero for text and line
};  

QPainter& Shape::get_qPainter() // Function that returns the shape painter
{
    return painter;
}

QPaintDevice *Shape::get_qPaintDevice(void) const
{
    return device;
}

// non-class members
std::ostream& operator<<(std::ostream& os, const Shape& s)
{
    return os << " Id:" << s.getId() << " P:" << s.calcPerimeter() << " A:" << s.calcArea();
}
std::ostream& operator<<(std::ostream& os, const Shape* s)
{
    return s->print(os);
}
#if 0
struct compare_shape_id {
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return (s1->getId() < s2->getId()); // dereference pointer, compare ids
    }
};

struct compare_shape_perimeter {
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return (s1->calcPerimeter() < s2->calcPerimeter());
    }
};

struct compare_shape_area {
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return (s1->calcArea() < s2->calcArea());
    }
};
#endif

