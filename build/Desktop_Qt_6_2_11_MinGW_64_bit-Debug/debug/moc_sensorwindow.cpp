/****************************************************************************
** Meta object code from reading C++ file 'sensorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frontend/sensorwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sensorWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_sensorWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_sensorWindow_t qt_meta_stringdata_sensorWindow = {
    {
        QT_MOC_LITERAL(0, 12),  // "sensorWindow"
        QT_MOC_LITERAL(13, 9),  // "addSensor"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 7),  // "Sensor*"
        QT_MOC_LITERAL(32, 1),  // "s"
        QT_MOC_LITERAL(34, 12),  // "modifySensor"
        QT_MOC_LITERAL(47, 7),  // "oldName"
        QT_MOC_LITERAL(55, 7),  // "newName"
        QT_MOC_LITERAL(63, 7),  // "newType"
        QT_MOC_LITERAL(71, 12),  // "deleteSensor"
        QT_MOC_LITERAL(84, 16),  // "deleteAllSensors"
        QT_MOC_LITERAL(101, 13),  // "filterSensors"
        QT_MOC_LITERAL(115, 10)   // "searchText"
    },
    "sensorWindow\0addSensor\0\0Sensor*\0s\0"
    "modifySensor\0oldName\0newName\0newType\0"
    "deleteSensor\0deleteAllSensors\0"
    "filterSensors\0searchText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sensorWindow[] = {

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
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       5,    3,   47,    2, 0x0a,    3 /* Public */,
       9,    1,   54,    2, 0x0a,    7 /* Public */,
      10,    0,   57,    2, 0x0a,    9 /* Public */,
      11,    1,   58,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void sensorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sensorWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addSensor((*reinterpret_cast< std::add_pointer_t<Sensor*>>(_a[1]))); break;
        case 1: _t->modifySensor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->deleteSensor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->deleteAllSensors(); break;
        case 4: _t->filterSensors((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject sensorWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_sensorWindow.offsetsAndSizes,
    qt_meta_data_sensorWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_sensorWindow_t
, QtPrivate::TypeAndForceComplete<sensorWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Sensor *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *sensorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sensorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sensorWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int sensorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
