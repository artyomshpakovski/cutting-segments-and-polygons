/****************************************************************************
** Meta object code from reading C++ file 'cuttingpolygons.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab_5_3/cuttingpolygons.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cuttingpolygons.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CuttingPolygons_t {
    QByteArrayData data[17];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CuttingPolygons_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CuttingPolygons_t qt_meta_stringdata_CuttingPolygons = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CuttingPolygons"
QT_MOC_LITERAL(1, 16, 12), // "intersection"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "x1"
QT_MOC_LITERAL(4, 33, 2), // "y1"
QT_MOC_LITERAL(5, 36, 2), // "x2"
QT_MOC_LITERAL(6, 39, 2), // "y2"
QT_MOC_LITERAL(7, 42, 2), // "x3"
QT_MOC_LITERAL(8, 45, 2), // "y3"
QT_MOC_LITERAL(9, 48, 2), // "x4"
QT_MOC_LITERAL(10, 51, 2), // "y4"
QT_MOC_LITERAL(11, 54, 8), // "drawPlot"
QT_MOC_LITERAL(12, 63, 17), // "midpointAlgorithm"
QT_MOC_LITERAL(13, 81, 4), // "xmin"
QT_MOC_LITERAL(14, 86, 4), // "ymin"
QT_MOC_LITERAL(15, 91, 4), // "xmax"
QT_MOC_LITERAL(16, 96, 4) // "ymax"

    },
    "CuttingPolygons\0intersection\0\0x1\0y1\0"
    "x2\0y2\0x3\0y3\0x4\0y4\0drawPlot\0midpointAlgorithm\0"
    "xmin\0ymin\0xmax\0ymax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CuttingPolygons[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    8,   29,    2, 0x08 /* Private */,
      11,    0,   46,    2, 0x08 /* Private */,
      12,    8,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,   13,   14,   15,   16,

       0        // eod
};

void CuttingPolygons::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CuttingPolygons *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->intersection((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->drawPlot(); break;
        case 2: _t->midpointAlgorithm((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CuttingPolygons::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CuttingPolygons.data,
    qt_meta_data_CuttingPolygons,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CuttingPolygons::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CuttingPolygons::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CuttingPolygons.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CuttingPolygons::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
