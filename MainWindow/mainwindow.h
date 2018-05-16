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

//! mainwindow - canvas area for application
//!
//! \author kevin (5/15/18)
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum base{baseSelect, baseLine, base2D, baseText}
             modCurShape, addCurShape, delCurShape; ///> types of objects to render

    //! constructor - create an area to render application objects
    //!
    //! \author kevin (5/15/18)
    //!
    //! \param parent 
    explicit MainWindow(QWidget *parent = 0);

    //========== IMPORTANT FUNCTIONS ==========/

    //! showEvent - load the window with menu prereqs
    //!
    //! \author kevin (5/15/18)
    //!
    //! \param event - QShowEvent *
    void showEvent(QShowEvent *event);

    //  Passes vector from main into here

    //! setVector - set internal pointer to appwide MyVector<Shape>*
    //!
    //! \author kevin (5/15/18)
    //!
    //! \param temp MyVector<Shape>*
    void setVector(MyVector<Shape *> *temp);

    //  Reloads the vector into comboBoxes in the mainwindow
    void reloadVector();

    //  Resets the comboBoxes in the mainwindow
    void resetBoxes();

    //  Adjusts currently selected shape to adjust menus for later
    void findShapeType(int index, base &curShape);

    //============ PARSE TO UI =======================//

    //  Multi-functional color parser
    int parseColorUI(QColor color);

    //  Pen & Brush
    int parsePenStyleUI(int line);
    int parsePenCapStyleUI(int cap);
    int parsePenJoinStyleUI(int join);
    int parseBrushStyleUI(int brush);

    //  Text
    int parseTextAlignmentUI(int align);
    int parseTextFontFamilyUI(QString family);
    int parseTextFontStyleUI(int style);
    int parseTextFontWeightUI(int weight);

    //============== PARSE TO VECTOR ================//

    //  Multi-functional color parser to vector
    QString parseColorVector(int index);
    Qt::GlobalColor parseColorEnumVector(int index);

    //  Pen & Brush
    Qt::PenStyle parsePenStyleVector(int index);
    Qt::PenCapStyle parsePenCapStyleVector(int index);
    Qt::PenJoinStyle parsePenJoinStyleVector(int index);
    Qt::BrushStyle parseBrushStyleVector(int index);

    //  Text
    Qt::AlignmentFlag parseTextAlignmentVector(int index);
    QString parseTextFontFamilyVector(int index);
    QFont::Style parseTextFontStyleVector(int index);
    QFont::Weight parseTextFontWeightVector(int index);

    //=============== UPDATERS ==================//
    //  Recreate menus in ADD TAB
    void updateAddTab(int index);

    //  Recreate menus in MOD TAB
    void updateModTab();

    //  Recreate elements in DEL TAB
    void updateDelTab();

    ~MainWindow();

private slots:

    //================ MULTIPLICATION ===========//
    void on_actionFeedback_triggered();
    void on_actionAbout_triggered();
    void on_actionContact_Us_triggered();
    void on_actionSort_by_ID_triggered();

    //============== TAB_SELECTIONS ==============//

    //  ADD TAB
    void on_combobox_add_shapeType_currentIndexChanged(int index);

    //  MOD TAB
    void on_comboBox_mod_ID_currentIndexChanged(int index);
    void on_pushButton_mod_submit_clicked();

    //  DEL TAB
    void on_pushButton_del_clicked();

    void on_comboBox_del_ID_currentIndexChanged(int index);

    //  REPORTS
    void on_actionSort_by_perimeter_triggered();
    void on_actionSort_by_area_triggered();
    void on_button_add_confirm_clicked();

    void on_pushButton_draw_single_clicked();

    void on_pushButton_draw_all_clicked();

    void on_pushButton_clear_all_clicked();

private:
    Ui::MainWindow *ui;
    testimonials *Testimonials;
    about *About;
    contact *Contact;
    reports *Reports;
    MyVector<Shape*> *pShapeVector;
};

#endif // MAINWINDOW_H
