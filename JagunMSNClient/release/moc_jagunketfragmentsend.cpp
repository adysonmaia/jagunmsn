/****************************************************************************
** Meta object code from reading C++ file 'jagunketfragmentsend.h'
**
** Created: Sat May 2 21:18:46 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JagunKet/jagunketfragmentsend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunketfragmentsend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunKETFragmentSend[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      33,   22,   21,   21, 0x05,
      60,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      82,   21,   21,   21, 0x08,
      98,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JagunKETFragmentSend[] = {
    "JagunKETFragmentSend\0\0sequential\0"
    "notConfirmedError(quint32)\0"
    "notConfirmed(quint32)\0finishedTimer()\0"
    "alertTimer()\0"
};

const QMetaObject JagunKETFragmentSend::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JagunKETFragmentSend,
      qt_meta_data_JagunKETFragmentSend, 0 }
};

const QMetaObject *JagunKETFragmentSend::metaObject() const
{
    return &staticMetaObject;
}

void *JagunKETFragmentSend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunKETFragmentSend))
        return static_cast<void*>(const_cast< JagunKETFragmentSend*>(this));
    return QObject::qt_metacast(_clname);
}

int JagunKETFragmentSend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: notConfirmedError((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: notConfirmed((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: finishedTimer(); break;
        case 3: alertTimer(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void JagunKETFragmentSend::notConfirmedError(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunKETFragmentSend::notConfirmed(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
