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

// Custom libraries/directives
//!!!!    Custom vector class goes here   !!!!


/****************************************************************************************************
 * IDEA: ? It may be a good idea to put our classes in seperate namespaces but we can decide later ?
 ****************************************************************************************************/

 /**********************************************************
  * Shape Base Class (Abstract base class) -
  * 
  * All shape types inherit from this base class.
  * This class uses composition for the Qt 2D graphics 
  * elements such as: QPainter, QBrush, QPen.
  **********************************************************/
class Shape
{
public: 
    // Enum with all different shape types
    enum shapeType {Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};
    
    // Need Shape constructor 
    // Shape(...)

    // Normal functions
        // Mutator methods
    // void setId(int xId)
    // void setShapeType(shapeType xShape)
    // void setQBrush(QBrush xBrush)
    // void setQPen(QPen xPen)

        // Assesor Methods
    // int getId()
    // shapeType setShapeType()
    // QBrush setQBrush()
    // QPen setQPen()

    // Virtual functions
    // Functions needed to calculate perimeter, calculate area of the shape

    // Pure Virtual functions
    virtual void draw() = 0;
    
    virtual void move() = 0;

    virtual void update() = 0;


protected:
    QPainter& get_qPainter(); // Function that returns the shape painter 
    
private:
    QPainter painter;    // QPainter variable - responsible for the drawing of the shapes in the viewing area
    int shapeId;         // A unique id number that will be attached to a shape
    shapeType typeShape; // The specific type of shape, from the enum shapeType
    QBrush brush;        // The brush object for the shape
    QPen pen;            // The pen object for the shape
};

#endif