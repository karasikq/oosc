/****************************************************************************
** Meta object code from reading C++ file 'LfoController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/LfoController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LfoController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LfoController_t {
    QByteArrayData data[20];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LfoController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LfoController_t qt_meta_stringdata_LfoController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LfoController"
QT_MOC_LITERAL(1, 14, 15), // "lfoValueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "value"
QT_MOC_LITERAL(4, 37, 15), // "lfoShapeChanged"
QT_MOC_LITERAL(5, 53, 18), // "std::vector<float>"
QT_MOC_LITERAL(6, 72, 4), // "data"
QT_MOC_LITERAL(7, 77, 34), // "std::vector<float>::const_ite..."
QT_MOC_LITERAL(8, 112, 4), // "from"
QT_MOC_LITERAL(9, 117, 2), // "to"
QT_MOC_LITERAL(10, 120, 5), // "phase"
QT_MOC_LITERAL(11, 126, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(12, 148, 9), // "frequency"
QT_MOC_LITERAL(13, 158, 9), // "waveshape"
QT_MOC_LITERAL(14, 168, 6), // "sender"
QT_MOC_LITERAL(15, 175, 13), // "AValueSender*"
QT_MOC_LITERAL(16, 189, 6), // "drawer"
QT_MOC_LITERAL(17, 196, 14), // "ADataReceiver*"
QT_MOC_LITERAL(18, 211, 12), // "timeReceiver"
QT_MOC_LITERAL(19, 224, 14) // "ITimeReceiver*"

    },
    "LfoController\0lfoValueChanged\0\0value\0"
    "lfoShapeChanged\0std::vector<float>\0"
    "data\0std::vector<float>::const_iterator\0"
    "from\0to\0phase\0IChangeableParameter*\0"
    "frequency\0waveshape\0sender\0AValueSender*\0"
    "drawer\0ADataReceiver*\0timeReceiver\0"
    "ITimeReceiver*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LfoController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       6,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    3,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00095409,
      12, 0x80000000 | 11, 0x00095409,
      13, 0x80000000 | 11, 0x00095409,
      14, 0x80000000 | 15, 0x00095409,
      16, 0x80000000 | 17, 0x0009510a,
      18, 0x80000000 | 19, 0x00095409,

       0        // eod
};

void LfoController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LfoController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->lfoValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->lfoShapeChanged((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LfoController::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LfoController::lfoValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LfoController::*)(const std::vector<float> & , std::vector<float>::const_iterator , std::vector<float>::const_iterator );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LfoController::lfoShapeChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LfoController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getPhase(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getFrequency(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getWaveshape(); break;
        case 3: *reinterpret_cast< AValueSender**>(_v) = _t->getValueSender(); break;
        case 5: *reinterpret_cast< ITimeReceiver**>(_v) = _t->getTimeReceiver(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<LfoController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setDrawer(*reinterpret_cast< ADataReceiver**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject LfoController::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_LfoController.data,
    qt_meta_data_LfoController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LfoController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LfoController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LfoController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ITimeReceiver"))
        return static_cast< ITimeReceiver*>(this);
    if (!strcmp(_clname, "AValueSender"))
        return static_cast< AValueSender*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int LfoController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LfoController::lfoValueChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LfoController::lfoShapeChanged(const std::vector<float> & _t1, std::vector<float>::const_iterator _t2, std::vector<float>::const_iterator _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
