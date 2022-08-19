/****************************************************************************
** Meta object code from reading C++ file 'PolarVectorscope.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Charts/PolarVectorscope.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PolarVectorscope.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PolarVectorscope_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolarVectorscope_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolarVectorscope_t qt_meta_stringdata_PolarVectorscope = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PolarVectorscope"
QT_MOC_LITERAL(1, 17, 15), // "drawVectorscope"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "AudioChannel*"
QT_MOC_LITERAL(4, 48, 7), // "channel"
QT_MOC_LITERAL(5, 56, 12), // "dataReceiver"
QT_MOC_LITERAL(6, 69, 14) // "ADataReceiver*"

    },
    "PolarVectorscope\0drawVectorscope\0\0"
    "AudioChannel*\0channel\0dataReceiver\0"
    "ADataReceiver*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolarVectorscope[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00095409,

       0        // eod
};

void PolarVectorscope::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PolarVectorscope *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->drawVectorscope((*reinterpret_cast< AudioChannel*(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PolarVectorscope *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ADataReceiver**>(_v) = _t->getDataReceiver(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PolarVectorscope::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_PolarVectorscope.data,
    qt_meta_data_PolarVectorscope,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PolarVectorscope::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolarVectorscope::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolarVectorscope.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ADataReceiver"))
        return static_cast< ADataReceiver*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int PolarVectorscope::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_VectroscopeDrawerSlots_t {
    QByteArrayData data[5];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VectroscopeDrawerSlots_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VectroscopeDrawerSlots_t qt_meta_stringdata_VectroscopeDrawerSlots = {
    {
QT_MOC_LITERAL(0, 0, 22), // "VectroscopeDrawerSlots"
QT_MOC_LITERAL(1, 23, 17), // "dataUpdateChannel"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 13), // "AudioChannel*"
QT_MOC_LITERAL(4, 56, 7) // "channel"

    },
    "VectroscopeDrawerSlots\0dataUpdateChannel\0"
    "\0AudioChannel*\0channel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VectroscopeDrawerSlots[] = {

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
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void VectroscopeDrawerSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VectroscopeDrawerSlots *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataUpdateChannel((*reinterpret_cast< AudioChannel*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VectroscopeDrawerSlots::staticMetaObject = { {
    QMetaObject::SuperData::link<ADataReceiverSlots::staticMetaObject>(),
    qt_meta_stringdata_VectroscopeDrawerSlots.data,
    qt_meta_data_VectroscopeDrawerSlots,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VectroscopeDrawerSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VectroscopeDrawerSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VectroscopeDrawerSlots.stringdata0))
        return static_cast<void*>(this);
    return ADataReceiverSlots::qt_metacast(_clname);
}

int VectroscopeDrawerSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
