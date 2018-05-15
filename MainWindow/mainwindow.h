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
    enum base{baseSelect, baseLine, base2D, baseText}
             modCurShape, addCurShape;

    explicit MainWindow(QWidget *parent = 0);

    //========== IMPORTANT FUNCTIONS ==========/

    //  Overloaded showEvent to load the window with menu prereqs
    void showEvent(QShowEvent *event);

    //  Passes vector from main into here
    void setVector(MyVector<Shape*> *temp);

    //  Reloads the vector into comboBoxes in the mainwindow
    void reloadVector();

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

    //  Text
    Qt::AlignmentFlag parseTextAlignmentVector(int index);


    //=============== UPDATERS ==================//
    //  Recreate menus in ADD TAB
    void updateAddTab();

    //  Recreate menus in MOD TAB
    void updateModTab();

    ~MainWindow();

private slots:

    //================ MULTIPLICATION ===========//
    void on_actionFeedback_triggered();
    void on_actionAbout_triggered();
    void on_actionContact_Us_triggered();
    void on_actionSort_by_ID_triggered();

    //============== TAB_SELECTIONS ==============//

    //  Change current menus in ADD TAB
    void on_combobox_add_shapeType_currentIndexChanged(int index);
    void on_comboBox_mod_ID_currentIndexChanged(int index);

    void on_pushButton_mod_submit_clicked();

private:
    Ui::MainWindow *ui;
    testimonials *Testimonials;
    about *About;
    contact *Contact;
    reports *Reports;
    MyVector<Shape*> *pShapeVector;
};

#endif // MAINWINDOW_H
