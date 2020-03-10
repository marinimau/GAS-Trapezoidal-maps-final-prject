/****************************************************************************
** Meta object code from reading C++ file 'drawable_object_drawlist_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GAS_2020_TrapezoidalMaps/cg3lib/cg3/viewer/internal/drawable_object_drawlist_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawable_object_drawlist_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cg3__viewer__DrawableObjectDrawListManager_t {
    QByteArrayData data[13];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cg3__viewer__DrawableObjectDrawListManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cg3__viewer__DrawableObjectDrawListManager_t qt_meta_stringdata_cg3__viewer__DrawableObjectDrawListManager = {
    {
QT_MOC_LITERAL(0, 0, 42), // "cg3::viewer::DrawableObjectDr..."
QT_MOC_LITERAL(1, 43, 11), // "setSubFrame"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 11), // "SubManager*"
QT_MOC_LITERAL(4, 68, 5), // "frame"
QT_MOC_LITERAL(5, 74, 3), // "vis"
QT_MOC_LITERAL(6, 78, 21), // "setSubFrameVisibility"
QT_MOC_LITERAL(7, 100, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(8, 125, 5), // "state"
QT_MOC_LITERAL(9, 131, 26), // "on_closePushButton_clicked"
QT_MOC_LITERAL(10, 158, 32), // "on_subFrameCheckBox_stateChanged"
QT_MOC_LITERAL(11, 191, 21), // "on_objectName_clicked"
QT_MOC_LITERAL(12, 213, 21) // "on_objectType_clicked"

    },
    "cg3::viewer::DrawableObjectDrawListManager\0"
    "setSubFrame\0\0SubManager*\0frame\0vis\0"
    "setSubFrameVisibility\0on_checkBox_stateChanged\0"
    "state\0on_closePushButton_clicked\0"
    "on_subFrameCheckBox_stateChanged\0"
    "on_objectName_clicked\0on_objectType_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cg3__viewer__DrawableObjectDrawListManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x08 /* Private */,
       1,    1,   59,    2, 0x28 /* Private | MethodCloned */,
       6,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cg3::viewer::DrawableObjectDrawListManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawableObjectDrawListManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSubFrame((*reinterpret_cast< SubManager*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setSubFrame((*reinterpret_cast< SubManager*(*)>(_a[1]))); break;
        case 2: _t->setSubFrameVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_closePushButton_clicked(); break;
        case 5: _t->on_subFrameCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_objectName_clicked(); break;
        case 7: _t->on_objectType_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cg3::viewer::DrawableObjectDrawListManager::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_cg3__viewer__DrawableObjectDrawListManager.data,
    qt_meta_data_cg3__viewer__DrawableObjectDrawListManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cg3::viewer::DrawableObjectDrawListManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cg3::viewer::DrawableObjectDrawListManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cg3__viewer__DrawableObjectDrawListManager.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int cg3::viewer::DrawableObjectDrawListManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
