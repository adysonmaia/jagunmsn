/****************************************************************************
** Meta object code from reading C++ file 'jagunketsendcontroller.h'
**
** Created: Sat May 2 21:55:04 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKet/jagunketsendcontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunketsendcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKETSendController[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      29,   24,   23,   23, 0x05,
      54,   23,   23,   23, 0x05,
      76,   68,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,  140,   23,   23, 0x09,
     168,  140,   23,   23, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_JagunKETSendController[] = {
    "JagunKETSendController\0\0data\0"
    "sendFailure(QByteArray*)\0sendSuccess()\0"
    "warning\0"
    "warning(JagunKETSendController::EWarningJagunKETSendController)\0"
    "sequential\0failure(quint32)\0"
    "trySend(quint32)\0"
};

const QMetaObject JagunKETSendController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunKETSendController,
      qt_meta_data_JagunKETSendController, 0 }
};

const QMetaObject *JagunKETSendController::metaObject() const
{
    return &staticMetaObject;
}

void *JagunKETSendController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunKETSendController))
        return static_cast<void*>(const_cast< JagunKETSendController*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunKETSendController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendFailure((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 1: sendSuccess(); break;
        case 2: warning((*reinterpret_cast< JagunKETSendController::EWarningJagunKETSendController(*)>(_a[1]))); break;
        case 3: failure((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: trySend((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void JagunKETSendController::sendFailure(QByteArray * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunKETSendController::sendSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void JagunKETSendController::warning(JagunKETSendController::EWarningJagunKETSendController _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
