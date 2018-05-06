#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "privilege.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(privilege& user, QWidget *parent = 0);
    int confirmUser(QString username, QString password);
    bool addUser(QString username, QString password, int accessLevel);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_addUser_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
