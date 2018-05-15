#ifndef REPORTS_H
#define REPORTS_H

#include "vector.h"
#include "shape.h"
#include <QWidget>

using namespace nserkkvector;
namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = 0, int sort = 0);

    void mouseMoveEvent(QMouseEvent *event);
    void setSort(int val);
    void setVector(MyVector<Shape*> *temp);
    void show();
    ~reports();

private slots:
    void on_pushButton_report_exit_clicked();
    void on_comboBox_report_sort_currentIndexChanged(int index);

private:
    Ui::reports *ui;
    int sorter;
    MyVector<Shape*> *pShapeVector;
};

#endif // REPORTS_H
