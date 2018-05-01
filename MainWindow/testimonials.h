#ifndef TESTIMONIALS_H
#define TESTIMONIALS_H

#include <QWidget>

namespace Ui {
class testimonials;
}

class testimonials : public QWidget
{
    Q_OBJECT

public:
    explicit testimonials(QWidget *parent = 0);
    ~testimonials();

private slots:
    void on_submit_button_clicked();

private:
    Ui::testimonials *ui;
};

#endif // TESTIMONIALS_H
