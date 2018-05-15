#include "reports.h"
#include "ui_reports.h"
#include <QMouseEvent>

reports::reports(QWidget *parent, int sort) :
    QWidget(parent),
    ui(new Ui::reports)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->comboBox_report_sort->setCurrentIndex(sort);
}

//  Destructor
reports::~reports()
{
    delete ui;
}

//  Moves window
void reports::mouseMoveEvent(QMouseEvent *event){
    QPoint mousePos = event->pos();

    //  FIX
    this->move(mousePos.x(), mousePos.y());
}

//  Closes window
void reports::on_pushButton_report_exit_clicked()
{
    this->close();
}

//  Change sort type
void reports::on_comboBox_report_sort_currentIndexChanged(int index)
{
    ui->tableWidget_report_ID->clear();
}
