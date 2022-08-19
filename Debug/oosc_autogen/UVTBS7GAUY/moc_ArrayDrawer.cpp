/****************************************************************************
** Meta object code from reading C++ file 'ArrayDrawer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Charts/ArrayDrawer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ArrayDrawer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArrayDrawer_t {
    QByteArrayData data[18];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArrayDrawer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArrayDrawer_t qt_meta_stringdata_ArrayDrawer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ArrayDrawer"
QT_MOC_LITERAL(1, 12, 16), // "lineColorChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "lineGradientChanged"
QT_MOC_LITERAL(4, 50, 22), // "backgroundColorChanged"
QT_MOC_LITERAL(5, 73, 25), // "backgroundGradientChanged"
QT_MOC_LITERAL(6, 99, 22), // "centerLineColorChanged"
QT_MOC_LITERAL(7, 122, 14), // "rawDataChanged"
QT_MOC_LITERAL(8, 137, 15), // "setLineGradient"
QT_MOC_LITERAL(9, 153, 12), // "lineGradient"
QT_MOC_LITERAL(10, 166, 21), // "setBackgroundGradient"
QT_MOC_LITERAL(11, 188, 18), // "backgroundGradient"
QT_MOC_LITERAL(12, 207, 9), // "lineColor"
QT_MOC_LITERAL(13, 217, 15), // "backgroundColor"
QT_MOC_LITERAL(14, 233, 15), // "centerLineColor"
QT_MOC_LITERAL(15, 249, 12), // "drawGradient"
QT_MOC_LITERAL(16, 262, 12), // "dataReceiver"
QT_MOC_LITERAL(17, 275, 14) // "ADataReceiver*"

    },
    "ArrayDrawer\0lineColorChanged\0\0"
    "lineGradientChanged\0backgroundColorChanged\0"
    "backgroundGradientChanged\0"
    "centerLineColorChanged\0rawDataChanged\0"
    "setLineGradient\0lineGradient\0"
    "setBackgroundGradient\0backgroundGradient\0"
    "lineColor\0backgroundColor\0centerLineColor\0"
    "drawGradient\0dataReceiver\0ADataReceiver*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArrayDrawer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       5,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    1,   60,    2, 0x02 /* Public */,
      10,    1,   63,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantList,    9,
    QMetaType::Void, QMetaType::QVariantList,   11,

 // properties: name, type, flags
      12, QMetaType::QColor, 0x00495103,
      13, QMetaType::QColor, 0x00495103,
      14, QMetaType::QColor, 0x00495103,
      15, QMetaType::Bool, 0x00095102,
      16, 0x80000000 | 17, 0x00095409,

 // properties: notify_signal_id
       0,
       2,
       4,
       0,
       0,

       0        // eod
};

void ArrayDrawer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArrayDrawer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->lineColorChanged(); break;
        case 1: _t->lineGradientChanged(); break;
        case 2: _t->backgroundColorChanged(); break;
        case 3: _t->backgroundGradientChanged(); break;
        case 4: _t->centerLineColorChanged(); break;
        case 5: _t->rawDataChanged(); break;
        case 6: _t->setLineGradient((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 7: _t->setBackgroundGradient((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArrayDrawer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArrayDrawer::lineColorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ArrayDrawer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArrayDrawer::lineGradientChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArrayDrawer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArrayDrawer::backgroundColorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ArrayDrawer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArrayDrawer::backgroundGradientChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ArrayDrawer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArrayDrawer::centerLineColorChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ArrayDrawer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArrayDrawer::rawDataChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ArrayDrawer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->getLineColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getBackgroundColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getCenterLineColor(); break;
        case 4: *reinterpret_cast< ADataReceiver**>(_v) = _t->getDataReceiver(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ArrayDrawer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setCenterLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setDrawGradient(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ArrayDrawer::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_ArrayDrawer.data,
    qt_meta_data_ArrayDrawer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArrayDrawer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArrayDrawer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArrayDrawer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ADataReceiver"))
        return static_cast< ADataReceiver*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int ArrayDrawer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ArrayDrawer::lineColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ArrayDrawer::lineGradientChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ArrayDrawer::backgroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ArrayDrawer::backgroundGradientChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ArrayDrawer::centerLineColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ArrayDrawer::rawDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
struct qt_meta_stringdata_ArrayDrawerSlots_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArrayDrawerSlots_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArrayDrawerSlots_t qt_meta_stringdata_ArrayDrawerSlots = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ArrayDrawerSlots"
QT_MOC_LITERAL(1, 17, 10), // "dataUpdate"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "std::vector<float>"
QT_MOC_LITERAL(4, 48, 4), // "data"
QT_MOC_LITERAL(5, 53, 34), // "std::vector<float>::const_ite..."
QT_MOC_LITERAL(6, 88, 4), // "from"
QT_MOC_LITERAL(7, 93, 2) // "to"

    },
    "ArrayDrawerSlots\0dataUpdate\0\0"
    "std::vector<float>\0data\0"
    "std::vector<float>::const_iterator\0"
    "from\0to"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArrayDrawerSlots[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,

       0        // eod
};

void ArrayDrawerSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArrayDrawerSlots *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataUpdate((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ArrayDrawerSlots::staticMetaObject = { {
    QMetaObject::SuperData::link<ADataReceiverSlots::staticMetaObject>(),
    qt_meta_stringdata_ArrayDrawerSlots.data,
    qt_meta_data_ArrayDrawerSlots,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArrayDrawerSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArrayDrawerSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArrayDrawerSlots.stringdata0))
        return static_cast<void*>(this);
    return ADataReceiverSlots::qt_metacast(_clname);
}

int ArrayDrawerSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ADataReceiverSlots::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
