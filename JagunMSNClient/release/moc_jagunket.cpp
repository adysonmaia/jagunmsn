/****************************************************************************
** Meta object code from reading C++ file 'jagunket.h'
**
** Created: Sat May 2 21:18:45 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKet/jagunket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKET[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      22,   10,    9,    9, 0x05,
      65,    9,    9,    9, 0x05,
      77,    9,    9,    9, 0x05,
      98,   92,    9,    9, 0x05,
     138,  130,    9,    9, 0x05,
     179,  174,    9,    9, 0x05,
     200,    9,    9,    9, 0x05,
     214,  211,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     244,  235,    9,    9, 0x09,
     283,    9,    9,    9, 0x09,
     301,    9,    9,    9, 0x09,
     318,  174,    9,    9, 0x09,
     343,    9,    9,    9, 0x09,
     357,    9,    9,    9, 0x09,
     383,    9,    9,    9, 0x09,
     396,    9,    9,    9, 0x09,
     417,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunKET[] = {
    "JagunKET\0\0socketState\0"
    "stateChanged(QAbstractSocket::SocketState)\0"
    "connected()\0disconnected()\0error\0"
    "error(JagunKET::EErrorJagunKET)\0warning\0"
    "warning(JagunKET::EWarningJagunKET)\0"
    "data\0receive(QByteArray*)\0sentData()\0"
    "id\0idAvailable(quint32)\0newState\0"
    "setState(QAbstractSocket::SocketState)\0"
    "arrivedDatagram()\0receiveFailure()\0"
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
        case 3: error((*reinterpret_cast< JagunKET::EErrorJagunKET(*)>(_a[1]))); break;
        case 4: warning((*reinterpret_cast< JagunKET::EWarningJagunKET(*)>(_a[1]))); break;
        case 5: receive((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 6: sentData(); break;
        case 7: idAvailable((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 8: setState((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 9: arrivedDatagram(); break;
        case 10: receiveFailure(); break;
        case 11: sendFailure((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 12: sendSuccess(); break;
        case 13: checkStateNewConnection(); break;
        case 14: tryConnect(); break;
        case 15: tryCloseConnection(); break;
        case 16: clean(); break;
        default: ;
        }
        _id -= 17;
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
void JagunKET::error(JagunKET::EErrorJagunKET _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JagunKET::warning(JagunKET::EWarningJagunKET _t1)
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
