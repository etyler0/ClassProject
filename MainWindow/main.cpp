#include "mainwindow.h"
#include <QApplication>
#include <istream>
#include "shape.h"
#include "login.h"
#include "vector.h"


using namespace nserkkvector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    privilege user;
    MainWindow w(user);
    login q(user);

    w.show();
    q.exec();
    MyVector<Shape*> *pShapeVector = new MyVector<Shape*>;

    // File Parser call goes here - pass a pointer to pShapeVector - allocate Shapes with new

    pShapeVector->printAsDebug(false,true);

    return a.exec();
}
