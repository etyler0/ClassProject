/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#ifndef LINE_H
#define LINE_H
/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
#include "shape1d.h"
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

// Line class, derived form the shape base class

//! Line class - derived from shape1D
//!
//! \author edt (5/13/18)
class Line : public Shape1D
{
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Line(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xBotRightX,
             int                xBotRightY);
    
    Line() = delete;
    Line& operator=(const Line&) = delete;  // Disallow copying
    Line(const Line&) = delete;
    ~Line();

    std::ostream& print(std::ostream& os) const;
    void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};
#endif // LINE_H
