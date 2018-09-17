/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessClient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "serverConnect"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "clientConnect"
QT_MOC_LITERAL(4, 40, 10), // "clickStart"
QT_MOC_LITERAL(5, 51, 12), // "clickEndGame"
QT_MOC_LITERAL(6, 64, 12), // "clickNewGame"
QT_MOC_LITERAL(7, 77, 15), // "clickQuitButton"
QT_MOC_LITERAL(8, 93, 14), // "newReadMessage"
QT_MOC_LITERAL(9, 108, 3), // "str"
QT_MOC_LITERAL(10, 112, 7), // "oneMove"
QT_MOC_LITERAL(11, 120, 11), // "oppoOneMove"
QT_MOC_LITERAL(12, 132, 3), // "win"
QT_MOC_LITERAL(13, 136, 4), // "lose"
QT_MOC_LITERAL(14, 141, 7), // "timeOut"
QT_MOC_LITERAL(15, 149, 5), // "admit"
QT_MOC_LITERAL(16, 155, 8), // "checking"
QT_MOC_LITERAL(17, 164, 10), // "disconnect"
QT_MOC_LITERAL(18, 175, 29), // "on_actionSet_server_triggered"
QT_MOC_LITERAL(19, 205, 36), // "on_actionConnect_to_server_tr..."
QT_MOC_LITERAL(20, 242, 28), // "on_actionLoad_file_triggered"
QT_MOC_LITERAL(21, 271, 28), // "on_actionSave_file_triggered"
QT_MOC_LITERAL(22, 300, 19), // "on_action_triggered"
QT_MOC_LITERAL(23, 320, 22) // "on_action_Qt_triggered"

    },
    "MainWindow\0serverConnect\0\0clientConnect\0"
    "clickStart\0clickEndGame\0clickNewGame\0"
    "clickQuitButton\0newReadMessage\0str\0"
    "oneMove\0oppoOneMove\0win\0lose\0timeOut\0"
    "admit\0checking\0disconnect\0"
    "on_actionSet_server_triggered\0"
    "on_actionConnect_to_server_triggered\0"
    "on_actionLoad_file_triggered\0"
    "on_actionSave_file_triggered\0"
    "on_action_triggered\0on_action_Qt_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x0a /* Public */,
       3,    0,  120,    2, 0x0a /* Public */,
       4,    0,  121,    2, 0x0a /* Public */,
       5,    0,  122,    2, 0x0a /* Public */,
       6,    0,  123,    2, 0x0a /* Public */,
       7,    0,  124,    2, 0x0a /* Public */,
       8,    1,  125,    2, 0x0a /* Public */,
      10,    0,  128,    2, 0x0a /* Public */,
      11,    0,  129,    2, 0x0a /* Public */,
      12,    0,  130,    2, 0x0a /* Public */,
      13,    0,  131,    2, 0x0a /* Public */,
      14,    0,  132,    2, 0x0a /* Public */,
      15,    0,  133,    2, 0x0a /* Public */,
      16,    0,  134,    2, 0x0a /* Public */,
      17,    0,  135,    2, 0x0a /* Public */,
      18,    0,  136,    2, 0x08 /* Private */,
      19,    0,  137,    2, 0x08 /* Private */,
      20,    0,  138,    2, 0x08 /* Private */,
      21,    0,  139,    2, 0x08 /* Private */,
      22,    0,  140,    2, 0x08 /* Private */,
      23,    0,  141,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serverConnect(); break;
        case 1: _t->clientConnect(); break;
        case 2: _t->clickStart(); break;
        case 3: _t->clickEndGame(); break;
        case 4: _t->clickNewGame(); break;
        case 5: _t->clickQuitButton(); break;
        case 6: _t->newReadMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->oneMove(); break;
        case 8: _t->oppoOneMove(); break;
        case 9: _t->win(); break;
        case 10: _t->lose(); break;
        case 11: _t->timeOut(); break;
        case 12: _t->admit(); break;
        case 13: _t->checking(); break;
        case 14: _t->disconnect(); break;
        case 15: _t->on_actionSet_server_triggered(); break;
        case 16: _t->on_actionConnect_to_server_triggered(); break;
        case 17: _t->on_actionLoad_file_triggered(); break;
        case 18: _t->on_actionSave_file_triggered(); break;
        case 19: _t->on_action_triggered(); break;
        case 20: _t->on_action_Qt_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
