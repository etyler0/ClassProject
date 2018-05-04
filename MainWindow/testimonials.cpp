#include "testimonials.h"
#include "ui_testimonials.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>

testimonials::testimonials(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testimonials)
{
    ui->setupUi(this);
}

testimonials::~testimonials()
{
    delete ui;
}

void testimonials::on_submit_button_clicked()
{
    QString homePath = QFileInfo(".").absolutePath();

    //  Uncomment for debugging purposes
    //  QMessageBox::information(this, "File Path", homePath + "/ClassProject-master_2.0/TextFiles/testimonials.txt");
    QFile file(homePath + "/ClassProject-master_2.0/TextFiles/testimonials.txt");
    if(!file.open(QFile::WriteOnly | QFile::Append)){
        QMessageBox::warning(this, "Error!", "Failed to open testimonials!");
    }

    QTextStream out(&file);
    QString name = ui->textEdit_name->toPlainText();
    QString text = ui->plainTextEdit_testimonial->toPlainText();
    ui->plainTextEdit_testimonial->setPlainText("");
    out << name << endl << text << endl;
    file.close();
}


void testimonials::on_verticalScrollBar_valueChanged(int value)
{
    ui->scrollArea->move(QPoint(0, value * 2));
}
