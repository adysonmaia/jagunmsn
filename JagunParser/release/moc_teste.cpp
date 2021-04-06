/****************************************************************************
** Meta object code from reading C++ file 'teste.h'
**
** Created: Sun Apr 26 19:31:42 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../teste.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teste.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Teste[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      28,    7,    6,    6, 0x09,
      72,   61,    6,    6, 0x09,
     112,  103,    6,    6, 0x09,
     151,  136,    6,    6, 0x09,
     214,  178,    6,    6, 0x09,
     257,  103,    6,    6, 0x09,
     295,  281,    6,    6, 0x09,
     328,  323,    6,    6, 0x09,
     403,  365,    6,    6, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Teste[] = {
    "Teste\0\0login,password,email\0"
    "newUser(QString,QString,QString)\0"
    "login,date\0userCreated(QString,QDateTime)\0"
    "errorStr\0userNotCreated(QString)\0"
    "login,password\0loginUser(QString,QString)\0"
    "login,nickname,message,image,status\0"
    "logOn(QString,QString,QString,QString,int)\0"
    "loginUserError(QString)\0login,message\0"
    "addContact(QString,QString)\0list\0"
    "contactList(QList<JagunMSNContact*>)\0"
    "nickname,message,image,status,sendToo\0"
    "changeStatus(QString,QString,QString,int,QStringList)\0"
};

const QMetaObject Teste::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Teste,
      qt_meta_data_Teste, 0 }
};

const QMetaObject *Teste::metaObject() const
{
    return &staticMetaObject;
}

void *Teste::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Teste))
        return static_cast<void*>(const_cast< Teste*>(this));
    return QObject::qt_metacast(_clname);
}

int Teste::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 7: contactList((*reinterpret_cast< QList<JagunMSNContact*>(*)>(_a[1]))); break;
        case 8: changeStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
