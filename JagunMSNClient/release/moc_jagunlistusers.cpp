/****************************************************************************
** Meta object code from reading C++ file 'jagunlistusers.h'
**
** Created: Sat May 2 21:18:55 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunlistusers.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunlistusers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunListUsers[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x0a,
      72,   61,   15,   15, 0x0a,
     104,   61,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_JagunListUsers[] = {
    "JagunListUsers\0\0list\0"
    "setContactList(QList<JagunMSNContact*>)\0"
    "newContact\0addNewContact(JagunMSNContact*)\0"
    "contactChangeStatus(JagunMSNContact*)\0"
};

const QMetaObject JagunListUsers::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_JagunListUsers,
      qt_meta_data_JagunListUsers, 0 }
};

const QMetaObject *JagunListUsers::metaObject() const
{
    return &staticMetaObject;
}

void *JagunListUsers::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunListUsers))
        return static_cast<void*>(const_cast< JagunListUsers*>(this));
    return QListWidget::qt_metacast(_clname);
}

int JagunListUsers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setContactList((*reinterpret_cast< QList<JagunMSNContact*>(*)>(_a[1]))); break;
        case 1: addNewContact((*reinterpret_cast< JagunMSNContact*(*)>(_a[1]))); break;
        case 2: contactChangeStatus((*reinterpret_cast< JagunMSNContact*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
