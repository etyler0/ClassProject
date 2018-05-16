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
#include "text.h"
#include "login.h"
#include "vector.h"  // for MyVector
#include "parser.h"
#include "selection_sort.h"


using namespace nserkkvector;
using namespace nserkkselsort;
//using namespace nserkk::shapes;

// global to pass authorization
privilege auth;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyVector<Shape*> *pShapeVector = new MyVector<Shape*>;

    MainWindow w;
    login q;

#undef READ_SHAPES_FROM_FILE
#ifdef READ_SHAPES_FROM_FILE
    // File Parser call goes here - pass a pointer to pShapeVector - allocate Shapes with new
    readFile((QPaintDevice*)&w, pShapeVector);
#else

    // temporary code to construct simple shapes for testing only
    Line *pLine1 = new Line((QPaintDevice*)&w, 1, Qt::GlobalColor::blue, 2, Qt::PenStyle::DashDotLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin, 20, 90, 100, 20);
    pShapeVector->push_back(pLine1);
    pLine1->draw(&w);
    QPoint qpx(0,0);
    pLine1->move(qpx);
    pLine1->calcArea();
    pLine1->calcPerimeter();

    vector<QPoint> *newpts1 = new vector<QPoint>();
    QPoint qpl(460,90);
    newpts1->push_back(qpl);
    QPoint qpl1(470,20);
    newpts1->push_back(qpl1);
    QPoint qpl2(530,40);
    newpts1->push_back(qpl2);
    QPoint qpl3(540,80);
    newpts1->push_back(qpl3);
    PolyLine *pPolyLine1 = new PolyLine((QPaintDevice*)&w, 2, Qt::GlobalColor::blue, 6, Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin, *newpts1);
    pShapeVector->push_back(pPolyLine1);

    vector<QPoint> *newpts = new vector<QPoint>();
    QPoint qp(900,90);
    newpts->push_back(qp);
    QPoint qp1(910,20);
    newpts->push_back(qp1);
    QPoint qp2(970,40);
    newpts->push_back(qp2);
    QPoint qp3(980,80);
    newpts->push_back(qp3);

    Polygon *pPolygon1 = new Polygon((QPaintDevice*)&w, 3, Qt::GlobalColor::cyan, 6, Qt::PenStyle::DashDotLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin, Qt::GlobalColor::yellow, Qt::BrushStyle::SolidPattern, *newpts);
    pShapeVector->push_back(pPolygon1);

    Rectangle *pRect1 = new Rectangle((QPaintDevice*)&w, 4, Qt::GlobalColor::blue, 0, Qt::PenStyle::DashLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin, Qt::GlobalColor::red, Qt::BrushStyle::VerPattern, 20, 200, 170, 100);
    pShapeVector->push_back(pRect1);

    Square *pSquare1 = new Square((QPaintDevice*)&w, 5, Qt::GlobalColor::blue, 0, Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin, Qt::GlobalColor::blue, Qt::BrushStyle::HorPattern, 250, 150, 200);
    pShapeVector->push_back(pSquare1);

    Ellipse *pEllipse1 = new Ellipse((QPaintDevice*)&w, 6, Qt::GlobalColor::black, 12, Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin, Qt::GlobalColor::white, Qt::BrushStyle::NoBrush, 520, 200, 170, 100);
    pShapeVector->push_back(pEllipse1);

    Circle *pCircle1 = new Circle((QPaintDevice*)&w, 7, Qt::GlobalColor::black, 12, Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin, Qt::GlobalColor::magenta, Qt::BrushStyle::SolidPattern, 750, 150, 200);
    pShapeVector->push_back(pCircle1);

    Text *pText1 = new Text((QPaintDevice*)&w, 8, "Class Project 2- 2D Graphics Modeler", Qt::GlobalColor::blue, Qt::AlignmentFlag::AlignCenter, 10, "Comic Sans MS", QFont::Style::StyleNormal, QFont::Weight::Normal, 250, 425, 500, 50);
    pShapeVector->push_back(pText1);

#endif
    //readFile((QPaintDevice*)&w, pShapeVector);
    cout << "By ID==============" << endl;
    nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_id());
    pShapeVector->printAsDebug(false,true);
    cout << "By perimeter==============" << endl;
    nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_perimeter());
    pShapeVector->printAsDebug(false,true);
    cout << "By area==============" << endl;
    nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_area());
    pShapeVector->printAsDebug(false,true);
    cout << endl;
    w.setVector(pShapeVector);
    w.show();
    q.exec();

    int retcode = a.exec();

    // clean up MyVector elemnets
    MyVector<Shape *>::iterator ptr = pShapeVector->begin();
    while (ptr != pShapeVector->end())
    {
        delete *ptr;
        ptr++;
    }
    delete pShapeVector;

    return retcode;
}
