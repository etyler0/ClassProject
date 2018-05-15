/*****************************************************
 * Class Project
 *
 * Class: CS1C at 10am, T/TH
 * Group: ERKK (Eugene, Richard, Kevin, Kole)
 * Created on: 4/4/18
 *****************************************************/

#include "text.h"

//! create a QT drawable text area - derives directly from Shape
//!
//! \author edt (5/14/18)
//!
//! \param device 
//! \param xId 
//! \param xString 
//! \param xColor 
//! \param xAlignment 
//! \param xFontSize 
//! \param xFontFamily 
//! \param xFontStyle 
//! \param xFontWeight 
//! \param xTopLeftX 
//! \param xTopLeftY 
//! \param xWidth 
//! \param xHeight 
Text::Text(QPaintDevice* device,
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
     int                xHeight)
    : Shape(device, xId, shapeType::Text), String{xString}, Color{xColor}, Alignment{xAlignment},
      FontSize{xFontSize}, FontFamily{xFontFamily}, FontStyle{xFontStyle},
      FontWeight{xFontWeight}
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    QPoint lr(xTopLeftX+xWidth, xTopLeftY+xHeight);
    lowerright = lr;
}

//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
Text::~Text() {};               vector<QPoint> v;

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream
//!
//! \return std::ostream&amp; 
std::ostream& Text::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device 
void Text::draw(QPaintDevice* device)
{
    QPainter& tPaint = get_qPainter();
    QFont tFont(FontFamily, FontSize);
    QPen tPen(Color);
    QRect tRect(upperleft, lowerright);
    tFont.setStyle(FontStyle);
    tFont.setWeight(FontWeight);
    tPaint.begin(device);
    tPaint.setFont(tFont);
    tPaint.setPen(tPen);
    tPaint.drawText(tRect, Alignment, String);
    tPaint.setPen(QPen());
    tPaint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    tPaint.end();
}

//! move - relocate text to new upper left coordinate 
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Text::move(QPoint &newUpperLeft)
{
    int deltaX = (newUpperLeft.x() - upperleft.x());
    int deltaY = (newUpperLeft.y() - upperleft.y());

    upperleft = newUpperLeft;
    lowerright.setX(lowerright.x() + deltaX);
    lowerright.setY(lowerright.y() + deltaY);
}

//! update - force redraw of object
//!
//! \author edt (5/13/18)
void Text::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Text::calcPerimeter() const
{
    return 0;
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double 
double Text::calcArea() const
{
    return 0;
}
