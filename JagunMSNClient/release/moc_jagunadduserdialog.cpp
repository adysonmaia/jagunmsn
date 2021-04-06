/****************************************************************************
** Meta object code from reading C++ file 'jagunadduserdialog.h'
**
** Created: Sat May 2 21:18:56 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunadduserdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunadduserdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunAddUserDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      33,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JagunAddUserDialog[] = {
    "JagunAddUserDialog\0\0cancelUser()\0"
    "addUser()\0"
};

const QMetaObject JagunAddUserDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_JagunAddUserDialog,
      qt_meta_data_JagunAddUserDialog, 0 }
};

const QMetaObject *JagunAddUserDialog::metaObject() const
{
    return &staticMetaObject;
}

void *JagunAddUserDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunAddUserDialog))
        return static_cast<void*>(const_cast< JagunAddUserDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int JagunAddUserDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cancelUser(); break;
        case 1: addUser(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
