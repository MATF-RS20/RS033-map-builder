/****************************************************************************
** Meta object code from reading C++ file 'options_comunicaton.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/comunication/options_comunicaton.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'options_comunicaton.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_map_builder__options_communication_t {
    QByteArrayData data[4];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_map_builder__options_communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_map_builder__options_communication_t qt_meta_stringdata_map_builder__options_communication = {
    {
QT_MOC_LITERAL(0, 0, 34), // "map_builder::options_communic..."
QT_MOC_LITERAL(1, 35, 27), // "make_and_show_splash_screen"
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 30) // "hide_and_destroy_splash_screen"

    },
    "map_builder::options_communication\0"
    "make_and_show_splash_screen\0\0"
    "hide_and_destroy_splash_screen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_map_builder__options_communication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void map_builder::options_communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        options_communication *_t = static_cast<options_communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->make_and_show_splash_screen(); break;
        case 1: _t->hide_and_destroy_splash_screen(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject map_builder::options_communication::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_map_builder__options_communication.data,
      qt_meta_data_map_builder__options_communication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *map_builder::options_communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *map_builder::options_communication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_map_builder__options_communication.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int map_builder::options_communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
