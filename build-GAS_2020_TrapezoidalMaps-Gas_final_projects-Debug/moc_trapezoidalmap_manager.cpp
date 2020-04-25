/****************************************************************************
** Meta object code from reading C++ file 'trapezoidalmap_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GAS_2020_TrapezoidalMaps/managers/trapezoidalmap_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trapezoidalmap_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrapezoidalMapManager_t {
    QByteArrayData data[12];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrapezoidalMapManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrapezoidalMapManager_t qt_meta_stringdata_TrapezoidalMapManager = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TrapezoidalMapManager"
QT_MOC_LITERAL(1, 22, 14), // "point2DClicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "cg3::Point2d"
QT_MOC_LITERAL(4, 51, 1), // "p"
QT_MOC_LITERAL(5, 53, 29), // "on_loadSegmentsButton_clicked"
QT_MOC_LITERAL(6, 83, 31), // "on_randomSegmentsButton_clicked"
QT_MOC_LITERAL(7, 115, 29), // "on_saveSegmentsButton_clicked"
QT_MOC_LITERAL(8, 145, 26), // "on_addSegmentRadio_clicked"
QT_MOC_LITERAL(9, 172, 21), // "on_queryRadio_clicked"
QT_MOC_LITERAL(10, 194, 30), // "on_clearSegmentsButton_clicked"
QT_MOC_LITERAL(11, 225, 27) // "on_resetSceneButton_clicked"

    },
    "TrapezoidalMapManager\0point2DClicked\0"
    "\0cg3::Point2d\0p\0on_loadSegmentsButton_clicked\0"
    "on_randomSegmentsButton_clicked\0"
    "on_saveSegmentsButton_clicked\0"
    "on_addSegmentRadio_clicked\0"
    "on_queryRadio_clicked\0"
    "on_clearSegmentsButton_clicked\0"
    "on_resetSceneButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrapezoidalMapManager[] = {

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
       1,    1,   54,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TrapezoidalMapManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrapezoidalMapManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->point2DClicked((*reinterpret_cast< cg3::Point2d(*)>(_a[1]))); break;
        case 1: _t->on_loadSegmentsButton_clicked(); break;
        case 2: _t->on_randomSegmentsButton_clicked(); break;
        case 3: _t->on_saveSegmentsButton_clicked(); break;
        case 4: _t->on_addSegmentRadio_clicked(); break;
        case 5: _t->on_queryRadio_clicked(); break;
        case 6: _t->on_clearSegmentsButton_clicked(); break;
        case 7: _t->on_resetSceneButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TrapezoidalMapManager::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_TrapezoidalMapManager.data,
    qt_meta_data_TrapezoidalMapManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TrapezoidalMapManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrapezoidalMapManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrapezoidalMapManager.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int TrapezoidalMapManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
