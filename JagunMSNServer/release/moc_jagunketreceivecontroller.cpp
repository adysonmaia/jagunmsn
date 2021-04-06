/****************************************************************************
** Meta object code from reading C++ file 'jagunketreceivecontroller.h'
**
** Created: Sat May 2 21:55:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKet/jagunketreceivecontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunketreceivecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKETReceiveController[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x05,
      49,   44,   26,   26, 0x05,
      85,   77,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
     149,   26,   26,   26, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunKETReceiveController[] = {
    "JagunKETReceiveController\0\0receiveFailure()\0"
    "data\0receiveSuccess(QByteArray*)\0"
    "warning\0"
    "warning(JagunKETReceiveController::EWJagunKETReceiveController)\0"
    "failure()\0"
};

const QMetaObject JagunKETReceiveController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunKETReceiveController,
      qt_meta_data_JagunKETReceiveController, 0 }
};

const QMetaObject *JagunKETReceiveController::metaObject() const
{
    return &staticMetaObject;
}

void *JagunKETReceiveController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunKETReceiveController))
        return static_cast<void*>(const_cast< JagunKETReceiveController*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunKETReceiveController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: receiveFailure(); break;
        case 1: receiveSuccess((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 2: warning((*reinterpret_cast< JagunKETReceiveController::EWJagunKETReceiveController(*)>(_a[1]))); break;
        case 3: failure(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void JagunKETReceiveController::receiveFailure()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void JagunKETReceiveController::receiveSuccess(QByteArray * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JagunKETReceiveController::warning(JagunKETReceiveController::EWJagunKETReceiveController _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
