/****************************************************************************
** Meta object code from reading C++ file 'drawable_mesh_drawlist_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GAS_2020_TrapezoidalMaps/cg3lib/cg3/viewer/internal/drawable_mesh_drawlist_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawable_mesh_drawlist_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cg3__viewer__DrawableMeshDrawListManager_t {
    QByteArrayData data[16];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cg3__viewer__DrawableMeshDrawListManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cg3__viewer__DrawableMeshDrawListManager_t qt_meta_stringdata_cg3__viewer__DrawableMeshDrawListManager = {
    {
QT_MOC_LITERAL(0, 0, 40), // "cg3::viewer::DrawableMeshDraw..."
QT_MOC_LITERAL(1, 41, 28), // "on_pointsRadioButton_toggled"
QT_MOC_LITERAL(2, 70, 0), // ""
QT_MOC_LITERAL(3, 71, 7), // "checked"
QT_MOC_LITERAL(4, 79, 26), // "on_flatRadioButton_toggled"
QT_MOC_LITERAL(5, 106, 28), // "on_smoothRadioButton_toggled"
QT_MOC_LITERAL(6, 135, 33), // "on_wireframeCheckBox_stateCha..."
QT_MOC_LITERAL(7, 169, 4), // "arg1"
QT_MOC_LITERAL(8, 174, 28), // "on_bboxCheckBox_stateChanged"
QT_MOC_LITERAL(9, 203, 28), // "on_vColorRadioButton_toggled"
QT_MOC_LITERAL(10, 232, 28), // "on_tColorRadioButton_toggled"
QT_MOC_LITERAL(11, 261, 25), // "on_savePushButton_clicked"
QT_MOC_LITERAL(12, 287, 36), // "on_subFrameAxisCheckBox_state..."
QT_MOC_LITERAL(13, 324, 36), // "on_wireframeWidthSlider_value..."
QT_MOC_LITERAL(14, 361, 5), // "value"
QT_MOC_LITERAL(15, 367, 32) // "on_pointWidthSlider_valueChanged"

    },
    "cg3::viewer::DrawableMeshDrawListManager\0"
    "on_pointsRadioButton_toggled\0\0checked\0"
    "on_flatRadioButton_toggled\0"
    "on_smoothRadioButton_toggled\0"
    "on_wireframeCheckBox_stateChanged\0"
    "arg1\0on_bboxCheckBox_stateChanged\0"
    "on_vColorRadioButton_toggled\0"
    "on_tColorRadioButton_toggled\0"
    "on_savePushButton_clicked\0"
    "on_subFrameAxisCheckBox_stateChanged\0"
    "on_wireframeWidthSlider_valueChanged\0"
    "value\0on_pointWidthSlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cg3__viewer__DrawableMeshDrawListManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    1,   75,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    1,   91,    2, 0x08 /* Private */,
      13,    1,   94,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void cg3::viewer::DrawableMeshDrawListManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawableMeshDrawListManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pointsRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_flatRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_smoothRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_wireframeCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_bboxCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_vColorRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_tColorRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_savePushButton_clicked(); break;
        case 8: _t->on_subFrameAxisCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_wireframeWidthSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pointWidthSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cg3::viewer::DrawableMeshDrawListManager::staticMetaObject = { {
    &SubManager::staticMetaObject,
    qt_meta_stringdata_cg3__viewer__DrawableMeshDrawListManager.data,
    qt_meta_data_cg3__viewer__DrawableMeshDrawListManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cg3::viewer::DrawableMeshDrawListManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cg3::viewer::DrawableMeshDrawListManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cg3__viewer__DrawableMeshDrawListManager.stringdata0))
        return static_cast<void*>(this);
    return SubManager::qt_metacast(_clname);
}

int cg3::viewer::DrawableMeshDrawListManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
