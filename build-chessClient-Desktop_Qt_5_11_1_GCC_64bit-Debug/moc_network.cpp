/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessClient/network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Network_t {
    QByteArrayData data[16];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Network_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Network_t qt_meta_stringdata_Network = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Network"
QT_MOC_LITERAL(1, 8, 7), // "newRead"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 13), // "clientConnect"
QT_MOC_LITERAL(4, 31, 13), // "serverConnect"
QT_MOC_LITERAL(5, 45, 11), // "startServer"
QT_MOC_LITERAL(6, 57, 2), // "IP"
QT_MOC_LITERAL(7, 60, 4), // "port"
QT_MOC_LITERAL(8, 65, 11), // "startClient"
QT_MOC_LITERAL(9, 77, 9), // "endServer"
QT_MOC_LITERAL(10, 87, 9), // "endClient"
QT_MOC_LITERAL(11, 97, 16), // "newServerConnect"
QT_MOC_LITERAL(12, 114, 16), // "newClientConnect"
QT_MOC_LITERAL(13, 131, 11), // "readMessage"
QT_MOC_LITERAL(14, 143, 7), // "newSend"
QT_MOC_LITERAL(15, 151, 5) // "array"

    },
    "Network\0newRead\0\0clientConnect\0"
    "serverConnect\0startServer\0IP\0port\0"
    "startClient\0endServer\0endClient\0"
    "newServerConnect\0newClientConnect\0"
    "readMessage\0newSend\0array"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    0,   72,    2, 0x06 /* Public */,
       4,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   74,    2, 0x0a /* Public */,
       8,    2,   79,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   15,

       0        // eod
};

void Network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Network *_t = static_cast<Network *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newRead((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->clientConnect(); break;
        case 2: _t->serverConnect(); break;
        case 3: _t->startServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->startClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->endServer(); break;
        case 6: _t->endClient(); break;
        case 7: _t->newServerConnect(); break;
        case 8: _t->newClientConnect(); break;
        case 9: _t->readMessage(); break;
        case 10: _t->newSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Network::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::newRead)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Network::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::clientConnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Network::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::serverConnect)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Network::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Network.data,
      qt_meta_data_Network,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Network::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Network.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Network::newRead(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Network::clientConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Network::serverConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
