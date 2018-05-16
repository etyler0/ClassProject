#ifndef CONTACT_H
#define CONTACT_H

#include <QDialog>

namespace Ui {
class contact;
}

//! Contact class - holds information for "Contact Us" dialog
//!
//! \author richard (5/13/18)
class contact : public QDialog
{
    Q_OBJECT

public:
    explicit contact(QWidget *parent = 0);
    ~contact();

private slots:
    void on_pushButton_clicked();

private:
    Ui::contact *ui;
};

#endif // CONTACT_H
