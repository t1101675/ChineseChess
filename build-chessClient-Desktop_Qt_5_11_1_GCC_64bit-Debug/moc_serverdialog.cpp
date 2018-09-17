/****************************************************************************
** Meta object code from reading C++ file 'serverdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessClient/serverdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerDialog_t {
    QByteArrayData data[13];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerDialog_t qt_meta_stringdata_ServerDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerDialog"
QT_MOC_LITERAL(1, 13, 9), // "okClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "IP"
QT_MOC_LITERAL(4, 27, 4), // "port"
QT_MOC_LITERAL(5, 32, 11), // "quitClicked"
QT_MOC_LITERAL(6, 44, 13), // "newConnection"
QT_MOC_LITERAL(7, 58, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(8, 80, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(9, 100, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(10, 124, 21), // "on_ipEdit_textChanged"
QT_MOC_LITERAL(11, 146, 4), // "arg1"
QT_MOC_LITERAL(12, 151, 10) // "newConnect"

    },
    "ServerDialog\0okClicked\0\0IP\0port\0"
    "quitClicked\0newConnection\0"
    "on_quitButton_clicked\0on_okButton_clicked\0"
    "on_cancelButton_clicked\0on_ipEdit_textChanged\0"
    "arg1\0newConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    0,   59,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    1,   64,    2, 0x08 /* Private */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void ServerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerDialog *_t = static_cast<ServerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->okClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->quitClicked(); break;
        case 2: _t->newConnection(); break;
        case 3: _t->on_quitButton_clicked(); break;
        case 4: _t->on_okButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        case 6: _t->on_ipEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->newConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerDialog::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerDialog::okClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerDialog::quitClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerDialog::newConnection)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ServerDialog.data,
      qt_meta_data_ServerDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ServerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ServerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ServerDialog::okClicked(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerDialog::quitClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ServerDialog::newConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
