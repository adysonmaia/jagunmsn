/****************************************************************************
** Meta object code from reading C++ file 'jagunketserver.h'
**
** Created: Sat May 2 21:55:01 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKetServer/jagunketserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunketserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKETServer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      39,   16,   15,   15, 0x05,
     100,   92,   15,   15, 0x05,
     154,  148,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     198,   15,   15,   15, 0x08,
     208,  205,   15,   15, 0x08,
     233,   16,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunKETServer[] = {
    "JagunKETServer\0\0idConnection,host,port\0"
    "newConnectionAvailable(quint32,QHostAddress,quint16)\0"
    "warning\0warning(JagunKETServer::EWarningJagunKETServer)\0"
    "error\0error(JagunKETServer::EErrorJagunKETServer)\0"
    "read()\0id\0getDisposableId(quint32)\0"
    "createNewConnection(quint32,QHostAddress,quint16)\0"
};

const QMetaObject JagunKETServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunKETServer,
      qt_meta_data_JagunKETServer, 0 }
};

const QMetaObject *JagunKETServer::metaObject() const
{
    return &staticMetaObject;
}

void *JagunKETServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunKETServer))
        return static_cast<void*>(const_cast< JagunKETServer*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunKETServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newConnectionAvailable((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 1: warning((*reinterpret_cast< JagunKETServer::EWarningJagunKETServer(*)>(_a[1]))); break;
        case 2: error((*reinterpret_cast< JagunKETServer::EErrorJagunKETServer(*)>(_a[1]))); break;
        case 3: read(); break;
        case 4: getDisposableId((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: createNewConnection((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void JagunKETServer::newConnectionAvailable(quint32 _t1, QHostAddress _t2, quint16 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunKETServer::warning(JagunKETServer::EWarningJagunKETServer _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JagunKETServer::error(JagunKETServer::EErrorJagunKETServer _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
