/****************************************************************************
** Meta object code from reading C++ file 'LinearIndicator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Charts/LinearIndicator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LinearIndicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LinearDirection_t {
    QByteArrayData data[4];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinearDirection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinearDirection_t qt_meta_stringdata_LinearDirection = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LinearDirection"
QT_MOC_LITERAL(1, 16, 9), // "Direction"
QT_MOC_LITERAL(2, 26, 8), // "Vertical"
QT_MOC_LITERAL(3, 35, 10) // "Horizontal"

    },
    "LinearDirection\0Direction\0Vertical\0"
    "Horizontal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinearDirection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    2,   19,

 // enum data: key, value
       2, uint(LinearDirection::Vertical),
       3, uint(LinearDirection::Horizontal),

       0        // eod
};

void LinearDirection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject LinearDirection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LinearDirection.data,
    qt_meta_data_LinearDirection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LinearDirection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinearDirection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LinearDirection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LinearDirection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LinearIndicator_t {
    QByteArrayData data[14];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinearIndicator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinearIndicator_t qt_meta_stringdata_LinearIndicator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LinearIndicator"
QT_MOC_LITERAL(1, 16, 22), // "foregroundColorChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 22), // "backgroundColorChanged"
QT_MOC_LITERAL(4, 63, 25), // "foregroundGradientChanged"
QT_MOC_LITERAL(5, 89, 25), // "backgroundGradientChanged"
QT_MOC_LITERAL(6, 115, 14), // "rawDataChanged"
QT_MOC_LITERAL(7, 130, 10), // "dataUpdate"
QT_MOC_LITERAL(8, 141, 13), // "MinMax<float>"
QT_MOC_LITERAL(9, 155, 5), // "range"
QT_MOC_LITERAL(10, 161, 15), // "foregroundColor"
QT_MOC_LITERAL(11, 177, 15), // "backgroundColor"
QT_MOC_LITERAL(12, 193, 18), // "foregroundGradient"
QT_MOC_LITERAL(13, 212, 18) // "backgroundGradient"

    },
    "LinearIndicator\0foregroundColorChanged\0"
    "\0backgroundColorChanged\0"
    "foregroundGradientChanged\0"
    "backgroundGradientChanged\0rawDataChanged\0"
    "dataUpdate\0MinMax<float>\0range\0"
    "foregroundColor\0backgroundColor\0"
    "foregroundGradient\0backgroundGradient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinearIndicator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,

 // properties: name, type, flags
      10, QMetaType::QColor, 0x00495103,
      11, QMetaType::QColor, 0x00495103,
      12, QMetaType::QVariantList, 0x00095102,
      13, QMetaType::QVariantList, 0x00095102,

 // properties: notify_signal_id
       0,
       1,
       0,
       0,

       0        // eod
};

void LinearIndicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LinearIndicator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->foregroundColorChanged(); break;
        case 1: _t->backgroundColorChanged(); break;
        case 2: _t->foregroundGradientChanged(); break;
        case 3: _t->backgroundGradientChanged(); break;
        case 4: _t->rawDataChanged(); break;
        case 5: _t->dataUpdate((*reinterpret_cast< MinMax<float>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LinearIndicator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearIndicator::foregroundColorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LinearIndicator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearIndicator::backgroundColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LinearIndicator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearIndicator::foregroundGradientChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LinearIndicator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearIndicator::backgroundGradientChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LinearIndicator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LinearIndicator::rawDataChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LinearIndicator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->getForegroundColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getBackgroundColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<LinearIndicator *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setForegroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setForegroundGradient(*reinterpret_cast< QVariantList*>(_v)); break;
        case 3: _t->setBackgroundGradient(*reinterpret_cast< QVariantList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject LinearIndicator::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_LinearIndicator.data,
    qt_meta_data_LinearIndicator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LinearIndicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinearIndicator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LinearIndicator.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int LinearIndicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LinearIndicator::foregroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LinearIndicator::backgroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LinearIndicator::foregroundGradientChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LinearIndicator::backgroundGradientChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LinearIndicator::rawDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
