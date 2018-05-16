#include "reports.h"
#include "ui_reports.h"
#include "shape.h"
#include "vector.h"
#include "selection_sort.h"
#include <QMouseEvent>
#include <QTableWidgetItem>

reports::reports(QWidget *parent, int sort) :
    QWidget(parent, Qt::FramelessWindowHint),
    ui(new Ui::reports),
    sorter(sort)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

//  Destructor
reports::~reports()
{
    delete ui;
}

//  Overloaded show function
void reports::show(){
    QWidget::show();
    ui->comboBox_report_sort->setCurrentIndex(sorter);
    ui->tableWidget_report_ID->setColumnCount(4);
    ui->tableWidget_report_area->setColumnCount(3);
    ui->tableWidget_report_perimeter->setColumnCount(3);

    //  Creates the headers
    QStringList HeaderID, HeaderPerimeter, HeaderArea;

    HeaderID.append("ID");
    HeaderID.append("Shape Type");
    HeaderID.append("Area");
    HeaderID.append("Perimeter");

    HeaderPerimeter.append("ID");
    HeaderPerimeter.append("Shape Type");
    HeaderPerimeter.append("Perimeter");

    HeaderArea.append("ID");
    HeaderArea.append("Shape Type");
    HeaderArea.append("Perimeter");

    //  Sets the headers
    ui->tableWidget_report_ID->setHorizontalHeaderLabels(HeaderID);
    ui->tableWidget_report_perimeter->setHorizontalHeaderLabels(HeaderPerimeter);
    ui->tableWidget_report_area->setHorizontalHeaderLabels(HeaderArea);

    //  Displays the combobox
    on_comboBox_report_sort_currentIndexChanged(sorter);

    //ui->tableWidget_report_ID->setHorizontalHeaderItem(0, );
}

QString reports::shapeToString(int shape){
    switch(shape){
    case 0:
        return "Line";
    case 1:
        return "PolyLine";
    case 2:
        return "Polygon";
    case 3:
        return "Rectangle";
    case 4:
        return "Square";
    case 5:
        return "Ellipse";
    case 6:
        return "Circle";
    case 7:
        return "Text";
    default:
        return "Line";
    }
}

//  Mouse Move
void reports::mouseMoveEvent(QMouseEvent *event){

    //  FIX
    if(isMouseDown == true){
        mousePoint = event->globalPos();
        this->move(mousePoint);
    }
}

//  Mouse Press
void reports::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        isMouseDown = true;
    }
}

//  Mouse Release
void reports::mouseReleaseEvent(QMouseEvent *event){
    isMouseDown = false;
}

//  Changes current sort value
void reports::setSort(int val){
    sorter = val;
}

void reports::setVector(MyVector<Shape*> *temp){
    pShapeVector = temp;
}

//  Closes window
void reports::on_pushButton_report_exit_clicked()
{
    this->close();
}

//  Loads report based on current selected index
void reports::on_comboBox_report_sort_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    int row = 0;

    switch(index){

    //  Handles report_ID
    case 0:
        ui->tableWidget_report_ID->setRowCount(pShapeVector->size());
        nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_id());
        for(MyVector<Shape *>::iterator i = pShapeVector->begin(); i != pShapeVector->end(); ++i, ++row){
            QString id = QString::number((*i)->getId());
            QString type = shapeToString((*i)->getShapeType());
            QString perimeter = QString::number((*i)->calcPerimeter());
            QString area = QString::number((*i)->calcArea());

            ui->tableWidget_report_ID->setItem(row, 0, new QTableWidgetItem(id));
            ui->tableWidget_report_ID->setItem(row, 1, new QTableWidgetItem(type));
            ui->tableWidget_report_ID->setItem(row, 2, new QTableWidgetItem(perimeter));
            ui->tableWidget_report_ID->setItem(row, 3, new QTableWidgetItem(area));
        }

        break;

    case 1:
        ui->tableWidget_report_perimeter->setRowCount(pShapeVector->size());
        nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_perimeter());

        for(MyVector<Shape *>::iterator i = pShapeVector->begin(); i != pShapeVector->end(); ++i, ++row){
            QString id = QString::number((*i)->getId());
            QString type = shapeToString((*i)->getShapeType());
            QString perimeter = QString::number((*i)->calcPerimeter());

            ui->tableWidget_report_perimeter->setItem(row, 0, new QTableWidgetItem(id));
            ui->tableWidget_report_perimeter->setItem(row, 1, new QTableWidgetItem(type));
            ui->tableWidget_report_perimeter->setItem(row, 2, new QTableWidgetItem(perimeter));
        }

        break;

    case 2:
        ui->tableWidget_report_area->setRowCount(pShapeVector->size());
        nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_area());

        for(MyVector<Shape *>::iterator i = pShapeVector->begin(); i != pShapeVector->end(); ++i, ++row){
            QString id = QString::number((*i)->getId());
            QString type = shapeToString((*i)->getShapeType());
            QString area = QString::number((*i)->calcArea());

            ui->tableWidget_report_area->setItem(row, 0, new QTableWidgetItem(id));
            ui->tableWidget_report_area->setItem(row, 1, new QTableWidgetItem(type));
            ui->tableWidget_report_area->setItem(row, 2, new QTableWidgetItem(area));
        }
        break;

    }
}

