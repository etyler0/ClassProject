#ifndef PRIVILEGE_H
#define PRIVILEGE_H
#include <QtCore>

class privilege: public QObject{

private:
    int access;

public:
    privilege(int access = 0):access(access){}
    bool isAdmin()const{return access == 2;}
    bool isGuest()const{return access > 0;}
    void setAccess(int acc){access = acc;}
};

#endif // PRIVILEGE_H
