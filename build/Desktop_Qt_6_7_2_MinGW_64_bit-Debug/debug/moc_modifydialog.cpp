/****************************************************************************
** Meta object code from reading C++ file 'modifydialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/modifydialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSModifyDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSModifyDialogENDCLASS = QtMocHelpers::stringData(
<<<<<<< HEAD
    "ModifyDialog"
=======
    "ModifyDialog",
    "onSceltaTipoChanged",
    ""
>>>>>>> 5cca1299b97e7a0bb260807bdee161a5baa294d9
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSModifyDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       0,    0, // methods
=======
       1,   14, // methods
>>>>>>> 5cca1299b97e7a0bb260807bdee161a5baa294d9
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

<<<<<<< HEAD
=======
 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

>>>>>>> 5cca1299b97e7a0bb260807bdee161a5baa294d9
       0        // eod
};

Q_CONSTINIT const QMetaObject ModifyDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<AddDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSModifyDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSModifyDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSModifyDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
<<<<<<< HEAD
        QtPrivate::TypeAndForceComplete<ModifyDialog, std::true_type>
=======
        QtPrivate::TypeAndForceComplete<ModifyDialog, std::true_type>,
        // method 'onSceltaTipoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
>>>>>>> 5cca1299b97e7a0bb260807bdee161a5baa294d9
    >,
    nullptr
} };

void ModifyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
<<<<<<< HEAD
    (void)_o;
    (void)_id;
    (void)_c;
=======
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModifyDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSceltaTipoChanged(); break;
        default: ;
        }
    }
>>>>>>> 5cca1299b97e7a0bb260807bdee161a5baa294d9
    (void)_a;
}

const QMetaObject *ModifyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModifyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSModifyDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AddDialog::qt_metacast(_clname);
}

int ModifyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AddDialog::qt_metacall(_c, _id, _a);
<<<<<<< HEAD
=======
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
>>>>>>> 5cca1299b97e7a0bb260807bdee161a5baa294d9
    return _id;
}
QT_WARNING_POP
