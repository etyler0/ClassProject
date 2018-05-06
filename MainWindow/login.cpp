#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QDir>

login::login(privilege& user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

//  Confirms if user is valid:
//      Returns 0 if invalid user
//      Returns 1 if a guest
//      Returns 2 if has admin privileges
int login::confirmUser(QString username, QString password){

    //  HomePath allows access to the current folder on any computer
    QString homePath = QFileInfo(".").absolutePath();
    QString textPath = "/TextFiles/users.txt";

    QFile file(homePath + textPath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, ":C", "No File Found!!!");
    }

    QTextStream in (&file);
    QString user, pass;
    int level;

    while(!in.atEnd()){

        //  Load input from the file
        in >> user >> pass >> level;

        //  Check along the way, if found, close file and return access level
        if(username == user && password == pass){
            file.close();
            return level;
        }
    }

    //  close and return false if no matching values
    file.close();
    return 0;
}


//  Helper Function
bool login::addUser(QString username, QString password, int accessLevel){

    QString homePath = QFileInfo(".").absolutePath();
    QString textPath = "/TextFiles/users.txt";
    QFile file(homePath + textPath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, ":C", "No File Found!!!");
    }

    QTextStream in(&file);
    QString user, pass;
    int level;

    while(!in.atEnd()){

        //  Load input from the file
        in >> user >> pass >> level;

        //  If duplicate username
        if(username == user){
            return false;
        }
    }
    file.close();

    //  If no duplicates, reopen to append new data to file
    if(!file.open(QFile::WriteOnly | QFile::Append)){
        QMessageBox::warning(this, ":C", "No File Found!!!");
    }

    QTextStream out(&file);
    out << username << " " << password << " " << accessLevel << endl;
    file.close();
    return true;
}


//  Pass param here
void login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    int access = confirmUser(username, password);

    switch(access){
    case 0:
        QMessageBox::information(this, "Login", "Invalid username or password");
        break;

    //  Must pass a guest class
    case 1:
        QMessageBox::information(this, "Login", "Welcome guest user!");
        break;

    //  Must pass an admin class
    case 2:
        QMessageBox::information(this, "Login", "Welcome admin!");
        break;

    default:
        QMessageBox::warning(this, "Error!", "You broke the program?");
        break;
    }
}

void login::on_pushButton_addUser_clicked()
{
    QString username = ui->lineEdit_addUser->text();
    QString password = ui->lineEdit_addPass->text();
    int access = ui->checkBox_admin->isChecked() + 1;

    if(password.length() < 8){
        QMessageBox::warning(this, "Error", "Password is too short!");
    }
    else if(username.length() < 1){
        QMessageBox::warning(this, "Error", "Enter a username!");
    }
    else if(addUser(username, password, access)){
        QMessageBox::information(this, "Add User", "Log in with your user and pass!");
    }
    else{
        QMessageBox::warning(this, "Error", "Username is already taken!");
    }
}
