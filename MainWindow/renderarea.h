/******************************
 * Render Area - Creates the
 * widget where the shapes
 * will be rendered
 ******************************/

#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPixmap>
#include "shape.h"
#include "vector.h"


class renderArea: public QWidget
{
    renderArea(QWidget* parent=0);
    //Takes a QWidget* to establish parent

    //returns a specific shape from canvas's current shapes
    void setShape(nserkkvector::MyVector<Shape*> source);

    Shape* getShape(int);
    //returns a specific shape from the canvas' shape vector, based on index passed in

    nserkkvector::MyVector<Shape*>& getShapes();
    //returns the entire shape vector

    void paintEvent(QPaintEvent *pEvent);

private:

    nserkkvector::MyVector<Shape*> shapes;
    // holds the shapes that the modeler will draw and modify
    renderArea *renderA;
    //holds the canvas object


};

#endif // RENDERAREA_H


