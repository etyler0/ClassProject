#include "renderarea.h"

//Canvas Constructor
renderArea::renderArea(QWidget *parent)
{

}

//assigns the passed vector of Shape* to canvas' Shape* vector
void renderArea::setShape(nserkkvector::MyVector<Shape*> source)
{
    shapes = source;
}

//returns a specific shape from canvas's current shapes
Shape* renderArea::getShape(int index)
{
    return *(shapes.begin()+(index-1));
}

//returns the shape* vector
nserkkvector::MyVector<Shape*>& renderArea::getShapes()
{
    return shapes;
}

//Overloaded paintEvent function to draw each shape to canvas
void renderArea::paintEvent(QPaintEvent *pEvent)
{
    nserkkvector::MyVector<Shape*>::iterator i = shapes.begin();
    QPaintDevice* device = this;
        while(i < shapes.end())
        {
           (*i)->draw(device);
            ++i;
        }
}


