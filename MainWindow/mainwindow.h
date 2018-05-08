#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "testimonials.h"
#include "about.h"
#include "contact.h"
#include "reports.h"
#include "shape.h"
using namespace nserkkvector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setVector(MyVector<Shape*> *temp);
    //void updateAddTab();
    ~MainWindow();

private slots:
    void on_actionFeedback_triggered();

    void on_actionAbout_triggered();

    void on_actionContact_Us_triggered();

    void on_actionSort_by_ID_triggered();

    void on_combobox_add_shapetype_activated(int index);

private:
    Ui::MainWindow *ui;
    testimonials *Testimonials;
    about *About;
    contact *Contact;
    reports *Reports;
    MyVector<Shape*> *pShapeVector;
    enum{baseSelect, baseLine, base2D, baseText}addCurShape;
};

#endif // MAINWINDOW_H
