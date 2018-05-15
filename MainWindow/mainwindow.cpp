#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector.h"
#include "shape.h"
#include "shape2d.h"
#include "text.h"
#include "shape1d.h"
#include "selection_sort.h"
#include <QComboBox>
#include <QAbstractItemView>
#include <QDebug>
#include <QMessageBox>
using namespace nserkkvector;

//=============== DEFAULT CLASS ===================//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Testimonials(nullptr),
    About(nullptr),
    Contact(nullptr),
    Reports(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if(Testimonials)    delete Testimonials;
    if(About)           delete About;
    if(Contact)         delete Contact;
    if(Reports)         delete Reports;
    delete ui;
}

//================ WINDOW DISPLAYS ===================//
void MainWindow::on_actionFeedback_triggered()
{
    if(!Testimonials)   Testimonials = new testimonials(this);
    Testimonials->show();
}

void MainWindow::on_actionAbout_triggered()
{
    if(!About)  About = new about(this);
    About->show();
}

void MainWindow::on_actionContact_Us_triggered()
{
    if(!Contact)    Contact = new contact(this);
    Contact->show();
}

void MainWindow::on_actionSort_by_ID_triggered()
{
    if(!Reports){
        Reports = new reports(this, 0);
    }
    else{
        Reports->setSort(0);
    }
    Reports->show();
}

void MainWindow::on_actionSort_by_perimeter_triggered()
{
    if(!Reports){
        Reports = new reports(this, 1);
    }
    else{
        Reports->setSort(1);
    }
    Reports->show();
}

void MainWindow::on_actionSort_by_area_triggered()
{
    if(!Reports){
        Reports = new reports(this, 2);
    }
    else{
        Reports->setSort(2);
    }
    Reports->show();
}

//================ IMPORTANT FUNCTIONS ================//

//  Overloaded show event
void MainWindow::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    findShapeType(ui->combobox_add_shapeType->currentIndex(), addCurShape);
    findShapeType(ui->combobox_mod_shapeType->currentIndex(), modCurShape);
    findShapeType(ui->combobox_del_shapeType->currentIndex(), delCurShape);
    reloadVector();
    updateAddTab();
    updateModTab();
    updateDelTab();
}

//  Set vector from main
void MainWindow::setVector(MyVector<Shape*> *temp){
    pShapeVector = temp;
}

//  Reloads the vector into the combobox
void MainWindow::reloadVector(){
    nserkkselsort::selection_sort(pShapeVector->begin(), pShapeVector->end(), compare_shape_id());
    for(MyVector<Shape *>::iterator i = pShapeVector->begin(); i != pShapeVector->end(); ++i){
        ui->comboBox_mod_ID->addItem(QString::number((*i)->getId()));
        ui->comboBox_del_ID->addItem(QString::number((*i)->getId()));
        //ui->comboBox_draw_ID->addItem(QString::number((*i)->getId()));
    }
}

//  Resets the comboBoxes in the mainwindow
//  Call after any deletions or additions
void MainWindow::resetBoxes(){
    ui->comboBox_mod_ID->clear();
    ui->comboBox_del_ID->clear();
    ui->comboBox_mod_ID->addItem("-Empty-");
    ui->comboBox_del_ID->addItem("-Empty-");
    //ui->comboBox_draw_ID->clear();
}

//   Parses index to select shape for current tab
void MainWindow::findShapeType(int index, base& curShape){
    switch(index){
    case 0:
        curShape = baseSelect;
        break;

    //  Line selection
    case 1:
    case 2:
        curShape = baseLine;
        break;

    //  2D shape selection
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        curShape = base2D;
        break;

    //  Text selection
    case 8:
        curShape = baseText;
        break;

    default:
        break;
    }
}

//=============== UI PARSERS =====================//

//  Transforms qt constant/enum for colors to match combobox
int MainWindow::parseColorUI(QColor color){
    if(color.name() == "#ffffff") return 0;     //  WHITE
    if(color.name() == "#000000") return 1;     //  BLACK
    if(color.name() == "#ff0000") return 2;     //  RED
    if(color.name() == "#008000") return 3;     //  GREEN
    if(color.name() == "#0000ff") return 4;     //  BLUE
    if(color.name() == "#00ffff") return 5;     //  CYAN
    if(color.name() == "#ff00ff") return 6;     //  MAGENTA
    if(color.name() == "#ffff00") return 7;     //  YELLOW
    if(color.name() == "#808080") return 8;     //  GRAY
    return 0;                                   //  WHITE IF NONE
}

int MainWindow::parsePenStyleUI(int line){
    if(line == Qt::NoPen)            return 0;   //  NO PEN
    if(line == Qt::SolidLine)        return 1;   //  SOLID LINE
    if(line == Qt::DashLine)         return 2;   //  DASH LINE
    if(line == Qt::DotLine)          return 3;   //  DOT LINE
    if(line == Qt::DashDotLine)      return 4;   //  DASH DOT LINE
    if(line == Qt::DashDotDotLine)   return 5;   //  DASH DOT DOT LINE
    return 0;                                    //  NO PEN IF NONE
}

int MainWindow::parsePenCapStyleUI(int cap){
    if(cap == Qt::FlatCap)      return 0;   //  FLATCAP
    if(cap == Qt::SquareCap)    return 1;   //  SQUARECAP
    if(cap == Qt::RoundCap)     return 2;   //  ROUNDCAP
    return 0;                               //  FLATCAP IF NONE
}

int MainWindow::parsePenJoinStyleUI(int join){
    if(join == Qt::MiterJoin)    return 0;   //  MITERJOIN
    if(join == Qt::BevelJoin)    return 1;   //  BEVELJOIN
    if(join == Qt::RoundJoin)    return 2;   //  ROUNDJOIN
    return 0;                                //  MITERJOIN IF NONE
}

int MainWindow::parseBrushStyleUI(int brush){
    if(brush == Qt::SolidPattern)     return 0;   //  SOLID PATTERN
    if(brush == Qt::HorPattern)       return 1;   //  HORIZONTAL
    if(brush == Qt::VerPattern)       return 2;   //  VERTICAL
    if(brush == Qt::NoBrush)          return 3;   //  NO BRUSH
    return 0;                                     //  SOLID PATTERN IF NONE
}

int MainWindow::parseTextAlignmentUI(int align){
    if(align == Qt::AlignLeft)    return 0;   //  ALIGN LEFT
    if(align == Qt::AlignRight)   return 1;   //  ALIGN RIGHT
    if(align == Qt::AlignTop)     return 2;   //  ALIGN TOP
    if(align == Qt::AlignBottom)  return 3;   //  ALIGN BOTTOM
    if(align == Qt::AlignCenter)  return 4;   //  ALIGN CENTER
    return 0;                                 //  ALIGN LEFT IF NONE
}

int MainWindow::parseTextFontFamilyUI(QString family){
    if(family == "Comic Sans MS")     return 0;     //  COMICSANS
    if(family == "Courier")           return 1;     //  COURIER
    if(family == "Helvetica")         return 2;     //  HELV
    if(family == "Times")             return 3;     //  TIMES
    return 0;                                       //  COMICSANS IF NONE
}

int MainWindow::parseTextFontStyleUI(int style){
    if(style == QFont::StyleNormal)      return 0;  //  NORMAL
    if(style == QFont::StyleItalic)      return 1;  //  ITALIC
    if(style == QFont::StyleOblique)     return 2;  //  OBLIQUE
    return 0;                                       //  NORMAL IF NONE
}

int MainWindow::parseTextFontWeightUI(int weight){
    if(weight == QFont::Thin)   return 0;   //  THIN
    if(weight == QFont::Light)  return 1;   //  LIGHT
    if(weight == QFont::Normal) return 2;   //  NORMAL
    if(weight == QFont::Bold)   return 3;   //  BOLD
    return 0;                               //  THIN IF NONE
}

//================= VECTOR PARSERS =================//

QString MainWindow::parseColorVector(int index){
    if(index == 0)      return "#ffffff";       //  WHITE
    if(index == 1)      return "#000000";       //  BLACK
    if(index == 2)      return "#ff0000";       //  RED
    if(index == 3)      return "#008000";       //  GREEN
    if(index == 4)      return "#0000ff";       //  BLUE
    if(index == 5)      return "#00ffff";       //  CYAN
    if(index == 6)      return "#ff00ff";       //  MAGENTA
    if(index == 7)      return "#ffff00";       //  YELLOW
    if(index == 8)      return "#808000";       //  GRAY
    return 0;                                   //  WHITE IF NONE
}

Qt::GlobalColor MainWindow::parseColorEnumVector(int index){
    if(index == 0)      return Qt::white;       //  WHITE
    if(index == 1)      return Qt::black;       //  BLACK
    if(index == 2)      return Qt::red;         //  RED
    if(index == 3)      return Qt::green;       //  GREEN
    if(index == 4)      return Qt::blue;        //  BLUE
    if(index == 5)      return Qt::cyan;        //  CYAN
    if(index == 6)      return Qt::magenta;     //  MAGENTA
    if(index == 7)      return Qt::yellow;      //  YELLOW
    if(index == 8)      return Qt::gray;        //  GRAY
    return Qt::white;                           //  WHITE IF NONE
}

Qt::PenStyle MainWindow::parsePenStyleVector(int index){
    if(index == 0)      return Qt::NoPen;               //  NO PEN
    if(index == 1)      return Qt::SolidLine;           //  SOLID LINE
    if(index == 2)      return Qt::DashLine;            //  DASH LINE
    if(index == 3)      return Qt::DotLine;             //  DOT LINE
    if(index == 4)      return Qt::DashDotLine;         //  DASH DOT LINE
    if(index == 5)      return Qt::DashDotDotLine;      //  DASH DOT DOT LINE
    return Qt::NoPen;                                   //  NO PEN IF NONE
}

Qt::PenCapStyle MainWindow::parsePenCapStyleVector(int index){
    if(index == 0)      return Qt::FlatCap;     //  FLATCAP
    if(index == 1)      return Qt::SquareCap;   //  SQUARECAP
    if(index == 2)      return Qt::RoundCap;    //  ROUNDCAP
    return Qt::FlatCap;                         //  FLATCAP IF NONE
}

Qt::PenJoinStyle MainWindow::parsePenJoinStyleVector(int index){
    if(index == 0)      return Qt::MiterJoin;   //  MITERJOIN
    if(index == 1)      return Qt::BevelJoin;   //  BEVELJOIN
    if(index == 2)      return Qt::RoundJoin;   //  ROUNDJOIN
    return Qt::MiterJoin;                       //  MITERJOIN IF NONE
}

Qt::BrushStyle MainWindow::parseBrushStyleVector(int index){
    if(index == 0)      return Qt::SolidPattern;    //  SOLID PATTERN
    if(index == 1)      return Qt::HorPattern;      //  HORIZONTAL
    if(index == 2)      return Qt::VerPattern;      //  VERTICAL
    if(index == 3)      return Qt::NoBrush;         //  NO BRUSH
    return Qt::SolidPattern;                        //  SOLID PATTERN IF NONE
}

Qt::AlignmentFlag MainWindow::parseTextAlignmentVector(int index){
    if(index == 0)      return Qt::AlignLeft;   //  ALIGN LEFT
    if(index == 1)      return Qt::AlignRight;  //  ALIGN RIGHT
    if(index == 2)      return Qt::AlignTop;    //  ALIGN TOP
    if(index == 3)      return Qt::AlignBottom; //  ALIGN BOTTOM
    if(index == 4)      return Qt::AlignCenter; //  ALIGN CENTER
    return Qt::AlignLeft;                       //  ALIGN LEFT IF NONE
}

QString MainWindow::parseTextFontFamilyVector(int index){
    if(index == 0)  return "Comic Sans MS";     //  COMIC SANS
    if(index == 1)  return "Courier";           //  COURIER
    if(index == 2)  return "Helvetica";         //  HELV
    if(index == 3)  return "Times";             //  TIMES
    return "Comic Sans MS";                     //  COMIC SANS IF NONE
}

QFont::Style MainWindow::parseTextFontStyleVector(int index){
    if(index == 0)  return QFont::StyleNormal;  //  NORMAL
    if(index == 1)  return QFont::StyleItalic;  //  ITALIC
    if(index == 2)  return QFont::StyleOblique; //  OBLIQUE
    return QFont::StyleNormal;                  //  NORMAL IF NONE

}

QFont::Weight MainWindow::parseTextFontWeightVector(int index){
    if(index == 0)  return QFont::Thin;     //  THIN
    if(index == 1)  return QFont::Light;    //  LIGHT
    if(index == 2)  return QFont::Normal;   //  NORMAL
    if(index == 3)  return QFont::Bold;     //  BOLD
    return QFont::Thin;                     //  THIN IF NONE
}



//================== ADD TAB =======================//

//  Update tab
void MainWindow::updateAddTab(){

    //  Hide All
    if(addCurShape == baseSelect){
        ui->stackedWidget_add_interface->hide();
    }

    //  Display all interface
    else{
        ui->stackedWidget_add_interface->show();
    }

    //  Show Pen
    if(addCurShape == baseLine || addCurShape == base2D){
        ui->stackedWidget_add_interface->setCurrentIndex(0);
    }

    //  Show Text
    else{
        ui->stackedWidget_add_interface->setCurrentIndex(1);
    }

    //  Brush
    if(addCurShape == base2D){
        ui->widget_add_brush->show();
    }

    //  No Brush
    else{
        ui->widget_add_brush->hide();
    }
}

//  Change index
void MainWindow::on_combobox_add_shapeType_currentIndexChanged(int index)
{
    findShapeType(index, addCurShape);
    updateAddTab();
}

//=================== MOD TAB ========================//

//  Update Mod Tab
void MainWindow::updateModTab(){
    //  Hide All
    if(modCurShape == baseSelect){
        ui->stackedWidget_mod_interface->hide();
        ui->label_mod_shapeType->hide();
        ui->combobox_mod_shapeType->hide();
        ui->label_mod_anchor->hide();
        ui->widget_mod_location->hide();
        ui->pushButton_mod_submit->hide();
    }

    //  Display all interface
    else{
        ui->stackedWidget_mod_interface->show();
        ui->label_mod_shapeType->show();
        ui->combobox_mod_shapeType->show();
        ui->label_mod_anchor->show();
        ui->widget_mod_location->show();
        ui->pushButton_mod_submit->show();
    }

    //  Show Pen
    if(modCurShape == baseLine || modCurShape == base2D){
        ui->stackedWidget_mod_interface->setCurrentIndex(0);
    }

    //  Show Text
    else{
        ui->stackedWidget_mod_interface->setCurrentIndex(1);
    }

    //  Brush
    if(modCurShape == base2D){
        ui->widget_mod_brush->show();
    }

    //  No Brush
    else{
        ui->widget_mod_brush->hide();
    }
}

//  Change selected shape in mod tab
void MainWindow::on_comboBox_mod_ID_currentIndexChanged(int index)
{
    int val = 0;
    //  Update current combobox of shape type

    //  If not base select
    if(index > 0){
        val = (*pShapeVector)[index - 1]->getShapeType();
        ui->combobox_mod_shapeType->setCurrentIndex(++val);

        //  Update shape type & menus
        findShapeType(val, modCurShape);

        //  ALL INTERNAL VALUE UPDATES

        /************* Text Shape Internal Values ****************/
        if(modCurShape == baseText){

            //  Casts Shape to Text to use text functions
            Text* temp = static_cast<Text*>((*pShapeVector)[index - 1]);

            //  Sets lineEdit box to match text's String var
            ui->lineEdit_mod_textString->setText(temp->String);

            //  Parses text color to the combobox
            int textColor_index = parseColorUI(temp->Color);
            ui->comboBox_mod_textColor->setCurrentIndex(textColor_index);

            //  Parses text alignment to the combobox
            int textAlignment_index = parseTextAlignmentUI(temp->Alignment);
            ui->comboBox_mod_textAlignment->setCurrentIndex(textAlignment_index);

            //  Parses Font Size to the spinbox
            ui->spinBox_mod_textPointSize->setValue(temp->FontSize);

            //  Parses text font family to the combobox
            int textFontFamily_index = parseTextFontFamilyUI(temp->FontFamily);
            ui->comboBox_mod_textFontFamily->setCurrentIndex(textFontFamily_index);

            //  Parses text font style to the combobox
            int textFontStyle_index = parseTextFontStyleUI(temp->FontStyle);
            ui->comboBox_mod_textFontStyle->setCurrentIndex(textFontStyle_index);

            //  Parses text font weight to the combobox
            int textFontWeight_index = parseTextFontWeightUI(temp->FontWeight);
            ui->comboBox_mod_textFontWeight->setCurrentIndex(textFontWeight_index);

            //  Provides value for the anchor box
            ui->spinBox_X_mod->setValue(temp->upperleft.x());
            ui->spinBox_Y_mod->setValue(temp->upperleft.y());
        }

        /****************** 2D & 1D Shape internal values ******************/
        else{
            //  Casts shape to use Shape2D functions
            Shape2D* temp = static_cast<Shape2D*>((*pShapeVector)[index - 1]);

            //  Parses pen color to the combobox
            int penColor_index = parseColorUI(temp->pen.color());
            ui->comboBox_mod_penColor->setCurrentIndex(penColor_index);

            //  Sets pen width value
            ui->spinBox_mod_penWidth->setValue(temp->pen.width());

            //  Parses pen style to the combobox
            int penStyle_index = parsePenStyleUI(temp->pen.style());
            ui->comboBox_mod_penStyle->setCurrentIndex(penStyle_index);

            //  Parses pen cap style to the combobox
            int penCapStyle_index = parsePenCapStyleUI(temp->pen.capStyle());
            ui->comboBox_mod_penCapStyle->setCurrentIndex(penCapStyle_index);

            //  Parses pen join style to the combo box
            int penJoinStyle_index = parsePenJoinStyleUI(temp->pen.joinStyle());
            ui->comboBox_mod_penJoinStyle->setCurrentIndex(penJoinStyle_index);

            //  Provides value for the anchor box
            ui->spinBox_X_mod->setValue(temp->upperleft.x());
            ui->spinBox_Y_mod->setValue(temp->upperleft.y());

            /******** Brush Exclusive to 2D shapes *************/
            if(modCurShape == base2D){
                //  Parses brush color to the combobox
                int brushColor_index = parseColorUI(temp->brush.color());
                ui->comboBox_mod_brushColor->setCurrentIndex(brushColor_index);

                //  Parses brush style to the combobox
                int brushStyle_index = parseBrushStyleUI(temp->brush.style());
                ui->comboBox_mod_brushStyle->setCurrentIndex(brushStyle_index);
            }
        }
    }

    //  Handles non-selected ID
    else{

        //  Update shape type & menus
        findShapeType(val, modCurShape);
    }

    //  Update menu displays
    updateModTab();
}

//  Submit Mod Tab
void MainWindow::on_pushButton_mod_submit_clicked()
{
    //  Separate message for non-selection
    QMessageBox::information(this, "Update", "Shape is updated!");
    int index = ui->comboBox_mod_ID->currentIndex();

    /************* Text internal vector values ***************/
    if(modCurShape == baseText){

        //  Casts Shape to Text to apply text modifications
        Text* temp = static_cast<Text*>((*pShapeVector)[index - 1]);

        //  Sets text string to match lineEdit
        temp->String = ui->lineEdit_mod_textString->text();

        //  Changes current text color in vector
        int textColor_index = ui->comboBox_mod_textColor->currentIndex();
        Qt::GlobalColor textColor = parseColorEnumVector(textColor_index);
        temp->Color = QColor(textColor);

        //  Changes current text alignment in vector
        int textAlignment_index = ui->comboBox_mod_textAlignment->currentIndex();
        Qt::AlignmentFlag textAlignment = parseTextAlignmentVector(textAlignment_index);
        temp->Alignment = textAlignment;

        //  Changes current text point size in vector
        int textFontSize = ui->spinBox_mod_textPointSize->value();
        temp->FontSize = textFontSize;

        //  Changes current text font family in vector
        int textFontFamily_index = ui->comboBox_mod_textFontFamily->currentIndex();
        QString textFontFamily = parseTextFontFamilyVector(textFontFamily_index);
        temp->FontFamily = textFontFamily;

        //  Changes current text font style in vector
        int textFontStyle_index = ui->comboBox_mod_textFontStyle->currentIndex();
        QFont::Style textFontStyle = parseTextFontStyleVector(textFontStyle_index);
        temp->FontStyle = textFontStyle;

        //  Changes current text font weight in vector
        int textFontWeight_index = ui->comboBox_mod_textFontWeight->currentIndex();
        QFont::Weight textFontWeight = parseTextFontWeightVector(textFontWeight_index);
        temp->FontWeight = textFontWeight;

        //  Changes current text anchor in vector
        int x = ui->spinBox_X_mod->value();
        int y = ui->spinBox_Y_mod->value();
        QPoint newUpperLeft(x, y);
        temp->move(newUpperLeft);
    }

    /********* 2D and 1D Shape Internal Values ******************/
    else if(modCurShape == base2D || modCurShape == baseLine){

        //  Casts shape to base 2D
        Shape2D* temp = static_cast<Shape2D*>((*pShapeVector)[index - 1]);

        //  Changes current pen color in vector
        int penColor_index = ui->comboBox_mod_penColor->currentIndex();
        Qt::GlobalColor penColor = parseColorEnumVector(penColor_index);
        temp->pen.setColor(penColor);

        //  Changes pen width value in vector
        int penWidth = ui->spinBox_mod_penWidth->value();
        temp->pen.setWidth(penWidth);

        //  Changes pen style in vector
        int penStyle_index = ui->comboBox_mod_penStyle->currentIndex();
        Qt::PenStyle penStyle = parsePenStyleVector(penStyle_index);
        temp->pen.setStyle(penStyle);

        //  Changes pen cap style in vector
        int penCapStyle_index = ui->comboBox_mod_penCapStyle->currentIndex();
        Qt::PenCapStyle penCapStyle = parsePenCapStyleVector(penCapStyle_index);
        temp->pen.setCapStyle(penCapStyle);

        //  Changes pen join style in vector
        int penJoinStyle_index = ui->comboBox_mod_penJoinStyle->currentIndex();
        Qt::PenJoinStyle penJoinStyle = parsePenJoinStyleVector(penJoinStyle_index);
        temp->pen.setJoinStyle(penJoinStyle);

        /********* Brush Exclusive to 2D shapes *************/
        if(modCurShape == base2D){
            //  Changes to brush color in vector
            int brushColor_index = ui->comboBox_mod_brushColor->currentIndex();
            Qt::GlobalColor brushColor = parseColorEnumVector(brushColor_index);
            temp->brush.setColor(brushColor);

            //  Changes brush style in vector
            int brushStyle_index = ui->comboBox_mod_brushStyle->currentIndex();
            Qt::BrushStyle brushStyle = parseBrushStyleVector(brushStyle_index);
            temp->brush.setStyle(brushStyle);
        }
    }
}

//================ DEL TAB =========================//

//  Update delete tab contents
void MainWindow::updateDelTab(){
    if(delCurShape == baseSelect){
        ui->groupBox_del->hide();
    }
    else{
        ui->groupBox_del->show();
    }
}

//  Delete confirmation
void MainWindow::on_pushButton_del_clicked()
{
    QMessageBox::information(this, "Deletion", "Shape is removed!");
    int toDelete = ui->comboBox_del_ID->currentIndex();
    MyVector<Shape*>::iterator i;

    for(i = pShapeVector->begin(); toDelete > 1; --toDelete){
        ++i;
    }
    pShapeVector->erase(i);

    resetBoxes();
    reloadVector();

}

//  Change index
void MainWindow::on_comboBox_del_ID_currentIndexChanged(int index)
{
    int val = 0;
    if(index > 0){
        val = (*pShapeVector)[index-1]->getShapeType();
        ui->combobox_del_shapeType->setCurrentIndex(++val);
    }
    findShapeType(val, delCurShape);
    updateDelTab();
}

//================ RENDER TAB ========================//
