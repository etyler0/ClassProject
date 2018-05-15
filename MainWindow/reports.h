#ifndef REPORTS_H
#define REPORTS_H

#include "vector.h"
#include "shape.h"
#include <QWidget>
#include <QTableWidget>

using namespace nserkkvector;
namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = 0, int sort = 0);
    void setSort(int val);
    void setVector(MyVector<Shape*> *temp);
    void show();
    QString shapeToString(int shape);
    ~reports();

protected:
    //  Mouse events
    QPoint mousePoint;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_pushButton_report_exit_clicked();
    void on_comboBox_report_sort_currentIndexChanged(int index);

private:
    Ui::reports *ui;
    int sorter;
    bool isMouseDown = false;
    MyVector<Shape*> *pShapeVector;
};

#endif // REPORTS_H
