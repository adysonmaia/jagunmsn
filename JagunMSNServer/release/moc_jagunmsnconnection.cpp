/****************************************************************************
** Meta object code from reading C++ file 'jagunmsnconnection.h'
**
** Created: Sun May 31 21:05:32 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunmsnconnection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunmsnconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunMSNConnection[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x09,
      68,   19,   19,   19, 0x09,
      98,   93,   19,   19, 0x09,
     122,   19,   19,   19, 0x09,
     153,  132,   19,   19, 0x09,
     201,  186,   19,   19, 0x09,
     228,   19,   19,   19, 0x09,
     263,  249,   19,   19, 0x09,
     307,  291,   19,   19, 0x09,
     382,  344,   19,   19, 0x09,
     456,  436,   19,   19, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunMSNConnection[] = {
    "JagunMSNConnection\0\0error\0"
    "errorConnection(JagunKET::EErrorJagunKET)\0"
    "disconnectedConnection()\0data\0"
    "readClient(QByteArray*)\0timeout()\0"
    "login,password,email\0"
    "newUser(QString,QString,QString)\0"
    "login,password\0loginUser(QString,QString)\0"
    "requestContactList()\0login,message\0"
    "addContact(QString,QString)\0to,confirmation\0"
    "addContactConfirmation(QString,bool)\0"
    "nickname,message,image,status,sendToo\0"
    "changeStatus(QString,QString,QString,int,QStringList)\0"
    "to,message,dateSend\0"
    "sendMessage(QStringList,QString,QDateTime)\0"
};

const QMetaObject JagunMSNConnection::staticMetaObject = {
    { &JagunKETConnection::staticMetaObject, qt_meta_stringdata_JagunMSNConnection,
      qt_meta_data_JagunMSNConnection, 0 }
};

const QMetaObject *JagunMSNConnection::metaObject() const
{
    return &staticMetaObject;
}

void *JagunMSNConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunMSNConnection))
        return static_cast<void*>(const_cast< JagunMSNConnection*>(this));
    return JagunKETConnection::qt_metacast(_clname);
}

int JagunMSNConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = JagunKETConnection::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: errorConnection((*reinterpret_cast< JagunKET::EErrorJagunKET(*)>(_a[1]))); break;
        case 1: disconnectedConnection(); break;
        case 2: readClient((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 3: timeout(); break;
        case 4: newUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: loginUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: requestContactList(); break;
        case 7: addContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: addContactConfirmation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: changeStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5]))); break;
        case 10: sendMessage((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
