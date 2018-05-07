#include "mainwindow.h"
#include <QApplication>
#include <istream>
#include "shape.h"
#include "shape2d.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "polygon.h"
#include "polyline.h"
#include "line.h"
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

    Rectangle Rect1((QPaintDevice*)&w, 4, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, 20, 200, 170, 100);
    pShapeVector->push_back(&Rect1);
    Square Square1((QPaintDevice*)&w, 5, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, 250, 150, 200);
    pShapeVector->push_back(&Square1);
    Ellipse Ellipse1((QPaintDevice*)&w, 6, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, 520, 200, 170, 100);
    pShapeVector->push_back(&Ellipse1);
    Circle Circle1((QPaintDevice*)&w, 7, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, 750, 150, 200);
    pShapeVector->push_back(&Circle1);
    vector<QPoint> *newpts = new vector<QPoint>();
    QPoint qp(900,90);
    newpts->push_back(qp);
    QPoint qp1(910,20);
    newpts->push_back(qp1);
    QPoint qp2(970,40);
    newpts->push_back(qp2);
    QPoint qp3(980,80);
    newpts->push_back(qp3);
    Polygon Polygon1((QPaintDevice*)&w, 3, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, BrushColor, Qt::VerPattern, *newpts);
    pShapeVector->push_back(&Polygon1);
    vector<QPoint> *newpts1 = new vector<QPoint>();
    QPoint qpl(460,90);
    newpts1->push_back(qpl);
    QPoint qpl1(470,20);
    newpts1->push_back(qpl1);
    QPoint qpl2(530,40);
    newpts1->push_back(qpl2);
    QPoint qpl3(540,80);
    newpts1->push_back(qpl3);
    PolyLine PolyLine1((QPaintDevice*)&w, 2, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, *newpts1);
    pShapeVector->push_back(&PolyLine1);
    Line Line1((QPaintDevice*)&w, 1, PenColor, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin, 20, 90, 100, 20);
    pShapeVector->push_back(&Line1);



    // File Parser call goes here - pass a pointer to pShapeVector - allocate Shapes with new

    pShapeVector->printAsDebug(false,true);

    w.show();
    q.exec();

    return a.exec();
}
