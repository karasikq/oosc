/****************************************************************************
** Meta object code from reading C++ file 'Knob.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Controls/Knob.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Knob.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Knob_t {
    QByteArrayData data[15];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Knob_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Knob_t qt_meta_stringdata_Knob = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Knob"
QT_MOC_LITERAL(1, 5, 17), // "startAngleChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "endAngleChanged"
QT_MOC_LITERAL(4, 40, 16), // "dialWidthChanged"
QT_MOC_LITERAL(5, 57, 17), // "outerColorChanged"
QT_MOC_LITERAL(6, 75, 18), // "outerStrokeChanged"
QT_MOC_LITERAL(7, 94, 16), // "pinRadiusChanged"
QT_MOC_LITERAL(8, 111, 12), // "updateAngles"
QT_MOC_LITERAL(9, 124, 10), // "startAngle"
QT_MOC_LITERAL(10, 135, 8), // "endAngle"
QT_MOC_LITERAL(11, 144, 11), // "outerStroke"
QT_MOC_LITERAL(12, 156, 9), // "pinRadius"
QT_MOC_LITERAL(13, 166, 10), // "outerColor"
QT_MOC_LITERAL(14, 177, 15) // "mouseWheelDelta"

    },
    "Knob\0startAngleChanged\0\0endAngleChanged\0"
    "dialWidthChanged\0outerColorChanged\0"
    "outerStrokeChanged\0pinRadiusChanged\0"
    "updateAngles\0startAngle\0endAngle\0"
    "outerStroke\0pinRadius\0outerColor\0"
    "mouseWheelDelta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Knob[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::Int, 0x00495103,
      10, QMetaType::Float, 0x00495103,
      11, QMetaType::Float, 0x00495103,
      12, QMetaType::Float, 0x00495103,
      13, QMetaType::QColor, 0x00495103,
      14, QMetaType::QPoint, 0x00095102,

 // properties: notify_signal_id
       0,
       1,
       4,
       5,
       3,
       0,

       0        // eod
};

void Knob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Knob *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startAngleChanged(); break;
        case 1: _t->endAngleChanged(); break;
        case 2: _t->dialWidthChanged(); break;
        case 3: _t->outerColorChanged(); break;
        case 4: _t->outerStrokeChanged(); break;
        case 5: _t->pinRadiusChanged(); break;
        case 6: _t->updateAngles(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Knob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Knob::startAngleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Knob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Knob::endAngleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Knob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Knob::dialWidthChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Knob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Knob::outerColorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Knob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Knob::outerStrokeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Knob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Knob::pinRadiusChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Knob *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getStartAngle(); break;
        case 1: *reinterpret_cast< float*>(_v) = _t->getEndAngle(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->getOuterStroke(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->getPinRadius(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getOuterColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Knob *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStartAngle(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setEndAngle(*reinterpret_cast< float*>(_v)); break;
        case 2: _t->setOuterStroke(*reinterpret_cast< float*>(_v)); break;
        case 3: _t->setPinRadius(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->setOuterColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setMouseWheelDelta(*reinterpret_cast< QPoint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Knob::staticMetaObject = { {
    QMetaObject::SuperData::link<AKnob::staticMetaObject>(),
    qt_meta_stringdata_Knob.data,
    qt_meta_data_Knob,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Knob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Knob::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Knob.stringdata0))
        return static_cast<void*>(this);
    return AKnob::qt_metacast(_clname);
}

int Knob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AKnob::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void Knob::startAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Knob::endAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Knob::dialWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Knob::outerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Knob::outerStrokeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Knob::pinRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
