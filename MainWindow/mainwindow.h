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
    enum base{baseSelect, baseLine, base2D, baseText}addCurShape;
    explicit MainWindow(QWidget *parent = 0);
    void comboBoxBaseShape(int index, base &typeShape);
    void setVector(MyVector<Shape*> *temp);
    //void updateAddTab();
    ~MainWindow();

private slots:
    void on_actionFeedback_triggered();

    void on_actionAbout_triggered();

    void on_actionContact_Us_triggered();

    void on_actionSort_by_ID_triggered();

    void on_combobox_add_shapeType_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    testimonials *Testimonials;
    about *About;
    contact *Contact;
    reports *Reports;
    MyVector<Shape*> *pShapeVector;
};

#endif // MAINWINDOW_H
