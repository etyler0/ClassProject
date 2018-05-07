#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "privilege.h"

extern privilege auth;

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    int confirmUser(QString username, QString password);
    int addUser(QString username, QString password, int accessLevel);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_addUser_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
