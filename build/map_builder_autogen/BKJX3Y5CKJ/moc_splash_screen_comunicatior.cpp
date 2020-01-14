/****************************************************************************
** Meta object code from reading C++ file 'splash_screen_comunicatior.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/comunication/splash_screen_comunicatior.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splash_screen_comunicatior.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_map_builder__splash_screen_communication_t {
    QByteArrayData data[6];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_map_builder__splash_screen_communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_map_builder__splash_screen_communication_t qt_meta_stringdata_map_builder__splash_screen_communication = {
    {
QT_MOC_LITERAL(0, 0, 40), // "map_builder::splash_screen_co..."
QT_MOC_LITERAL(1, 41, 27), // "make_and_show_splash_screen"
QT_MOC_LITERAL(2, 69, 0), // ""
QT_MOC_LITERAL(3, 70, 30), // "hide_and_destroy_splash_screen"
QT_MOC_LITERAL(4, 101, 8), // "increase"
QT_MOC_LITERAL(5, 110, 6) // "amount"

    },
    "map_builder::splash_screen_communication\0"
    "make_and_show_splash_screen\0\0"
    "hide_and_destroy_splash_screen\0increase\0"
    "amount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_map_builder__splash_screen_communication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    1,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void map_builder::splash_screen_communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        splash_screen_communication *_t = static_cast<splash_screen_communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->make_and_show_splash_screen(); break;
        case 1: _t->hide_and_destroy_splash_screen(); break;
        case 2: _t->increase((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject map_builder::splash_screen_communication::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_map_builder__splash_screen_communication.data,
      qt_meta_data_map_builder__splash_screen_communication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *map_builder::splash_screen_communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *map_builder::splash_screen_communication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_map_builder__splash_screen_communication.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int map_builder::splash_screen_communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
