#include "about.h"
#include "ui_about.h"

//! about constructor - requires a Qwidgit to draw on
//!
//! \author richard (5/13/18)
//!
//! \param parent 
about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

//! about destructor - release space
//!
//! \author richard (5/13/18)
about::~about()
{
    delete ui;
}
