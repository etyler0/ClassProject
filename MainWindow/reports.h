#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>

namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = 0, int sort = 0);
    void mouseMoveEvent(QMouseEvent *event);
    ~reports();

private slots:
    void on_pushButton_report_exit_clicked();
    void on_comboBox_report_sort_currentIndexChanged(int index);
    void setSort(int val);

private:
    Ui::reports *ui;
    int sorter;
};

#endif // REPORTS_H
