#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "testimonials.h"
#include "about.h"
#include "contact.h"
#include "privilege.h"

extern privilege auth;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionFeedback_triggered();

    void on_actionAbout_triggered();

    void on_actionContact_Us_triggered();

private:
    Ui::MainWindow *ui;
    testimonials *Testimonials;
    about *About;
    contact *Contact;
};

#endif // MAINWINDOW_H
