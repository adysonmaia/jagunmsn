/****************************************************************************
** Meta object code from reading C++ file 'jagunwindow.h'
**
** Created: Sun May 31 19:43:47 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      33,   13,   12,   12, 0x05,
      81,   66,   12,   12, 0x05,
     146,  108,   12,   12, 0x05,
     214,  200,   12,   12, 0x05,
     268,  249,   12,   12, 0x05,
     316,  305,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     349,   12,   12,   12, 0x08,
     372,   12,   12,   12, 0x08,
     393,   12,   12,   12, 0x08,
     411,   12,   12,   12, 0x08,
     438,  431,   12,   12, 0x08,
     473,  465,   12,   12, 0x08,
     511,   12,   12,   12, 0x08,
     531,   12,   12,   12, 0x08,
     557,  548,   12,   12, 0x08,
     596,  581,   12,   12, 0x08,
     650,  620,   12,   12, 0x08,
     696,  548,   12,   12, 0x08,
     727,  722,   12,   12, 0x08,
     747,   12,   12,   12, 0x08,
     769,  764,   12,   12, 0x08,
     802,   12,   12,   12, 0x08,
     828,   12,   12,   12, 0x08,
     848,   12,   12,   12, 0x08,
     857,   12,   12,   12, 0x08,
     871,  200,   12,   12, 0x08,
     922,  906,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JagunWindow[] = {
    "JagunWindow\0\0user,password,email\0"
    "newUser(QString,QString,QString)\0"
    "login,password\0loginUser(QString,QString)\0"
    "nickname,message,image,status,sendToo\0"
    "changeStatus(QString,QString,QString,int,QStringList)\0"
    "login,message\0addContactRequest(QString,QString)\0"
    "login,confirmation\0"
    "addContactConfirmation(QString,bool)\0"
    "to,message\0sendMessage(QStringList,QString)\0"
    "changeToNewUserState()\0changeToLoginState()\0"
    "validateNewUser()\0validateLoginUser()\0"
    "action\0changeStatusUser(QAction*)\0"
    "contact\0changeStatusContact(JagunMSNContact*)\0"
    "serverNotResponse()\0successNewUser()\0"
    "errorStr\0failureNewUser(QString)\0"
    "icon,imageName\0newImage(QIcon,QString)\0"
    "nickname,message,image,status\0"
    "successloginUser(QString,QString,QString,int)\0"
    "failureLoginUser(QString)\0text\0"
    "filterUser(QString)\0addUserRequest()\0"
    "item\0openChatWindow(QListWidgetItem*)\0"
    "updateExibitionNameUser()\0updateMessageUser()\0"
    "logoff()\0timeoutAway()\0"
    "requestAddContact(QString,QString)\0"
    "from,to,message\0"
    "receiveMessage(QString,QStringList,QString)\0"
};

const QMetaObject JagunWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JagunWindow,
      qt_meta_data_JagunWindow, 0 }
};

const QMetaObject *JagunWindow::metaObject() const
{
    return &staticMetaObject;
}

void *JagunWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunWindow))
        return static_cast<void*>(const_cast< JagunWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JagunWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: loginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: changeStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5]))); break;
        case 3: addContactRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: addContactConfirmation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: sendMessage((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: changeToNewUserState(); break;
        case 7: changeToLoginState(); break;
        case 8: validateNewUser(); break;
        case 9: validateLoginUser(); break;
        case 10: changeStatusUser((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 11: changeStatusContact((*reinterpret_cast< JagunMSNContact*(*)>(_a[1]))); break;
        case 12: serverNotResponse(); break;
        case 13: successNewUser(); break;
        case 14: failureNewUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: newImage((*reinterpret_cast< QIcon(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: successloginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 17: failureLoginUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: filterUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: addUserRequest(); break;
        case 20: openChatWindow((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 21: updateExibitionNameUser(); break;
        case 22: updateMessageUser(); break;
        case 23: logoff(); break;
        case 24: timeoutAway(); break;
        case 25: requestAddContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: receiveMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void JagunWindow::newUser(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunWindow::loginUser(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JagunWindow::changeStatus(QString _t1, QString _t2, QString _t3, int _t4, QStringList _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JagunWindow::addContactRequest(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JagunWindow::addContactConfirmation(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JagunWindow::sendMessage(QStringList _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
