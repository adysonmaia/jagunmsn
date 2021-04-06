/****************************************************************************
** Meta object code from reading C++ file 'jagunchatwindow.h'
**
** Created: Sun May 31 19:43:50 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jagunchatwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jagunchatwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JagunChatWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      28,   17,   16,   16, 0x05,
      61,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_JagunChatWindow[] = {
    "JagunChatWindow\0\0to,message\0"
    "sendMessage(QStringList,QString)\0"
    "pressEnter()\0sendMsg()\0"
};

const QMetaObject JagunChatWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JagunChatWindow,
      qt_meta_data_JagunChatWindow, 0 }
};

const QMetaObject *JagunChatWindow::metaObject() const
{
    return &staticMetaObject;
}

void *JagunChatWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JagunChatWindow))
        return static_cast<void*>(const_cast< JagunChatWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JagunChatWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendMessage((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: pressEnter(); break;
        case 2: sendMsg(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void JagunChatWindow::sendMessage(QStringList _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JagunChatWindow::pressEnter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
