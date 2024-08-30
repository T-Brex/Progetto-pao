/****************************************************************************
** Meta object code from reading C++ file 'simulation.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frontend/simulation.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Simulation_t {
    uint offsetsAndSizes[32];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Simulation_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Simulation_t qt_meta_stringdata_Simulation = {
    {
        QT_MOC_LITERAL(0, 10),  // "Simulation"
        QT_MOC_LITERAL(11, 12),  // "removeSensor"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 1),  // "n"
        QT_MOC_LITERAL(27, 10),  // "updateDust"
        QT_MOC_LITERAL(38, 4),  // "Dust"
        QT_MOC_LITERAL(43, 1),  // "s"
        QT_MOC_LITERAL(45, 1),  // "i"
        QT_MOC_LITERAL(47, 10),  // "updateWind"
        QT_MOC_LITERAL(58, 4),  // "Wind"
        QT_MOC_LITERAL(63, 16),  // "updateTermometer"
        QT_MOC_LITERAL(80, 10),  // "Termometer"
        QT_MOC_LITERAL(91, 14),  // "updateHumidity"
        QT_MOC_LITERAL(106, 8),  // "Humidity"
        QT_MOC_LITERAL(115, 16),  // "updateAirQuality"
        QT_MOC_LITERAL(132, 10)   // "AirQuality"
    },
    "Simulation\0removeSensor\0\0n\0updateDust\0"
    "Dust\0s\0i\0updateWind\0Wind\0updateTermometer\0"
    "Termometer\0updateHumidity\0Humidity\0"
    "updateAirQuality\0AirQuality"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Simulation[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    3,   53,    2, 0x0a,    3 /* Public */,
       8,    3,   60,    2, 0x0a,    7 /* Public */,
      10,    3,   67,    2, 0x0a,   11 /* Public */,
      12,    3,   74,    2, 0x0a,   15 /* Public */,
      14,    3,   81,    2, 0x0a,   19 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, QMetaType::Int,    6,    7,    3,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int,    6,    7,    3,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int, QMetaType::Int,    6,    7,    3,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int, QMetaType::Int,    6,    7,    3,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int, QMetaType::Int,    6,    7,    3,

       0        // eod
};

void Simulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Simulation *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->removeSensor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->updateDust((*reinterpret_cast< std::add_pointer_t<Dust>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->updateWind((*reinterpret_cast< std::add_pointer_t<Wind>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->updateTermometer((*reinterpret_cast< std::add_pointer_t<Termometer>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->updateHumidity((*reinterpret_cast< std::add_pointer_t<Humidity>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->updateAirQuality((*reinterpret_cast< std::add_pointer_t<AirQuality>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject Simulation::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Simulation.offsetsAndSizes,
    qt_meta_data_Simulation,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Simulation_t
, QtPrivate::TypeAndForceComplete<Simulation, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Dust &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Wind &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Termometer &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Humidity &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const AirQuality &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Simulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Simulation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Simulation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Simulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
