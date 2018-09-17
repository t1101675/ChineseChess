/****************************************************************************
** Meta object code from reading C++ file 'coder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessClient/coder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Coder_t {
    QByteArrayData data[12];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Coder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Coder_t qt_meta_stringdata_Coder = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Coder"
QT_MOC_LITERAL(1, 6, 10), // "newSigByte"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "array"
QT_MOC_LITERAL(4, 24, 10), // "newSigInfo"
QT_MOC_LITERAL(5, 35, 10), // "ChessInfo*"
QT_MOC_LITERAL(6, 46, 4), // "info"
QT_MOC_LITERAL(7, 51, 13), // "newSigMessage"
QT_MOC_LITERAL(8, 65, 3), // "str"
QT_MOC_LITERAL(9, 69, 10), // "newSloByte"
QT_MOC_LITERAL(10, 80, 10), // "newSloInfo"
QT_MOC_LITERAL(11, 91, 13) // "newSloMessage"

    },
    "Coder\0newSigByte\0\0array\0newSigInfo\0"
    "ChessInfo*\0info\0newSigMessage\0str\0"
    "newSloByte\0newSloInfo\0newSloMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Coder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   53,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void Coder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Coder *_t = static_cast<Coder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newSigByte((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->newSigInfo((*reinterpret_cast< ChessInfo*(*)>(_a[1]))); break;
        case 2: _t->newSigMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->newSloByte((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->newSloInfo((*reinterpret_cast< ChessInfo*(*)>(_a[1]))); break;
        case 5: _t->newSloMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Coder::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Coder::newSigByte)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Coder::*)(ChessInfo * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Coder::newSigInfo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Coder::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Coder::newSigMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Coder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Coder.data,
      qt_meta_data_Coder,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Coder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Coder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Coder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Coder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Coder::newSigByte(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Coder::newSigInfo(ChessInfo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Coder::newSigMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
