#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include <QComboBox>
#include <QAbstractItemView>
#include <QDebug>
using namespace nserkkvector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setVector(MyVector<Shape*> *temp){
    pShapeVector = temp;
    pShapeVector->printAsDebug(1, 1);
}

void MainWindow::on_actionFeedback_triggered()
{
    Testimonials = new testimonials(this);
    Testimonials->show();
}

void MainWindow::on_actionAbout_triggered()
{
    About = new about(this);
    About->show();
}

void MainWindow::on_actionContact_Us_triggered()
{
    Contact = new contact(this);
    Contact->show();
}

void MainWindow::on_actionSort_by_ID_triggered()
{
    Reports = new reports(this);
    Reports->show();
}

void MainWindow::on_combobox_add_shapetype_activated(int index)
{
    switch(index){
    case 0:
        addCurShape = baseSelect;
        break;

    //  Line selection
    case 1:
    case 2:
        addCurShape = baseLine;
        break;

    //  2D shape selection
    case 3:
    case 4:
    case 5:
    case 6:
        addCurShape = base2D;
        break;

    //  Text selection
    case 7:
        addCurShape = baseText;
        break;

    default:
        break;
    }
}
