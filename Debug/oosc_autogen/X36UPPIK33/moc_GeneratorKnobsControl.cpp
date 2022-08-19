/****************************************************************************
** Meta object code from reading C++ file 'GeneratorKnobsControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/GeneratorKnobsControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneratorKnobsControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneratorKnobsControl_t {
    QByteArrayData data[15];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneratorKnobsControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneratorKnobsControl_t qt_meta_stringdata_GeneratorKnobsControl = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GeneratorKnobsControl"
QT_MOC_LITERAL(1, 22, 12), // "knobAttached"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "attachKnobs"
QT_MOC_LITERAL(4, 48, 16), // "generatorControl"
QT_MOC_LITERAL(5, 65, 17), // "GeneratorControl*"
QT_MOC_LITERAL(6, 83, 7), // "posKnob"
QT_MOC_LITERAL(7, 91, 5), // "Knob*"
QT_MOC_LITERAL(8, 97, 7), // "panKnob"
QT_MOC_LITERAL(9, 105, 8), // "gainKnob"
QT_MOC_LITERAL(10, 114, 9), // "phaseKnob"
QT_MOC_LITERAL(11, 124, 16), // "unisonVoicesKnob"
QT_MOC_LITERAL(12, 141, 13), // "unisonPanKnob"
QT_MOC_LITERAL(13, 155, 15), // "unisonLevelKnob"
QT_MOC_LITERAL(14, 171, 14) // "unisonFineKnob"

    },
    "GeneratorKnobsControl\0knobAttached\0\0"
    "attachKnobs\0generatorControl\0"
    "GeneratorControl*\0posKnob\0Knob*\0panKnob\0"
    "gainKnob\0phaseKnob\0unisonVoicesKnob\0"
    "unisonPanKnob\0unisonLevelKnob\0"
    "unisonFineKnob"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneratorKnobsControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       9,   26, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       4, 0x80000000 | 5, 0x0009510a,
       6, 0x80000000 | 7, 0x0049510b,
       8, 0x80000000 | 7, 0x0049510b,
       9, 0x80000000 | 7, 0x0049510b,
      10, 0x80000000 | 7, 0x0049510b,
      11, 0x80000000 | 7, 0x0049510b,
      12, 0x80000000 | 7, 0x0049510b,
      13, 0x80000000 | 7, 0x0049510b,
      14, 0x80000000 | 7, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void GeneratorKnobsControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneratorKnobsControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->knobAttached(); break;
        case 1: _t->attachKnobs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GeneratorKnobsControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneratorKnobsControl::knobAttached)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GeneratorControl* >(); break;
        case 8:
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Knob* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<GeneratorKnobsControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: *reinterpret_cast< Knob**>(_v) = _t->getPosKnob(); break;
        case 2: *reinterpret_cast< Knob**>(_v) = _t->getPanKnob(); break;
        case 3: *reinterpret_cast< Knob**>(_v) = _t->getGainKnob(); break;
        case 4: *reinterpret_cast< Knob**>(_v) = _t->getPhaseKnob(); break;
        case 5: *reinterpret_cast< Knob**>(_v) = _t->getUnisonVoicesKnob(); break;
        case 6: *reinterpret_cast< Knob**>(_v) = _t->getUnisonPanKnob(); break;
        case 7: *reinterpret_cast< Knob**>(_v) = _t->getUnisonLevelKnob(); break;
        case 8: *reinterpret_cast< Knob**>(_v) = _t->getUnisonFineKnob(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<GeneratorKnobsControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGeneratorControl(*reinterpret_cast< GeneratorControl**>(_v)); break;
        case 1: _t->setPosKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 2: _t->setPanKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 3: _t->setGainKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 4: _t->setPhaseKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 5: _t->setUnisonVoicesKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 6: _t->setUnisonPanKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 7: _t->setUnisonLevelKnob(*reinterpret_cast< Knob**>(_v)); break;
        case 8: _t->setUnisonFineKnob(*reinterpret_cast< Knob**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject GeneratorKnobsControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_GeneratorKnobsControl.data,
    qt_meta_data_GeneratorKnobsControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeneratorKnobsControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneratorKnobsControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorKnobsControl.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int GeneratorKnobsControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GeneratorKnobsControl::knobAttached()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
