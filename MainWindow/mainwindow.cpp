#include "mainwindow.h"
#include "ui_mainwindow.h"

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
