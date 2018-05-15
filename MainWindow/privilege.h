#ifndef PRIVILEGE_H
#define PRIVILEGE_H
#include <QtCore>
#include <QDebug>

//! privilege class - manage user privileges
//!
//! \author richard (5/14/18)
class privilege: public QObject{

private:
    int access; ///< user access level

public:
    //! constructor - create instance for user
    //!
    //! \author richard (5/14/18)
    //!
    //! \param access - allowed access level
    privilege(int access = 0):access(access){}

    //! isAdmin - determine user level
    //!
    //! \author richard (5/14/18)
    //!
    //! \return bool - true if admin user
    bool isAdmin()const{return access == 2;}

    //! isUser - detemine user level
    //!
    //! \author richard (5/14/18)
    //!
    //! \return bool - true if regular user
    bool isUser()const{return access > 0;}

    //! getAccess - fetch access level
    //!
    //! \author richard (5/14/18)
    //!
    //! \return int - access level
    int getAccess()const{return access; }

    //! setAccess - store access level
    //!
    //! \author richard (5/14/18)
    //!
    //! \param acc - access level to store
    void setAccess(int acc) { access = acc;}

    //  Optional debugging to see if values have passed
    //  void showAccess()const{qDebug() << "MY ACCESS LEVEL IS: " << access << endl; }
};

#endif // PRIVILEGE_H
