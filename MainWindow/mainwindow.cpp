#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include "shape.h"
#include "shape2d.h"
#include <QComboBox>
#include <QAbstractItemView>
#include <QDebug>
using namespace nserkkvector;

//=============== DEFAULT CLASS ===================//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Testimonials(nullptr),
    About(nullptr),
    Contact(nullptr),
    Reports(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if(Testimonials)    delete Testimonials;
    if(About)           delete About;
    if(Contact)         delete Contact;
    if(Reports)         delete Reports;
    delete ui;
}

//================ WINDOW DISPLAYS ===================//
void MainWindow::on_actionFeedback_triggered()
{
    if(!Testimonials)   Testimonials = new testimonials(this);
    Testimonials->show();
}

void MainWindow::on_actionAbout_triggered()
{
    if(!About)  About = new about(this);
    About->show();
}

void MainWindow::on_actionContact_Us_triggered()
{
    if(!Contact)    Contact = new contact(this);
    Contact->show();
}

void MainWindow::on_actionSort_by_ID_triggered()
{
    if(!Reports)    Reports = new reports(this);
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

//  Transforms qt constant/enum for pen color to match combobox
int MainWindow::parsePenColor(QColor color){
    if(color.name() == "#ffffff") return 0;     //  WHITE
    if(color.name() == "#000000") return 1;     //  BLACK
    if(color.name() == "#ff0000") return 2;     //  RED
    if(color.name() == "#008000") return 3;     //  GREEN
    if(color.name() == "#0000ff") return 4;     //  BLUE
    if(color.name() == "#00ffff") return 5;     //  CYAN
    if(color.name() == "#ff00ff") return 6;     //  MAGENTA
    if(color.name() == "#ffff00") return 7;     //  YELLOW
    if(color.name() == "#808080") return 8;     //  GRAY
    return 0;                                   //  DEFAULT IF NONE
}

int MainWindow::parsePenStyle(int counter){
    if(counter == Qt::NoPen)            return 0;   //  NO PEN
    if(counter == Qt::SolidLine)        return 1;   //  SOLID LINE
    if(counter == Qt::DashLine)         return 2;   //  DASH LINE
    if(counter == Qt::DotLine)          return 3;   //  DOT LINE
    if(counter == Qt::DashDotLine)      return 4;   //  DASH DOT LINE
    if(counter == Qt::DashDotDotLine)   return 5;   //  DASH DOT DOT LINE
    return 0;                                       //  DEFAULT IF NONE
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
    int val = 0;

    //  Update current combobox of shape type
    if(index > 0){
        val = (*pShapeVector)[index - 1]->getShapeType();
        ui->combobox_mod_shapeType->setCurrentIndex(++val);

    }

    //  Update shape type & menus
    comboBoxBaseShape(val, modCurShape);

    //  ALL INTERNAL VALUE UPDATES

    /*********** 2D Shape internal values ***************/
    if(modCurShape == base2D){
        Shape2D* temp = dynamic_cast<Shape2D*>((*pShapeVector)[index - 1]);

        //  Parses pen color to the combobox
        int penColor_index = parsePenColor(temp->pen.color());
        ui->comboBox_mod_penColor->setCurrentIndex(penColor_index);

        //  Sets pen width value
        ui->spinBox_mod_penWidth->setValue(temp->pen.width());

        //  Parses pen style to the combobox
        int penStyle_index = parsePenStyle(temp->pen.style());
        ui->comboBox_mod_penStyle->setCurrentIndex(penStyle_index);

        //


    }

    //  Update menu displays
    updateModTab();
}

