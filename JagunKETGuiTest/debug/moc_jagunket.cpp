/****************************************************************************
** Meta object code from reading C++ file 'jagunket.h'
**
** Created: Fri Apr 17 23:05:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKet/jagunket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKET[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      22,   10,    9,    9, 0x05,
      65,    9,    9,    9, 0x05,
      77,    9,    9,    9, 0x05,
      98,   92,    9,    9, 0x05,
     128,  120,    9,    9, 0x05,
     159,  154,    9,    9, 0x05,
     180,    9,    9,    9, 0x05,
     194,  191,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     224,  215,    9,    9, 0x09,
     263,    9,    9,    9, 0x09,
     281,    9,    9,    9, 0x09,
     298,  154,    9,    9, 0x09,
     326,  154,    9,    9, 0x09,
     351,    9,    9,    9, 0x09,
     365,    9,    9,    9, 0x09,
     391,    9,    9,    9, 0x09,
     404,    9,    9,    9, 0x09,
     425,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunKET[] = {
    "JagunKET\0\0socketState\0"
    "stateChanged(QAbstractSocket::SocketState)\0"
    "connected()\0disconnected()\0error\0"
    "error(EErrorJagunKET)\0warning\0"
    "warning(EWarningJagunKET)\0data\0"
    "receive(QByteArray*)\0sentData()\0id\0"
    "idAvailable(quint32)\0newState\0"
    "setState(QAbstractSocket::SocketState)\0"
    "arrivedDatagram()\0receiveFailure()\0"
    "receiveSuccess(QByteArray*)\0"
    "sendFailure(QByteArray*)\0sendSuccess()\0"
    "checkStateNewConnection()\0tryConnect()\0"
    "tryCloseConnection()\0clean()\0"
};

const QMetaObject JagunKET::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunKET,
      qt_meta_data_JagunKET, 0 }
};

const QMetaObject *JagunKET::metaObject() const
{
    return &staticMetaObject;
}

void *JagunKET::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunKET))
        return static_cast<void*>(const_cast< JagunKET*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunKET::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 1: connected(); break;
        case 2: disconnected(); break;
        case 3: error((*reinterpret_cast< EErrorJagunKET(*)>(_a[1]))); break;
        case 4: warning((*reinterpret_cast< EWarningJagunKET(*)>(_a[1]))); break;
        case 5: receive((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 6: sentData(); break;
        case 7: idAvailable((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 8: setState((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 9: arrivedDatagram(); break;
        case 10: receiveFailure(); break;
        case 11: receiveSuccess((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 12: sendFailure((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 13: sendSuccess(); break;
        case 14: checkStateNewConnection(); break;
        case 15: tryConnect(); break;
        case 16: tryCloseConnection(); break;
        case 17: clean(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void JagunKET::stateChanged(QAbstractSocket::SocketState _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunKET::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void JagunKET::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void JagunKET::error(EErrorJagunKET _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JagunKET::warning(EWarningJagunKET _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JagunKET::receive(QByteArray * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JagunKET::sentData()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void JagunKET::idAvailable(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
