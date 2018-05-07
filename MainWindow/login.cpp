#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

//  Helper Function "confirmUser"
//      - Confirms if user and password is a matching pair in file
//  Return 0: Invalid User
//  Return 1: Guest User
//  Return 2: Administrative User
int login::confirmUser(QString username, QString password){

    //  HomePath allows access to the current folder on any computer
    QString homePath = QFileInfo(".").absolutePath();
    QString textPath = "/MainWindow/TextFiles/users.txt";

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


//  Helper Function "addUser"
//     - Checks if there are any duplicate usernames in file
//     - Appends user information into the file
//  Return 0: No file found
//  Return 1: Duplicate username, have user re-enter
//  Return 2: Pass or Valid
int login::addUser(QString username, QString password, int accessLevel){

    QString homePath = QFileInfo(".").absolutePath();
    QString textPath = "/MainWindow/TextFiles/users.txt";
    QFile file(homePath + textPath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "!!!", "Missing User Data");
        return 0;
    }

    QTextStream in(&file);
    QString user, pass;
    int level;

    while(!in.atEnd()){

        //  Load input from the file
        in >> user >> pass >> level;

        //  If duplicate username
        if(username == user){
            return 1;
        }
    }
    file.close();

    //  If no duplicates, reopen to append new data to file
    file.open(QFile::WriteOnly | QFile::Append);

    QTextStream out(&file);
    out << username << " " << password << " " << accessLevel << endl;
    file.close();
    return 2;
}

//  Interface Function "pushButton_login_clicked"
//      - Used to confirm if existing user inside users.txt
//      - Passes privilege object auth to the primary class
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
        auth.setAccess(access);
        this->close();
        break;

    //  Must pass an admin class
    case 2:
        QMessageBox::information(this, "Login", "Welcome admin!");
        auth.setAccess(access);
        this->close();
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
    int checkIn = addUser(username, password, access);

    if(password.length() < 8){
        QMessageBox::warning(this, "Error", "Password is too short!");
    }
    else if(username.length() < 1){
        QMessageBox::warning(this, "Error", "Enter a username!");
    }
    else if(checkIn == 2){
        QMessageBox::information(this, "Add User", "Log in with your user and pass!");
        auth.setAccess(access);
    }
    else if(checkIn == 1){
        QMessageBox::warning(this, "Error", "Username is already taken!");
    }
}
