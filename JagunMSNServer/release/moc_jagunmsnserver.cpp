/****************************************************************************
** Meta object code from reading C++ file 'jagunmsnserver.h'
**
** Created: Sun May 31 21:05:34 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunmsnserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunmsnserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunMSNServer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      39,   16,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunMSNServer[] = {
    "JagunMSNServer\0\0idConnection,host,port\0"
    "createNewConnection(quint32,QHostAddress,quint16)\0"
};

const QMetaObject JagunMSNServer::staticMetaObject = {
    { &JagunKETServer::staticMetaObject, qt_meta_stringdata_JagunMSNServer,
      qt_meta_data_JagunMSNServer, 0 }
};

const QMetaObject *JagunMSNServer::metaObject() const
{
    return &staticMetaObject;
}

void *JagunMSNServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunMSNServer))
        return static_cast<void*>(const_cast< JagunMSNServer*>(this));
    return JagunKETServer::qt_metacast(_clname);
}

int JagunMSNServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = JagunKETServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: createNewConnection((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
