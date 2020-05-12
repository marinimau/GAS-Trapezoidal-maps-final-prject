/****************************************************************************
** Meta object code from reading C++ file 'drawable_container.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../GAS_2020_TrapezoidalMaps/cg3lib/cg3/viewer/interfaces/drawable_container.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawable_container.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cg3__DrawableContainer_t {
    QByteArrayData data[7];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cg3__DrawableContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cg3__DrawableContainer_t qt_meta_stringdata_cg3__DrawableContainer = {
    {
QT_MOC_LITERAL(0, 0, 22), // "cg3::DrawableContainer"
QT_MOC_LITERAL(1, 23, 29), // "drawableContainerPushedObject"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 11), // "std::string"
QT_MOC_LITERAL(4, 66, 29), // "drawableContainerErasedObject"
QT_MOC_LITERAL(5, 96, 21), // "const DrawableObject*"
QT_MOC_LITERAL(6, 118, 40) // "drawableContainerVisibilityOb..."

    },
    "cg3::DrawableContainer\0"
    "drawableContainerPushedObject\0\0"
    "std::string\0drawableContainerErasedObject\0"
    "const DrawableObject*\0"
    "drawableContainerVisibilityObjectChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cg3__DrawableContainer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       4,    1,   34,    2, 0x06 /* Public */,
       6,    2,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Bool,    2,    2,

       0        // eod
};

void cg3::DrawableContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawableContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawableContainerPushedObject((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->drawableContainerErasedObject((*reinterpret_cast< const DrawableObject*(*)>(_a[1]))); break;
        case 2: _t->drawableContainerVisibilityObjectChanged((*reinterpret_cast< const DrawableObject*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DrawableContainer::*)(const std::string & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawableContainer::drawableContainerPushedObject)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DrawableContainer::*)(const DrawableObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawableContainer::drawableContainerErasedObject)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DrawableContainer::*)(const DrawableObject * , bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrawableContainer::drawableContainerVisibilityObjectChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cg3::DrawableContainer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cg3__DrawableContainer.data,
    qt_meta_data_cg3__DrawableContainer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cg3::DrawableContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cg3::DrawableContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cg3__DrawableContainer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "DrawableObject"))
        return static_cast< DrawableObject*>(this);
    return QObject::qt_metacast(_clname);
}

int cg3::DrawableContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void cg3::DrawableContainer::drawableContainerPushedObject(const std::string & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cg3::DrawableContainer::drawableContainerErasedObject(const DrawableObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cg3::DrawableContainer::drawableContainerVisibilityObjectChanged(const DrawableObject * _t1, bool _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< cg3::DrawableContainer *>(this), &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
