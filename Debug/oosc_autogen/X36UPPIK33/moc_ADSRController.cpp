/****************************************************************************
** Meta object code from reading C++ file 'ADSRController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/ADSRController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ADSRController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ADSRController_t {
    QByteArrayData data[15];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ADSRController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ADSRController_t qt_meta_stringdata_ADSRController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ADSRController"
QT_MOC_LITERAL(1, 15, 15), // "envelopeChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "drawerChanged"
QT_MOC_LITERAL(4, 46, 11), // "ADSRDrawer*"
QT_MOC_LITERAL(5, 58, 6), // "drawer"
QT_MOC_LITERAL(6, 65, 6), // "attack"
QT_MOC_LITERAL(7, 72, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(8, 94, 5), // "decay"
QT_MOC_LITERAL(9, 100, 7), // "sustain"
QT_MOC_LITERAL(10, 108, 7), // "release"
QT_MOC_LITERAL(11, 116, 6), // "sender"
QT_MOC_LITERAL(12, 123, 13), // "AValueSender*"
QT_MOC_LITERAL(13, 137, 12), // "dataReceiver"
QT_MOC_LITERAL(14, 150, 14) // "ADataReceiver*"

    },
    "ADSRController\0envelopeChanged\0\0"
    "drawerChanged\0ADSRDrawer*\0drawer\0"
    "attack\0IChangeableParameter*\0decay\0"
    "sustain\0release\0sender\0AValueSender*\0"
    "dataReceiver\0ADataReceiver*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ADSRController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       7,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    1,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // properties: name, type, flags
       6, 0x80000000 | 7, 0x00095409,
       8, 0x80000000 | 7, 0x00095409,
       9, 0x80000000 | 7, 0x00095409,
      10, 0x80000000 | 7, 0x00095409,
       5, 0x80000000 | 4, 0x0049510b,
      11, 0x80000000 | 12, 0x00095409,
      13, 0x80000000 | 14, 0x00095409,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       1,
       0,
       0,

       0        // eod
};

void ADSRController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ADSRController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->envelopeChanged(); break;
        case 1: _t->drawerChanged((*reinterpret_cast< ADSRDrawer*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ADSRController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ADSRController::envelopeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ADSRController::*)(ADSRDrawer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ADSRController::drawerChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ADSRController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getAttack(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getDecay(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getSustain(); break;
        case 3: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getRelease(); break;
        case 4: *reinterpret_cast< ADSRDrawer**>(_v) = _t->getDrawer(); break;
        case 5: *reinterpret_cast< AValueSender**>(_v) = _t->getValueSender(); break;
        case 6: *reinterpret_cast< ADataReceiver**>(_v) = _t->getDataReceiver(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ADSRController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setDrawer(*reinterpret_cast< ADSRDrawer**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ADSRController::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_ADSRController.data,
    qt_meta_data_ADSRController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ADSRController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ADSRController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ADSRController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "AValueSender"))
        return static_cast< AValueSender*>(this);
    if (!strcmp(_clname, "ADataReceiver"))
        return static_cast< ADataReceiver*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int ADSRController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ADSRController::envelopeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ADSRController::drawerChanged(ADSRDrawer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ADSRSlots_t {
    QByteArrayData data[5];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ADSRSlots_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ADSRSlots_t qt_meta_stringdata_ADSRSlots = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ADSRSlots"
QT_MOC_LITERAL(1, 10, 16), // "lastNoteReceived"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "Note<3>"
QT_MOC_LITERAL(4, 36, 4) // "note"

    },
    "ADSRSlots\0lastNoteReceived\0\0Note<3>\0"
    "note"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ADSRSlots[] = {

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

void ADSRSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ADSRSlots *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->lastNoteReceived((*reinterpret_cast< const Note<3>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ADSRSlots::staticMetaObject = { {
    QMetaObject::SuperData::link<ADataReceiverSlots::staticMetaObject>(),
    qt_meta_stringdata_ADSRSlots.data,
    qt_meta_data_ADSRSlots,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ADSRSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ADSRSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ADSRSlots.stringdata0))
        return static_cast<void*>(this);
    return ADataReceiverSlots::qt_metacast(_clname);
}

int ADSRSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
