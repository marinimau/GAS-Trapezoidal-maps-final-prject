/****************************************************************************
** Meta object code from reading C++ file 'drawable_container_drawlist_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GAS_2020_TrapezoidalMaps/cg3lib/cg3/viewer/internal/drawable_container_drawlist_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawable_container_drawlist_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cg3__viewer__DrawableContainerDrawListManager_t {
    QByteArrayData data[13];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cg3__viewer__DrawableContainerDrawListManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cg3__viewer__DrawableContainerDrawListManager_t qt_meta_stringdata_cg3__viewer__DrawableContainerDrawListManager = {
    {
QT_MOC_LITERAL(0, 0, 45), // "cg3::viewer::DrawableContaine..."
QT_MOC_LITERAL(1, 46, 30), // "addCheckBoxOfDrawableContainer"
QT_MOC_LITERAL(2, 77, 0), // ""
QT_MOC_LITERAL(3, 78, 11), // "std::string"
QT_MOC_LITERAL(4, 90, 4), // "name"
QT_MOC_LITERAL(5, 95, 7), // "visible"
QT_MOC_LITERAL(6, 103, 33), // "removeCheckBoxOfDrawableConta..."
QT_MOC_LITERAL(7, 137, 21), // "const DrawableObject*"
QT_MOC_LITERAL(8, 159, 3), // "obj"
QT_MOC_LITERAL(9, 163, 22), // "changeVisibilityObject"
QT_MOC_LITERAL(10, 186, 3), // "vis"
QT_MOC_LITERAL(11, 190, 24), // "on_visibleButton_clicked"
QT_MOC_LITERAL(12, 215, 23) // "on_hiddenButton_clicked"

    },
    "cg3::viewer::DrawableContainerDrawListManager\0"
    "addCheckBoxOfDrawableContainer\0\0"
    "std::string\0name\0visible\0"
    "removeCheckBoxOfDrawableContainer\0"
    "const DrawableObject*\0obj\0"
    "changeVisibilityObject\0vis\0"
    "on_visibleButton_clicked\0"
    "on_hiddenButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cg3__viewer__DrawableContainerDrawListManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       9,    2,   47,    2, 0x08 /* Private */,
      11,    0,   52,    2, 0x08 /* Private */,
      12,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cg3::viewer::DrawableContainerDrawListManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawableContainerDrawListManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addCheckBoxOfDrawableContainer((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->removeCheckBoxOfDrawableContainer((*reinterpret_cast< const DrawableObject*(*)>(_a[1]))); break;
        case 2: _t->changeVisibilityObject((*reinterpret_cast< const DrawableObject*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->on_visibleButton_clicked(); break;
        case 4: _t->on_hiddenButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cg3::viewer::DrawableContainerDrawListManager::staticMetaObject = { {
    &SubManager::staticMetaObject,
    qt_meta_stringdata_cg3__viewer__DrawableContainerDrawListManager.data,
    qt_meta_data_cg3__viewer__DrawableContainerDrawListManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cg3::viewer::DrawableContainerDrawListManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cg3::viewer::DrawableContainerDrawListManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cg3__viewer__DrawableContainerDrawListManager.stringdata0))
        return static_cast<void*>(this);
    return SubManager::qt_metacast(_clname);
}

int cg3::viewer::DrawableContainerDrawListManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
