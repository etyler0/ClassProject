/*******************************************
 * Pre-processor directives
 *******************************************/
// Header files to include
#include "testimonials.h"
#include "ui_testimonials.h"

// Qt libraries/directives that will be utilized
#include <QFile>        // Gives access to QFile, allows modifying and reading files
#include <QTextStream>  // Gives access to QTextStream, allows streaming of string literals from or to files
#include <QMessageBox>  // Gives access to QMessageBox, allows displaying info to users
#include <QDir>         // Gives access to QDir, allows generic directory access across different computers
#include <QDebug>       // Gives access to QDebug, allows for debugging on the application output

//! testimonials constructor - requires a QWidget to draw on
//!
//! \author richard (5/14/18)
//!
//! \param parent 
testimonials::testimonials(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testimonials)
{
    ui->setupUi(this);
}

//! testimonials destructor - release allocated space
//!
//! \author richard (5/14/18)
testimonials::~testimonials()
{
    delete ui;
}

//! showEvent - make changes to window visible immediately - Overlaods QWidgit
//! //!       - Calls previous showEvent, and ALSO updateTestimonie
//!
//! \author richard (5/14/18)
//!
//! \param event 
void testimonials::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    updateTestimonies();
}

//! updateTestimonies - Reads input from file and parses it to display as testimonial
//!
//! \author richard (5/14/18)
void testimonials::updateTestimonies(){
    QString homePath = QFileInfo(".").absolutePath();
    QString textPath = "/MainWindow/testimonials.txt";
    QString divider = "*@791728$@(!*@492!@*42";

    QFile file(homePath + textPath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error!", "Failed to open testimonials!");
    }

    QTextStream in(&file);

    //  Resets textBrowser every time we update (is there a more efficient method?)
    ui->textBrowser->setPlainText("");

    //  Grabs the starting location to place the anchor back after inputting file stuff
    QPoint start(ui->textBrowser->pos());

    //  Traverse the file
    while(!in.atEnd()){

        //  Append the name
        ui->textBrowser->setFontWeight(100);
        ui->textBrowser->append(in.readLine() + " says:");

        QString curLine = in.readLine();

        while(curLine != divider){
            ui->textBrowser->setFontWeight(40);
            ui->textBrowser->append("  " + curLine);
            curLine = in.readLine();
        }

        ui->textBrowser->append("\n");
    }

    ui->textBrowser->anchorAt(start);
}

//  Interface Function "submit_button_clicked"
//      - Used to submit info to a text file
//      - Checks if there is input in all fields
//      - Adds a divider into the text file in case of multiline testimonies

//! on_submit_button_clicked - adds user entered data to a text file
//!                  - Checks if there is input in all fields
//!                  - Adds a divider into the text file in case of multiline testimonies
//!
//! \author richard (5/14/18)
void testimonials::on_submit_button_clicked()
{
    QString homePath = QFileInfo(".").absolutePath();
    QString textPath = "/MainWindow/testimonials.txt";
    QString divider = "*@791728$@(!*@492!@*42";

    //  Uncomment for debugging purposes
    //  QMessageBox::information(this, "File Path", homePath + "/ClassProject-master_2.0/TextFiles/testimonials.txt");

    QFile file(homePath + textPath);
    if(!file.open(QFile::WriteOnly | QFile::Append)){
        QMessageBox::warning(this, "Error!", "Failed to open testimonials!");
    }

    QTextStream out(&file);
    QString name = ui->lineEdit_name->text();
    QString text = ui->textEdit_testimonials->toPlainText();
    ui->textEdit_testimonials->setPlainText("");

    //  No name, warn user
    if(name.length() < 1){
        QMessageBox::warning(this, "Error!", "You need to put a name!");
    }

    //  No testimony, warn user
    else if(text.length() < 1){
        QMessageBox::warning(this, "Error!", "You need to write a testimony!");
    }

    //  Valid and passed, save input to file
    else{
        out << name << endl << text << endl << divider << endl;
    }
    file.close();
}

//! on_pushButton_exit_clicked - exits testimonials window
//!
//! \author richard (5/14/18)
void testimonials::on_pushButton_exit_clicked()
{
    this->close();
}

//! on_pushButton_exit_2_clicked - exits testimonials window
//!
//! \author richard (5/14/18)
void testimonials::on_pushButton_exit_2_clicked()
{
    this->close();
}
