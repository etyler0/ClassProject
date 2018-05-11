#ifndef TEXT_H
#define TEXT_H
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


class Text : public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to 
    //       access and modify them without restrictions and so creating 
    //       accessors and mutators adds no value.
    QString            String;
    QColor             Color;
    Qt::AlignmentFlag  Alignment;
    int                FontSize;
    QString            FontFamily;
    QFont::Style       FontStyle;
    QFont::Weight      FontWeight;
    QPoint             upperleft;
    QPoint             lowerright;

    Text(QPaintDevice* device,
         int                xId,
         //const char        *xString,
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
    Text() = delete;
    Text& operator=(const Text&) = delete;  // Disallow copying
    Text(const Text&) = delete;
    ~Text() {};               vector<QPoint> v;

    std::ostream& print(std::ostream& os) const
    {
        return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
    };

    void draw(QPaintDevice* device)
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

    void move(QPoint &newUpperLeft)
    {
        int deltaX = (newUpperLeft.x() - upperleft.x());
        int deltaY = (newUpperLeft.y() - upperleft.y());

        upperleft = newUpperLeft;
        lowerright.setX(lowerright.x() + deltaX);
        lowerright.setY(lowerright.y() + deltaY);
    }

    void update(void)
    {
        draw((get_qPaintDevice()));
        return;
    }


    double calcArea() const
    {
        return 0;
    }

    double calcPerimeter() const
    {
        return 0;
    }
};

#endif // TEXT_H
