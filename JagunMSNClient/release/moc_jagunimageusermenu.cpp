/****************************************************************************
** Meta object code from reading C++ file 'jagunimageusermenu.h'
**
** Created: Sat May 2 21:18:51 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunimageusermenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunimageusermenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunImageUserMenu[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      32,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   56,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JagunImageUserMenu[] = {
    "JagunImageUserMenu\0\0i,imageName\0"
    "newImage(QIcon,QString)\0i\0"
    "selectItem(QModelIndex)\0"
};

const QMetaObject JagunImageUserMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_JagunImageUserMenu,
      qt_meta_data_JagunImageUserMenu, 0 }
};

const QMetaObject *JagunImageUserMenu::metaObject() const
{
    return &staticMetaObject;
}

void *JagunImageUserMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunImageUserMenu))
        return static_cast<void*>(const_cast< JagunImageUserMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int JagunImageUserMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newImage((*reinterpret_cast< QIcon(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: selectItem((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void JagunImageUserMenu::newImage(QIcon _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
