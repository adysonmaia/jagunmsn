/****************************************************************************
** Meta object code from reading C++ file 'jagunchatuseritem.h'
**
** Created: Sat May 2 21:19:02 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunchatuseritem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunchatuseritem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunChatUserItem[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_JagunChatUserItem[] = {
    "JagunChatUserItem\0"
};

const QMetaObject JagunChatUserItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_JagunChatUserItem,
      qt_meta_data_JagunChatUserItem, 0 }
};

const QMetaObject *JagunChatUserItem::metaObject() const
{
    return &staticMetaObject;
}

void *JagunChatUserItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunChatUserItem))
        return static_cast<void*>(const_cast< JagunChatUserItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int JagunChatUserItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
