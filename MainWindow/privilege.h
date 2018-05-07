#ifndef PRIVILEGE_H
#define PRIVILEGE_H
#include <QtCore>
#include <QDebug>

class privilege: public QObject{

private:
    int access;

public:
    privilege(int access = 0):access(access){}
    bool isAdmin()const{return access == 2;}
    bool isGuest()const{return access > 0;}
    int getAccess()const{return access; }
    void setAccess(int acc){access = acc;}

    //  Optional debugging to see if values have passed
    //  void showAccess()const{qDebug() << "MY ACCESS LEVEL IS: " << access << endl; }
};

#endif // PRIVILEGE_H
