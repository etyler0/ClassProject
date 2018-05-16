#include "contact.h"
#include "ui_contact.h"
#include <QMessageBox>

//! contact constructor - requires a Qwidgit to draw on
//!
//! \author richard (5/13/18)
//!
//! \param parent 
contact::contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contact)
{
    ui->setupUi(this);
}

//! contact destructor - release space
//!
//! \author richard (5/13/18)
contact::~contact()
{
    delete ui;
}

void contact::on_pushButton_clicked()
{
    QMessageBox::information(this, "Saved", "We will carefully go over your submission, Thanks!");
}
