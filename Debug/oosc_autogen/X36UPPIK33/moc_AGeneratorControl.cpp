/****************************************************************************
** Meta object code from reading C++ file 'AGeneratorControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/AGeneratorControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AGeneratorControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AGeneratorControl_t {
    QByteArrayData data[12];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AGeneratorControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AGeneratorControl_t qt_meta_stringdata_AGeneratorControl = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AGeneratorControl"
QT_MOC_LITERAL(1, 18, 18), // "generatorIDChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 18), // "AGeneratorControl*"
QT_MOC_LITERAL(4, 57, 16), // "generatorControl"
QT_MOC_LITERAL(5, 74, 11), // "adsrChanged"
QT_MOC_LITERAL(6, 86, 15), // "ADSRController*"
QT_MOC_LITERAL(7, 102, 10), // "controller"
QT_MOC_LITERAL(8, 113, 13), // "bypassChanged"
QT_MOC_LITERAL(9, 127, 6), // "bypass"
QT_MOC_LITERAL(10, 134, 11), // "generatorID"
QT_MOC_LITERAL(11, 146, 14) // "adsrController"

    },
    "AGeneratorControl\0generatorIDChanged\0"
    "\0AGeneratorControl*\0generatorControl\0"
    "adsrChanged\0ADSRController*\0controller\0"
    "bypassChanged\0bypass\0generatorID\0"
    "adsrController"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AGeneratorControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       8,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // properties: name, type, flags
      10, QMetaType::UInt, 0x00495103,
       9, QMetaType::Bool, 0x00495103,
      11, 0x80000000 | 6, 0x0049500b,

 // properties: notify_signal_id
       0,
       2,
       1,

       0        // eod
};

void AGeneratorControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AGeneratorControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->generatorIDChanged((*reinterpret_cast< AGeneratorControl*(*)>(_a[1]))); break;
        case 1: _t->adsrChanged((*reinterpret_cast< ADSRController*(*)>(_a[1]))); break;
        case 2: _t->bypassChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AGeneratorControl* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ADSRController* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AGeneratorControl::*)(AGeneratorControl * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AGeneratorControl::generatorIDChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AGeneratorControl::*)(ADSRController * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AGeneratorControl::adsrChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AGeneratorControl::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AGeneratorControl::bypassChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ADSRController* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AGeneratorControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->getGeneratorID(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getBypass(); break;
        case 2: *reinterpret_cast< ADSRController**>(_v) = _t->getAdsr(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AGeneratorControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGeneratorID(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setBypass(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setAdsr(*reinterpret_cast< ADSRController**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AGeneratorControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_AGeneratorControl.data,
    qt_meta_data_AGeneratorControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AGeneratorControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AGeneratorControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AGeneratorControl.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int AGeneratorControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AGeneratorControl::generatorIDChanged(AGeneratorControl * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AGeneratorControl::adsrChanged(ADSRController * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AGeneratorControl::bypassChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
