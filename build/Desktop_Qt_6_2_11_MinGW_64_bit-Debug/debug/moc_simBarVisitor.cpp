/****************************************************************************
** Meta object code from reading C++ file 'simBarVisitor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frontend/simBarVisitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simBarVisitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimBarVisitor_t {
    uint offsetsAndSizes[44];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SimBarVisitor_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_SimBarVisitor_t qt_meta_stringdata_SimBarVisitor = {
    {
        QT_MOC_LITERAL(0, 13),  // "SimBarVisitor"
        QT_MOC_LITERAL(14, 7),  // "addDust"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 4),  // "Dust"
        QT_MOC_LITERAL(28, 6),  // "sensor"
        QT_MOC_LITERAL(35, 1),  // "i"
        QT_MOC_LITERAL(37, 1),  // "n"
        QT_MOC_LITERAL(39, 7),  // "addWind"
        QT_MOC_LITERAL(47, 4),  // "Wind"
        QT_MOC_LITERAL(52, 13),  // "addTermometer"
        QT_MOC_LITERAL(66, 10),  // "Termometer"
        QT_MOC_LITERAL(77, 11),  // "addHumidity"
        QT_MOC_LITERAL(89, 8),  // "Humidity"
        QT_MOC_LITERAL(98, 13),  // "addAirQuality"
        QT_MOC_LITERAL(112, 10),  // "AirQuality"
        QT_MOC_LITERAL(123, 6),  // "remove"
        QT_MOC_LITERAL(130, 10),  // "updateDust"
        QT_MOC_LITERAL(141, 1),  // "s"
        QT_MOC_LITERAL(143, 10),  // "updateWind"
        QT_MOC_LITERAL(154, 16),  // "updateTermometer"
        QT_MOC_LITERAL(171, 14),  // "updateHumidity"
        QT_MOC_LITERAL(186, 16)   // "updateAirQuality"
    },
    "SimBarVisitor\0addDust\0\0Dust\0sensor\0i\0"
    "n\0addWind\0Wind\0addTermometer\0Termometer\0"
    "addHumidity\0Humidity\0addAirQuality\0"
    "AirQuality\0remove\0updateDust\0s\0"
    "updateWind\0updateTermometer\0updateHumidity\0"
    "updateAirQuality"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimBarVisitor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   80,    2, 0x06,    1 /* Public */,
       7,    3,   87,    2, 0x06,    5 /* Public */,
       9,    3,   94,    2, 0x06,    9 /* Public */,
      11,    3,  101,    2, 0x06,   13 /* Public */,
      13,    3,  108,    2, 0x06,   17 /* Public */,
      15,    1,  115,    2, 0x06,   21 /* Public */,
      16,    3,  118,    2, 0x06,   23 /* Public */,
      18,    3,  125,    2, 0x06,   27 /* Public */,
      19,    3,  132,    2, 0x06,   31 /* Public */,
      20,    3,  139,    2, 0x06,   35 /* Public */,
      21,    3,  146,    2, 0x06,   39 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,   17,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,   17,    5,    6,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,   17,    5,    6,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::Int,   17,    5,    6,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,   17,    5,    6,

       0        // eod
};

void SimBarVisitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SimBarVisitor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addDust((*reinterpret_cast< std::add_pointer_t<Dust>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->addWind((*reinterpret_cast< std::add_pointer_t<Wind>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->addTermometer((*reinterpret_cast< std::add_pointer_t<Termometer>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->addHumidity((*reinterpret_cast< std::add_pointer_t<Humidity>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->addAirQuality((*reinterpret_cast< std::add_pointer_t<AirQuality>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->remove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->updateDust((*reinterpret_cast< std::add_pointer_t<Dust>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->updateWind((*reinterpret_cast< std::add_pointer_t<Wind>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->updateTermometer((*reinterpret_cast< std::add_pointer_t<Termometer>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->updateHumidity((*reinterpret_cast< std::add_pointer_t<Humidity>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->updateAirQuality((*reinterpret_cast< std::add_pointer_t<AirQuality>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SimBarVisitor::*)(const Dust & , int , int );
            if (_t _q_method = &SimBarVisitor::addDust; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Wind & , int , int );
            if (_t _q_method = &SimBarVisitor::addWind; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Termometer & , int , int );
            if (_t _q_method = &SimBarVisitor::addTermometer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Humidity & , int , int );
            if (_t _q_method = &SimBarVisitor::addHumidity; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const AirQuality & , int , int );
            if (_t _q_method = &SimBarVisitor::addAirQuality; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(int );
            if (_t _q_method = &SimBarVisitor::remove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Dust & , int , int );
            if (_t _q_method = &SimBarVisitor::updateDust; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Wind & , int , int );
            if (_t _q_method = &SimBarVisitor::updateWind; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Termometer & , int , int );
            if (_t _q_method = &SimBarVisitor::updateTermometer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const Humidity & , int , int );
            if (_t _q_method = &SimBarVisitor::updateHumidity; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SimBarVisitor::*)(const AirQuality & , int , int );
            if (_t _q_method = &SimBarVisitor::updateAirQuality; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject SimBarVisitor::staticMetaObject = { {
    QMetaObject::SuperData::link<Visitor::staticMetaObject>(),
    qt_meta_stringdata_SimBarVisitor.offsetsAndSizes,
    qt_meta_data_SimBarVisitor,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SimBarVisitor_t
, QtPrivate::TypeAndForceComplete<SimBarVisitor, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Dust &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Wind &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Termometer &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Humidity &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const AirQuality &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Dust &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Wind &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Termometer &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Humidity &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const AirQuality &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>



>,
    nullptr
} };


const QMetaObject *SimBarVisitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimBarVisitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimBarVisitor.stringdata0))
        return static_cast<void*>(this);
    return Visitor::qt_metacast(_clname);
}

int SimBarVisitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Visitor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SimBarVisitor::addDust(const Dust & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimBarVisitor::addWind(const Wind & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SimBarVisitor::addTermometer(const Termometer & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SimBarVisitor::addHumidity(const Humidity & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SimBarVisitor::addAirQuality(const AirQuality & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SimBarVisitor::remove(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SimBarVisitor::updateDust(const Dust & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SimBarVisitor::updateWind(const Wind & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SimBarVisitor::updateTermometer(const Termometer & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SimBarVisitor::updateHumidity(const Humidity & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SimBarVisitor::updateAirQuality(const AirQuality & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
