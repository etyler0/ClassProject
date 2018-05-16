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

//! reports - canvas area for reports
//!
//! \author richard (5/15/18)
class reports : public QWidget
{
    Q_OBJECT

public:
    //! constructor - craete an area to render the reports
    //!
    //! \author richard (5/15/18)
    //!
    //! \param parent 
    //! \param sort 
    explicit reports(QWidget *parent = 0, int sort = 0);

    //! setSort - set internal sorter member
    //!
    //! \author richard (5/15/18)
    //!
    //! \param val - sorter value
    void setSort(int val);

    //! setVector - set internal pointer to appwide MyVector<Shape>*
    //!
    //! \author richard (5/15/18)
    //!
    //! \param temp - MyVector<Shape>*
    void setVector(MyVector<Shape *> *temp);

    //! show - draw on canvas
    //!
    //! \author richard (5/15/18)
    void show();

    //! shapeToString - convert shapeType enum to string describing shape
    //!
    //! \author richard (5/15/18)
    //!
    //! \param shape - shape ID
    //!
    //! \return QString 
    QString shapeToString(int shape);

    //! Destuctor - deallocate local members
    //!
    //! \author edt (5/15/18)
    ~reports();

protected:
    //  Mouse events
    QPoint mousePoint; ///< current mouse location

    //! mousePressEvent - process a mouse click down event
    //!
    //! \author richard (5/15/18)
    //!
    //! \param event 
    void mousePressEvent(QMouseEvent *event);

    //! mouseReleaseEvent - process a mouse click release event
    //!
    //! \author richard (5/15/18)
    //!
    //! \param event 
    void mouseReleaseEvent(QMouseEvent *event);

    //! mousePressEvent - process a mouse move event
    //!
    //! \author edt (5/15/18)
    //!
    //! \param event 
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    //!on_pushButton_report_exit_clicked - process exit clicked event
    //!
    //! \author richard (5/15/18)
    void on_pushButton_report_exit_clicked();

    //! on_comboBox_report_sort_currentIndexChanged - - process event
    //!
    //! \author richard (5/15/18)
    //!
    //! \param index 
    void on_comboBox_report_sort_currentIndexChanged(int index);

private:
    Ui::reports *ui;
    int sorter;
    bool isMouseDown = false;
    MyVector<Shape*> *pShapeVector;
};

#endif // REPORTS_H
