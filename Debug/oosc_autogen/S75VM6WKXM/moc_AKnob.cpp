/****************************************************************************
** Meta object code from reading C++ file 'AKnob.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Controls/AKnob.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AKnob.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KnobInterpolation_t {
    QByteArrayData data[4];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KnobInterpolation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KnobInterpolation_t qt_meta_stringdata_KnobInterpolation = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KnobInterpolation"
QT_MOC_LITERAL(1, 18, 23), // "KnobInterpolationMethod"
QT_MOC_LITERAL(2, 42, 6), // "Linear"
QT_MOC_LITERAL(3, 49, 11) // "Exponential"

    },
    "KnobInterpolation\0KnobInterpolationMethod\0"
    "Linear\0Exponential"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KnobInterpolation[] = {

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
       2, uint(KnobInterpolation::Linear),
       3, uint(KnobInterpolation::Exponential),

       0        // eod
};

void KnobInterpolation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KnobInterpolation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_KnobInterpolation.data,
    qt_meta_data_KnobInterpolation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KnobInterpolation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KnobInterpolation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KnobInterpolation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KnobInterpolation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KnobDirection_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KnobDirection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KnobDirection_t qt_meta_stringdata_KnobDirection = {
    {
QT_MOC_LITERAL(0, 0, 13), // "KnobDirection"
QT_MOC_LITERAL(1, 14, 19), // "KnobDirectionMethod"
QT_MOC_LITERAL(2, 34, 8), // "Vertical"
QT_MOC_LITERAL(3, 43, 10) // "Horizontal"

    },
    "KnobDirection\0KnobDirectionMethod\0"
    "Vertical\0Horizontal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KnobDirection[] = {

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
       2, uint(KnobDirection::Vertical),
       3, uint(KnobDirection::Horizontal),

       0        // eod
};

void KnobDirection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KnobDirection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_KnobDirection.data,
    qt_meta_data_KnobDirection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KnobDirection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KnobDirection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KnobDirection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KnobDirection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AKnob_t {
    QByteArrayData data[32];
    char stringdata0[533];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AKnob_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AKnob_t qt_meta_stringdata_AKnob = {
    {
QT_MOC_LITERAL(0, 0, 5), // "AKnob"
QT_MOC_LITERAL(1, 6, 12), // "valueChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "value"
QT_MOC_LITERAL(4, 26, 20), // "mousePositionChanged"
QT_MOC_LITERAL(5, 47, 25), // "startMousePositionChanged"
QT_MOC_LITERAL(6, 73, 17), // "mouseTrackChanged"
QT_MOC_LITERAL(7, 91, 25), // "mouseStartPositionChanged"
QT_MOC_LITERAL(8, 117, 20), // "interpolationChanged"
QT_MOC_LITERAL(9, 138, 16), // "directionChanged"
QT_MOC_LITERAL(10, 155, 9), // "mouseMove"
QT_MOC_LITERAL(11, 165, 15), // "trackMouseState"
QT_MOC_LITERAL(12, 181, 5), // "state"
QT_MOC_LITERAL(13, 187, 25), // "updateChangeableParameter"
QT_MOC_LITERAL(14, 213, 16), // "updateAutomation"
QT_MOC_LITERAL(15, 230, 14), // "changeParametr"
QT_MOC_LITERAL(16, 245, 18), // "connectValueSender"
QT_MOC_LITERAL(17, 264, 13), // "AValueSender*"
QT_MOC_LITERAL(18, 278, 6), // "sender"
QT_MOC_LITERAL(19, 285, 16), // "disconnectSender"
QT_MOC_LITERAL(20, 302, 21), // "setChangeableParametr"
QT_MOC_LITERAL(21, 324, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(22, 346, 8), // "parametr"
QT_MOC_LITERAL(23, 355, 12), // "currentValue"
QT_MOC_LITERAL(24, 368, 13), // "mousePosition"
QT_MOC_LITERAL(25, 382, 10), // "trackMouse"
QT_MOC_LITERAL(26, 393, 18), // "startMousePosition"
QT_MOC_LITERAL(27, 412, 13), // "interpolation"
QT_MOC_LITERAL(28, 426, 42), // "KnobInterpolation::KnobInterp..."
QT_MOC_LITERAL(29, 469, 9), // "direction"
QT_MOC_LITERAL(30, 479, 34), // "KnobDirection::KnobDirectionM..."
QT_MOC_LITERAL(31, 514, 18) // "changeableParametr"

    },
    "AKnob\0valueChanged\0\0value\0"
    "mousePositionChanged\0startMousePositionChanged\0"
    "mouseTrackChanged\0mouseStartPositionChanged\0"
    "interpolationChanged\0directionChanged\0"
    "mouseMove\0trackMouseState\0state\0"
    "updateChangeableParameter\0updateAutomation\0"
    "changeParametr\0connectValueSender\0"
    "AValueSender*\0sender\0disconnectSender\0"
    "setChangeableParametr\0IChangeableParameter*\0"
    "parametr\0currentValue\0mousePosition\0"
    "trackMouse\0startMousePosition\0"
    "interpolation\0KnobInterpolation::KnobInterpolationMethod\0"
    "direction\0KnobDirection::KnobDirectionMethod\0"
    "changeableParametr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AKnob[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       7,  118, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    1,   94,    2, 0x06 /* Public */,
       7,    0,   97,    2, 0x06 /* Public */,
       8,    0,   98,    2, 0x06 /* Public */,
       9,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  100,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    1,  105,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      15,    1,  108,    2, 0x02 /* Public */,
      16,    1,  111,    2, 0x02 /* Public */,
      19,    0,  114,    2, 0x02 /* Public */,
      20,    1,  115,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,

 // properties: name, type, flags
      23, QMetaType::Float, 0x00495001,
      24, QMetaType::QPoint, 0x00095103,
      25, QMetaType::Bool, 0x00495003,
      26, QMetaType::QPoint, 0x00495103,
      27, 0x80000000 | 28, 0x0049510b,
      29, 0x80000000 | 30, 0x0049510b,
      31, 0x80000000 | 21, 0x0009510a,

 // properties: notify_signal_id
       0,
       0,
       3,
       2,
       5,
       6,
       0,

       0        // eod
};

void AKnob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AKnob *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->mousePositionChanged(); break;
        case 2: _t->startMousePositionChanged(); break;
        case 3: _t->mouseTrackChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->mouseStartPositionChanged(); break;
        case 5: _t->interpolationChanged(); break;
        case 6: _t->directionChanged(); break;
        case 7: _t->mouseMove(); break;
        case 8: _t->trackMouseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->updateChangeableParameter(); break;
        case 10: _t->updateAutomation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->changeParametr((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 12: _t->connectValueSender((*reinterpret_cast< AValueSender*(*)>(_a[1]))); break;
        case 13: _t->disconnectSender(); break;
        case 14: _t->setChangeableParametr((*reinterpret_cast< IChangeableParameter*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AKnob::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AKnob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::mousePositionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AKnob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::startMousePositionChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AKnob::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::mouseTrackChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AKnob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::mouseStartPositionChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AKnob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::interpolationChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AKnob::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AKnob::directionChanged)) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AKnob *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->getCurrentValue(); break;
        case 1: *reinterpret_cast< QPoint*>(_v) = _t->getMousePosition(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getTrackMouse(); break;
        case 3: *reinterpret_cast< QPoint*>(_v) = _t->getStartMousePosition(); break;
        case 4: *reinterpret_cast< KnobInterpolation::KnobInterpolationMethod*>(_v) = _t->getInterpolation(); break;
        case 5: *reinterpret_cast< KnobDirection::KnobDirectionMethod*>(_v) = _t->getDirection(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AKnob *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setMousePosition(*reinterpret_cast< QPoint*>(_v)); break;
        case 2: _t->setMouseTrack(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setStartMousePosition(*reinterpret_cast< QPoint*>(_v)); break;
        case 4: _t->setInterpolation(*reinterpret_cast< KnobInterpolation::KnobInterpolationMethod*>(_v)); break;
        case 5: _t->setDirection(*reinterpret_cast< KnobDirection::KnobDirectionMethod*>(_v)); break;
        case 6: _t->setChangeableParametr(*reinterpret_cast< IChangeableParameter**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

static const QMetaObject::SuperData qt_meta_extradata_AKnob[] = {
    QMetaObject::SuperData::link<KnobInterpolation::staticMetaObject>(),
    QMetaObject::SuperData::link<KnobDirection::staticMetaObject>(),
    nullptr
};

QT_INIT_METAOBJECT const QMetaObject AKnob::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_AKnob.data,
    qt_meta_data_AKnob,
    qt_static_metacall,
    qt_meta_extradata_AKnob,
    nullptr
} };


const QMetaObject *AKnob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AKnob::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AKnob.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int AKnob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AKnob::valueChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AKnob::mousePositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AKnob::startMousePositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AKnob::mouseTrackChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AKnob::mouseStartPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AKnob::interpolationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void AKnob::directionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
