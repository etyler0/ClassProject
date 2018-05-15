#include "reports.h"
#include "ui_reports.h"

reports::reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reports)
{
    ui->setupUi(this);
    setMouseTracking(true);
    //  Implement drag and move
}

reports::~reports()
{
    delete ui;
}
