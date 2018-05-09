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

void MainWindow::comboBoxBaseShape(int index, base &typeShape){
    switch(index){
    case 0:
        typeShape = baseSelect;
        break;

    //  Line selection
    case 1:
    case 2:
        typeShape = baseLine;
        break;

    //  2D shape selection
    case 3:
    case 4:
    case 5:
    case 6:
        typeShape = base2D;
        break;

    //  Text selection
    case 7:
        typeShape = baseText;
        break;

    default:
        break;
    }
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

void MainWindow::on_combobox_add_shapeType_currentIndexChanged(int index)
{
    comboBoxBaseShape(index, addCurShape);

    //  Show Pen
    if(addCurShape == baseLine || addCurShape == base2D){
        ui->stackedWidget_add_interface->setCurrentIndex(0);
        qDebug() << "SHOW" << endl;
    }

    //  Show Text
    else{
        ui->stackedWidget_add_interface->setCurrentIndex(1);
        qDebug() << "HIDE" << endl;
    }

    //  Hide Counter
    if(addCurShape == baseSelect){
        ui->groupBox_add_shapeCounter->hide();
    }

    //  Show Counter
    else{
        ui->groupBox_add_shapeCounter->show();
    }

    //  Brush
    if(addCurShape == base2D){
        ui->widget_add_brush->show();
    }

    //  No Brush
    else{
        ui->widget_add_brush->hide();
    }
}
