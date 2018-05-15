/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#ifndef TEXT_H
#define TEXT_H
/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
#include "shape.h"
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

class Text : public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.
    QString            String;      ///< string to display
    QColor             Color;       ///< color of string text
    Qt::AlignmentFlag  Alignment;   ///< alignment of string in bounding rectangle
    int                FontSize;    ///< font size of string
    QString            FontFamily;  ///< font family to use in rendering string
    QFont::Style       FontStyle;
    QFont::Weight      FontWeight;
    QPoint             upperleft;   ///< Upper left anchor of bounding rectangle
    QPoint             lowerright;  ///< Lower right anchor for bounding rectangle

    Text(QPaintDevice* device,
         int                xId,
         QString            xString,
         QColor             xColor,
         Qt::AlignmentFlag  xAlignment,
         int                xFontSize,
         QString            xFontFamily,
         QFont::Style       xFontStyle,
         QFont::Weight      xFontWeight,
         int                xTopLeftX,
         int                xTopLeftY,
         int                xWidth,
         int                xHeight);

    Text() = delete;
    Text& operator=(const Text&) = delete;  // Disallow copying
    Text(const Text&) = delete;
    ~Text();

    std::ostream& print(std::ostream& os) const;
   void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};

#endif // TEXT_H
