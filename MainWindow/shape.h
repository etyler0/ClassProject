/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/
#ifndef SHAPE_H
#define SHAPE_H

/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

// Custom libraries/directives
//!!!!    Custom vector class goes here   !!!!


/****************************************************************************************************
 * IDEA: ? It may be a good idea to put our classes in seperate namespaces but we can decide later ?
 ****************************************************************************************************/

 /*********************************************************************************************************
  * Shape Base Class (Abstract base class) -
  *
  * All shape types inherit from this base class.
  * This class uses composition for the Qt 2D graphics
  * elements such as: QPainter, QBrush, QPen.
  *
  * Basic 2D drawing example link - http://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html
  *********************************************************************************************************/
class Shape
{
public:
    // Enum with all different shape types
    enum shapeType {Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};
    Shape() {}
    // Shape Constructor - using BMI list
    Shape(QPaintDevice *pDevice,
          int xId,
          shapeType s)
           : device{pDevice},
             shapeId{xId},
             typeShape{s},
             painter{pDevice} {}

    // Normal functions
    int getId()
    {
        return shapeId;
    }

    shapeType getShapeType()
    {
        return typeShape;
    }


    // Pure Virtual functions
    virtual void draw(QPaintDevice* pDevice) = 0;

    virtual void move(Shape *shapeSource) = 0;

    virtual void update(void) = 0;

    virtual double calcPerimeter(void) { return 0.0; };  // default to zero for text and line
    virtual double calcArea(void)      { return 0.0; };  // default to zero for text and line

    // Qpoint class documentation: http://doc.qt.io/qt-5/qpoint.html

    // Virtual functions for polymorphism
    // Operations for rendering and other
    //

#if 0
    // NOTE: The following definitions should be deleted - only need to be in derived class
    // For the line, functions that will get the start and endpoints of a line
    //virtual QPoint getStartPoint(){}
    //virtual QPoint getEndPoint(){}

    // Functions that pertain to the rectangle shape
    //virtual int getWidth(){}        // Function that gets the width of the rectangle
    //virtual int getHeight(){}       // Function that gets the height of the rectangle
    //virtual QPoint getUpperLeft(){} // Function that gets the upper left most point of the rectangle
#endif



    // Virtual Destructor
    virtual ~Shape() {}

protected:
    QPainter& get_qPainter()  // Function that returns the shape painter
    {
        return painter;
    }

    QPaintDevice *get_qPaintDevice(void)
    {
        return device;
    }

private:
    QPaintDevice *device;    // QPainter variable - responsible for the drawing of the shapes in the viewing area
    int shapeId;         // A unique id number that will be attached to a shape
    shapeType typeShape; // The specific type of shape, from the enum shapeType
    QPainter painter;
};

#endif
