/****************************************************************************
** Meta object code from reading C++ file 'jagunclientcontroller.h'
**
** Created: Sat May 2 21:18:43 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunclientcontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunclientcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunClientController[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      43,   22,   22,   22, 0x05,
      69,   60,   22,   22, 0x05,
     123,   93,   22,   22, 0x05,
     169,   60,   22,   22, 0x05,
     200,  195,   22,   22, 0x05,
     251,  237,   22,   22, 0x05,
     297,  286,   22,   22, 0x05,
     326,  286,   22,   22, 0x05,
     380,  364,   22,   22, 0x05,
     424,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     454,  433,   22,   22, 0x0a,
     502,  487,   22,   22, 0x0a,
     529,  237,   22,   22, 0x0a,
     595,  557,   22,   22, 0x0a,
     668,  649,   22,   22, 0x0a,
     716,  705,   22,   22, 0x0a,
     749,   22,   22,   22, 0x09,
     768,   22,   22,   22, 0x09,
     796,  790,   22,   22, 0x09,
     852,  841,   22,   22, 0x09,
     883,   60,   22,   22, 0x09,
     907,   22,   22,   22, 0x09,
     919,   22,   22,   22, 0x09,
     937,   22,   22,   22, 0x09,
     963,  958,   22,   22, 0x09,
     990,  790,   22,   22, 0x09,
    1064, 1028,   22,   22, 0x09,
    1107,   60,   22,   22, 0x09,
    1131, 1028,   22,   22, 0x09,
    1187, 1028,   22,   22, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunClientController[] = {
    "JagunClientController\0\0serverNotResponse()\0"
    "successNewUser()\0errorStr\0"
    "failureNewUser(QString)\0"
    "nickname,message,image,status\0"
    "successloginUser(QString,QString,QString,int)\0"
    "failureLoginUser(QString)\0list\0"
    "contactList(QList<JagunMSNContact*>)\0"
    "login,message\0requestAddContact(QString,QString)\0"
    "newContact\0newContact(JagunMSNContact*)\0"
    "contactChangeStatus(JagunMSNContact*)\0"
    "from,to,message\0"
    "receiveMessage(QString,QStringList,QString)\0"
    "logoff()\0login,password,email\0"
    "newUser(QString,QString,QString)\0"
    "login,password\0loginUser(QString,QString)\0"
    "addContact(QString,QString)\0"
    "nickname,message,image,status,sendToo\0"
    "changeStatus(QString,QString,QString,int,QStringList)\0"
    "login,confirmation\0"
    "addContactConfirmation(QString,bool)\0"
    "to,message\0sendMessage(QStringList,QString)\0"
    "connectedNewUser()\0disconnectedNewUser()\0"
    "error\0errorServerNewUser(JagunKET::EErrorJagunKET)\0"
    "login,date\0userCreated(QString,QDateTime)\0"
    "userNotCreated(QString)\0keepAlive()\0"
    "connectedServer()\0disconnectedServer()\0"
    "data\0receiveServer(QByteArray*)\0"
    "errorServer(JagunKET::EErrorJagunKET)\0"
    "login,nickname,message,image,status\0"
    "logOn(QString,QString,QString,QString,int)\0"
    "loginUserError(QString)\0"
    "approvedAddContact(QString,QString,QString,QString,int)\0"
    "changeStatusContact(QString,QString,QString,QString,int)\0"
};

const QMetaObject JagunClientController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunClientController,
      qt_meta_data_JagunClientController, 0 }
};

const QMetaObject *JagunClientController::metaObject() const
{
    return &staticMetaObject;
}

void *JagunClientController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunClientController))
        return static_cast<void*>(const_cast< JagunClientController*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunClientController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: serverNotResponse(); break;
        case 1: successNewUser(); break;
        case 2: failureNewUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: successloginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: failureLoginUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: contactList((*reinterpret_cast< QList<JagunMSNContact*>(*)>(_a[1]))); break;
        case 6: requestAddContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: newContact((*reinterpret_cast< JagunMSNContact*(*)>(_a[1]))); break;
        case 8: contactChangeStatus((*reinterpret_cast< JagunMSNContact*(*)>(_a[1]))); break;
        case 9: receiveMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: logoff(); break;
        case 11: newUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 12: loginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: addContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: changeStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5]))); break;
        case 15: addContactConfirmation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: sendMessage((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: connectedNewUser(); break;
        case 18: disconnectedNewUser(); break;
        case 19: errorServerNewUser((*reinterpret_cast< JagunKET::EErrorJagunKET(*)>(_a[1]))); break;
        case 20: userCreated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 21: userNotCreated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: keepAlive(); break;
        case 23: connectedServer(); break;
        case 24: disconnectedServer(); break;
        case 25: receiveServer((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 26: errorServer((*reinterpret_cast< JagunKET::EErrorJagunKET(*)>(_a[1]))); break;
        case 27: logOn((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 28: loginUserError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: approvedAddContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 30: changeStatusContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void JagunClientController::serverNotResponse()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void JagunClientController::successNewUser()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void JagunClientController::failureNewUser(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JagunClientController::successloginUser(QString _t1, QString _t2, QString _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JagunClientController::failureLoginUser(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JagunClientController::contactList(QList<JagunMSNContact*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JagunClientController::requestAddContact(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JagunClientController::newContact(JagunMSNContact * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void JagunClientController::contactChangeStatus(JagunMSNContact * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void JagunClientController::receiveMessage(QString _t1, QStringList _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void JagunClientController::logoff()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
