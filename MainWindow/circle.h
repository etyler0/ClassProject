/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H
/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
#include "shape2d.h"
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

//! Circle class - derived from Shape2D
//!
//! \author edt (5/13/18)
class Circle : public Shape2D
{
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Circle(QPaintDevice* device,
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
             int                xDiameter);

    Circle() = delete;         // default constructor never used
    Circle& operator=(const Circle&) = delete;  // Disallow copying
    Circle(const Circle&) = delete;
    ~Circle();

    std::ostream& print(std::ostream& os) const;

    void draw(QPaintDevice* device) override;
    void move(QPoint &newUpperLeft) override;
    void update(void) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // CIRCLE_H
