/****************************************************************************
** Meta object code from reading C++ file 'chessboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessClient/chessboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chessboard_t {
    QByteArrayData data[10];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chessboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chessboard_t qt_meta_stringdata_Chessboard = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Chessboard"
QT_MOC_LITERAL(1, 11, 7), // "newSend"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "ChessInfo*"
QT_MOC_LITERAL(4, 31, 4), // "info"
QT_MOC_LITERAL(5, 36, 7), // "oneMove"
QT_MOC_LITERAL(6, 44, 8), // "checking"
QT_MOC_LITERAL(7, 53, 3), // "win"
QT_MOC_LITERAL(8, 57, 4), // "lose"
QT_MOC_LITERAL(9, 62, 7) // "newRead"

    },
    "Chessboard\0newSend\0\0ChessInfo*\0info\0"
    "oneMove\0checking\0win\0lose\0newRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chessboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,
       8,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Chessboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chessboard *_t = static_cast<Chessboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newSend((*reinterpret_cast< ChessInfo*(*)>(_a[1]))); break;
        case 1: _t->oneMove(); break;
        case 2: _t->checking(); break;
        case 3: _t->win(); break;
        case 4: _t->lose(); break;
        case 5: _t->newRead((*reinterpret_cast< ChessInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Chessboard::*)(ChessInfo * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chessboard::newSend)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Chessboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chessboard::oneMove)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Chessboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chessboard::checking)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Chessboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chessboard::win)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Chessboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chessboard::lose)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chessboard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Chessboard.data,
      qt_meta_data_Chessboard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chessboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chessboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chessboard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Chessboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Chessboard::newSend(ChessInfo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Chessboard::oneMove()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Chessboard::checking()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Chessboard::win()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Chessboard::lose()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
