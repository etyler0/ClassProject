#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include <QComboBox>
#include <QAbstractItemView>
#include <QDebug>
using namespace nserkkvector;

//=============== DEFAULT CLASS ===================//
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

//================ WINDOW DISPLAYS ===================//
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

//================ IMPORTANT FUNCTIONS ================//

//  Overloaded show event
void MainWindow::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    comboBoxBaseShape(ui->combobox_add_shapeType->currentIndex(), addCurShape);
    comboBoxBaseShape(ui->combobox_mod_shapeType->currentIndex(), modCurShape);
    reloadVector();
    updateAddTab();
    updateModTab();
}

//  Set vector from main
void MainWindow::setVector(MyVector<Shape*> *temp){
    pShapeVector = temp;
    pShapeVector->printAsDebug(1, 1);
}

//  Reloads the vector into the combobox
void MainWindow::reloadVector(){
    for(MyVector<Shape *>::iterator i = pShapeVector->begin(); i < pShapeVector->end(); ++i){
        ui->comboBox_mod_ID->addItem(QString::number((*i)->getId()));
        //ui->comboBox_del_ID->addItem(QString::number((*i)->getId()));
        //ui->comboBox_draw_ID->addItem(QString::number((*i)->getId()));
    }
}

//=============== MINI PARSERS =====================//

//   Parses index to select shape for current tab
void MainWindow::comboBoxBaseShape(int index, base& curShape){
    switch(index){
    case 0:
        curShape = baseSelect;
        break;

    //  Line selection
    case 1:
    case 2:
        curShape = baseLine;
        break;

    //  2D shape selection
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        curShape = base2D;
        break;

    //  Text selection
    case 8:
        curShape = baseText;
        break;

    default:
        break;
    }
}

int parsePenColor(int constant){
    switch(constant){
    case Qt::white:
        return 1;
    case Qt::black:
        return 2;
    case Qt::red:
        return 3;
    case Qt::green:
        return 4;
    case Qt::blue:
        return 5;
    case Qt::cyan:
        return 6;
    case Qt::magenta:
        return 7;
    case Qt::yellow:
        return 8;
    case Qt::gray:
        return 9;
    default:
        return 0;
    }
}

//================== ADD TAB =======================//

//  Update tab
void MainWindow::updateAddTab(){

    //  Hide All
    if(addCurShape == baseSelect){
        ui->stackedWidget_add_interface->hide();
    }


    //  Display all interface
    else{
        ui->stackedWidget_add_interface->show();
    }

    //  Show Pen
    if(addCurShape == baseLine || addCurShape == base2D){
        ui->stackedWidget_add_interface->setCurrentIndex(0);
    }

    //  Show Text
    else{
        ui->stackedWidget_add_interface->setCurrentIndex(1);
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

//  Change index
void MainWindow::on_combobox_add_shapeType_currentIndexChanged(int index)
{
    comboBoxBaseShape(index, addCurShape);
    updateAddTab();
}

//=================== MOD TAB ========================//

//  Update Mod Tab
void MainWindow::updateModTab(){
    //  Hide All
    if(modCurShape == baseSelect){
        ui->stackedWidget_mod_interface->hide();
        ui->label_mod_shapeType->hide();
        ui->combobox_mod_shapeType->hide();
        ui->label_mod_anchor->hide();
        ui->widget_mod_location->hide();
    }

    //  Display all interface
    else{
        ui->stackedWidget_mod_interface->show();
        ui->label_mod_shapeType->show();
        ui->combobox_mod_shapeType->show();
        ui->label_mod_anchor->show();
        ui->widget_mod_location->show();
    }

    //  Show Pen
    if(modCurShape == baseLine || modCurShape == base2D){
        ui->stackedWidget_mod_interface->setCurrentIndex(0);
    }

    //  Show Text
    else{
        ui->stackedWidget_mod_interface->setCurrentIndex(1);
    }

    //  Brush
    if(modCurShape == base2D){
        ui->widget_mod_brush->show();
    }

    //  No Brush
    else{
        ui->widget_mod_brush->hide();
    }
}

//  Change selected shape
void MainWindow::on_comboBox_mod_ID_currentIndexChanged(int index)
{
    int val = 0, color = 0;
    if(index > 0){
        val = (*pShapeVector)[index - 1]->getShapeType();
        ui->combobox_mod_shapeType->setCurrentIndex(++val);

    }

    //  Update shape type & menus
    comboBoxBaseShape(val, modCurShape);

    //  ALL INTERNAL VALUE UPDATES

    //  Update menu displays
    updateModTab();
}

