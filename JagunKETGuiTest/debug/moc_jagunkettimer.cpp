/****************************************************************************
** Meta object code from reading C++ file 'jagunkettimer.h'
**
** Created: Fri Apr 17 23:06:00 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKet/jagunkettimer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunkettimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKETTimer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      26,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JagunKETTimer[] = {
    "JagunKETTimer\0\0finished()\0alert()\0"
    "controlTimeout()\0"
};

const QMetaObject JagunKETTimer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunKETTimer,
      qt_meta_data_JagunKETTimer, 0 }
};

const QMetaObject *JagunKETTimer::metaObject() const
{
    return &staticMetaObject;
}

void *JagunKETTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunKETTimer))
        return static_cast<void*>(const_cast< JagunKETTimer*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunKETTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: alert(); break;
        case 2: controlTimeout(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void JagunKETTimer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void JagunKETTimer::alert()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
