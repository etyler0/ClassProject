#include "mainwindow.h"
#include <QApplication>
#include <istream>
#include "shape.h"
#include "shape2d.h"
#include "rectangle.h"
#include "square.h"
#include "login.h"
#include "vector.h"  // for MyVector
#include "parser.h"


using namespace nserkkvector;

// global to pass authorization
privilege auth;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login q;

    MyVector<Shape*> *pShapeVector = new MyVector<Shape*>;
    readFile((QPaintDevice*)&w, pShapeVector);

    // temporary code to construct a simple shape for testing only
    QColor PenColor;
    PenColor.fromRgb(0,0,255);

    QColor BrushColor;
    BrushColor.fromRgb(255,0,0);

    Rectangle Rect1((QPaintDevice*)&w, 1, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, 20, 200, 170, 100);
    pShapeVector->push_back(&Rect1);
    Square Square1((QPaintDevice*)&w, 1, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, 250, 150, 200);
    pShapeVector->push_back(&Square1);

    // File Parser call goes here - pass a pointer to pShapeVector - allocate Shapes with new

    pShapeVector->printAsDebug(false,true);

    w.show();
    q.exec();

    return a.exec();
}
