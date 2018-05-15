#include "reports.h"
#include "ui_reports.h"
#include "shape.h"
#include "vector.h"
#include "selection_sort.h"
#include <QMouseEvent>

reports::reports(QWidget *parent, int sort) :
    QWidget(parent),
    ui(new Ui::reports),
    sorter(sort)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->comboBox_report_sort->setCurrentIndex(sorter);
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
}

//  Moves window
void reports::mouseMoveEvent(QMouseEvent *event){
    QPoint mousePos = event->pos();

    //  FIX
    this->move(mousePos.x(), mousePos.y());
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

//  Change sort type
void reports::on_comboBox_report_sort_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);

    switch(index){
        case 0:
        ui->tableWidget_report_ID->setColumnCount(4);
        ui->tableWidget_report_ID->setRowCount(pShapeVector->size());
        ui->tableWidget_report_ID->setHorizontalHeaderItem()


    }
    ui->tableWidget_report_ID->setRowCount(0);
    ui->tableWidget_report_perimeter->setRowCount(0);
    ui->tableWidget_report_area->setRowCount(0);


}
