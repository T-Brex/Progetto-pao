/****************************************************************************
** Meta object code from reading C++ file 'searchMenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frontend/searchMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchMenu_t {
    uint offsetsAndSizes[20];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SearchMenu_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_SearchMenu_t qt_meta_stringdata_SearchMenu = {
    {
        QT_MOC_LITERAL(0, 10),  // "SearchMenu"
        QT_MOC_LITERAL(11, 13),  // "showAddDialog"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 16),  // "showDeleteDialog"
        QT_MOC_LITERAL(43, 16),  // "showSaveAsDialog"
        QT_MOC_LITERAL(60, 19),  // "showDeleteAllDialog"
        QT_MOC_LITERAL(80, 16),  // "showImportDialog"
        QT_MOC_LITERAL(97, 16),  // "showModifyDialog"
        QT_MOC_LITERAL(114, 13),  // "const Sensor*"
        QT_MOC_LITERAL(128, 6)   // "sensor"
    },
    "SearchMenu\0showAddDialog\0\0showDeleteDialog\0"
    "showSaveAsDialog\0showDeleteAllDialog\0"
    "showImportDialog\0showModifyDialog\0"
    "const Sensor*\0sensor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchMenu[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,
       5,    0,   53,    2, 0x06,    4 /* Public */,
       6,    0,   54,    2, 0x06,    5 /* Public */,
       7,    1,   55,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void SearchMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showAddDialog(); break;
        case 1: _t->showDeleteDialog(); break;
        case 2: _t->showSaveAsDialog(); break;
        case 3: _t->showDeleteAllDialog(); break;
        case 4: _t->showImportDialog(); break;
        case 5: _t->showModifyDialog((*reinterpret_cast< std::add_pointer_t<const Sensor*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchMenu::*)();
            if (_t _q_method = &SearchMenu::showAddDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SearchMenu::*)();
            if (_t _q_method = &SearchMenu::showDeleteDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SearchMenu::*)();
            if (_t _q_method = &SearchMenu::showSaveAsDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SearchMenu::*)();
            if (_t _q_method = &SearchMenu::showDeleteAllDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SearchMenu::*)();
            if (_t _q_method = &SearchMenu::showImportDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SearchMenu::*)(const Sensor * );
            if (_t _q_method = &SearchMenu::showModifyDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject SearchMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SearchMenu.offsetsAndSizes,
    qt_meta_data_SearchMenu,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SearchMenu_t
, QtPrivate::TypeAndForceComplete<SearchMenu, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Sensor *, std::false_type>



>,
    nullptr
} };


const QMetaObject *SearchMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SearchMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SearchMenu::showAddDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SearchMenu::showDeleteDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SearchMenu::showSaveAsDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SearchMenu::showDeleteAllDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SearchMenu::showImportDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SearchMenu::showModifyDialog(const Sensor * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
