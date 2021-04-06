/****************************************************************************
** Meta object code from reading C++ file 'jagunparserfromxml.h'
**
** Created: Sat May 2 21:18:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunParser/jagunparserfromxml.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunparserfromxml.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunParserFromXML[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      41,   20,   19,   19, 0x05,
      85,   74,   19,   19, 0x05,
     125,  116,   19,   19, 0x05,
     164,  149,   19,   19, 0x05,
     227,  191,   19,   19, 0x05,
     270,  116,   19,   19, 0x05,
     308,  294,   19,   19, 0x05,
     336,  116,   19,   19, 0x05,
     374,  361,   19,   19, 0x05,
     425,  409,   19,   19, 0x05,
     462,  191,   19,   19, 0x05,
     518,   19,   19,   19, 0x05,
     544,  539,   19,   19, 0x05,
     587,  581,   19,   19, 0x05,
     622,  610,   19,   19, 0x05,
     680,  642,   19,   19, 0x05,
     734,  581,   19,   19, 0x05,
     760,  191,   19,   19, 0x05,
     817,   19,   19,   19, 0x05,
     849,  829,   19,   19, 0x05,
     917,  892,   19,   19, 0x05,
    1002,  971,   19,   19, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_JagunParserFromXML[] = {
    "JagunParserFromXML\0\0login,password,email\0"
    "newUser(QString,QString,QString)\0"
    "login,date\0userCreated(QString,QDateTime)\0"
    "errorStr\0userNotCreated(QString)\0"
    "login,password\0loginUser(QString,QString)\0"
    "login,nickname,message,image,status\0"
    "logOn(QString,QString,QString,QString,int)\0"
    "loginUserError(QString)\0login,message\0"
    "addContact(QString,QString)\0"
    "addContactError(QString)\0from,message\0"
    "requestAddContact(QString,QString)\0"
    "to,confirmation\0addContactConfirmation(QString,bool)\0"
    "approvedAddContact(QString,QString,QString,QString,int)\0"
    "requestContactList()\0list\0"
    "contactList(QList<JagunMSNContact*>)\0"
    "login\0removeContact(QString)\0login,block\0"
    "block(QString,bool)\0"
    "nickname,message,image,status,sendToo\0"
    "changeStatus(QString,QString,QString,int,QStringList)\0"
    "getStatusContact(QString)\0"
    "changeStatusContact(QString,QString,QString,QString,int)\0"
    "keepAlive()\0to,message,dateSend\0"
    "sendMessage(QStringList,QString,QDateTime)\0"
    "from,to,message,dateSend\0"
    "receiveMessage(QString,QStringList,QString,QDateTime)\0"
    "errorMsg,errorLine,errorColumn\0"
    "error(QString,int,int)\0"
};

const QMetaObject JagunParserFromXML::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunParserFromXML,
      qt_meta_data_JagunParserFromXML, 0 }
};

const QMetaObject *JagunParserFromXML::metaObject() const
{
    return &staticMetaObject;
}

void *JagunParserFromXML::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunParserFromXML))
        return static_cast<void*>(const_cast< JagunParserFromXML*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunParserFromXML::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: userCreated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2]))); break;
        case 2: userNotCreated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: loginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: logOn((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: loginUserError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: addContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: addContactError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: requestAddContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: addContactConfirmation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: approvedAddContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 11: requestContactList(); break;
        case 12: contactList((*reinterpret_cast< QList<JagunMSNContact*>(*)>(_a[1]))); break;
        case 13: removeContact((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: block((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: changeStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5]))); break;
        case 16: getStatusContact((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: changeStatusContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 18: keepAlive(); break;
        case 19: sendMessage((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 20: receiveMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QDateTime(*)>(_a[4]))); break;
        case 21: error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void JagunParserFromXML::newUser(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunParserFromXML::userCreated(QString _t1, QDateTime _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JagunParserFromXML::userNotCreated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JagunParserFromXML::loginUser(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JagunParserFromXML::logOn(QString _t1, QString _t2, QString _t3, QString _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JagunParserFromXML::loginUserError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JagunParserFromXML::addContact(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JagunParserFromXML::addContactError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void JagunParserFromXML::requestAddContact(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void JagunParserFromXML::addContactConfirmation(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void JagunParserFromXML::approvedAddContact(QString _t1, QString _t2, QString _t3, QString _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void JagunParserFromXML::requestContactList()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void JagunParserFromXML::contactList(QList<JagunMSNContact*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void JagunParserFromXML::removeContact(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void JagunParserFromXML::block(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void JagunParserFromXML::changeStatus(QString _t1, QString _t2, QString _t3, int _t4, QStringList _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void JagunParserFromXML::getStatusContact(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void JagunParserFromXML::changeStatusContact(QString _t1, QString _t2, QString _t3, QString _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void JagunParserFromXML::keepAlive()
{
    QMetaObject::activate(this, &staticMetaObject, 18, 0);
}

// SIGNAL 19
void JagunParserFromXML::sendMessage(QStringList _t1, QString _t2, QDateTime _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void JagunParserFromXML::receiveMessage(QString _t1, QStringList _t2, QString _t3, QDateTime _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void JagunParserFromXML::error(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}
QT_END_MOC_NAMESPACE
