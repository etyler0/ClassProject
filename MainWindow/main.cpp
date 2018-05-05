#include "mainwindow.h"
#include <QApplication>
#include <istream>
#include "shape.h"
#include "vector.h"


using namespace nserkkvector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyVector<Shape*> *pShapeVector = new MyVector<Shape*>;

    // File Parser call goes here - pass a pointer to pShapeVector - allocate Shapes with new

    pShapeVector->printAsDebug(false,true);

    return a.exec();
}
