/****************************************************************************
** Meta object code from reading C++ file 'clientdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessClient/clientdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientDialog_t {
    QByteArrayData data[11];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientDialog_t qt_meta_stringdata_ClientDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ClientDialog"
QT_MOC_LITERAL(1, 13, 9), // "okClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "IP"
QT_MOC_LITERAL(4, 27, 4), // "port"
QT_MOC_LITERAL(5, 32, 11), // "quitClicked"
QT_MOC_LITERAL(6, 44, 13), // "newConnection"
QT_MOC_LITERAL(7, 58, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(8, 78, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(9, 100, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(10, 124, 10) // "newConnect"

    },
    "ClientDialog\0okClicked\0\0IP\0port\0"
    "quitClicked\0newConnection\0on_okButton_clicked\0"
    "on_quitButton_clicked\0on_cancelButton_clicked\0"
    "newConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientDialog *_t = static_cast<ClientDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->okClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->quitClicked(); break;
        case 2: _t->newConnection(); break;
        case 3: _t->on_okButton_clicked(); break;
        case 4: _t->on_quitButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        case 6: _t->newConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientDialog::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientDialog::okClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientDialog::quitClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClientDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientDialog::newConnection)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClientDialog.data,
      qt_meta_data_ClientDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ClientDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ClientDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ClientDialog::okClicked(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientDialog::quitClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ClientDialog::newConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE