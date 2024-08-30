/****************************************************************************
** Meta object code from reading C++ file 'cartesianPlane.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frontend/cartesianPlane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cartesianPlane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CartesianPlane_t {
    uint offsetsAndSizes[30];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CartesianPlane_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_CartesianPlane_t qt_meta_stringdata_CartesianPlane = {
    {
        QT_MOC_LITERAL(0, 14),  // "CartesianPlane"
        QT_MOC_LITERAL(15, 7),  // "addDust"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 4),  // "Dust"
        QT_MOC_LITERAL(29, 1),  // "s"
        QT_MOC_LITERAL(31, 1),  // "i"
        QT_MOC_LITERAL(33, 1),  // "n"
        QT_MOC_LITERAL(35, 7),  // "addWind"
        QT_MOC_LITERAL(43, 4),  // "Wind"
        QT_MOC_LITERAL(48, 13),  // "addTermometer"
        QT_MOC_LITERAL(62, 10),  // "Termometer"
        QT_MOC_LITERAL(73, 11),  // "addHumidity"
        QT_MOC_LITERAL(85, 8),  // "Humidity"
        QT_MOC_LITERAL(94, 13),  // "addAirQuality"
        QT_MOC_LITERAL(108, 10)   // "AirQuality"
    },
    "CartesianPlane\0addDust\0\0Dust\0s\0i\0n\0"
    "addWind\0Wind\0addTermometer\0Termometer\0"
    "addHumidity\0Humidity\0addAirQuality\0"
    "AirQuality"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CartesianPlane[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   44,    2, 0x0a,    1 /* Public */,
       7,    3,   51,    2, 0x0a,    5 /* Public */,
       9,    3,   58,    2, 0x0a,    9 /* Public */,
      11,    3,   65,    2, 0x0a,   13 /* Public */,
      13,    3,   72,    2, 0x0a,   17 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,    4,    5,    6,

       0        // eod
};

void CartesianPlane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CartesianPlane *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addDust((*reinterpret_cast< std::add_pointer_t<Dust>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->addWind((*reinterpret_cast< std::add_pointer_t<Wind>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->addTermometer((*reinterpret_cast< std::add_pointer_t<Termometer>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->addHumidity((*reinterpret_cast< std::add_pointer_t<Humidity>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->addAirQuality((*reinterpret_cast< std::add_pointer_t<AirQuality>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject CartesianPlane::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CartesianPlane.offsetsAndSizes,
    qt_meta_data_CartesianPlane,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CartesianPlane_t
, QtPrivate::TypeAndForceComplete<CartesianPlane, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Dust &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Wind &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Termometer &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Humidity &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const AirQuality &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CartesianPlane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CartesianPlane::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CartesianPlane.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CartesianPlane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
