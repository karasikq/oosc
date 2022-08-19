/****************************************************************************
** Meta object code from reading C++ file 'FlangerUIWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Effects/FlangerUIWrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlangerUIWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FlangerUIWrapper_t {
    QByteArrayData data[10];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlangerUIWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlangerUIWrapper_t qt_meta_stringdata_FlangerUIWrapper = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FlangerUIWrapper"
QT_MOC_LITERAL(1, 17, 5), // "delay"
QT_MOC_LITERAL(2, 23, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(3, 45, 12), // "flangerWidth"
QT_MOC_LITERAL(4, 58, 5), // "depth"
QT_MOC_LITERAL(5, 64, 8), // "feedback"
QT_MOC_LITERAL(6, 73, 12), // "invertedMode"
QT_MOC_LITERAL(7, 86, 12), // "lfoFrequency"
QT_MOC_LITERAL(8, 99, 13), // "interpolation"
QT_MOC_LITERAL(9, 113, 8) // "lfoShape"

    },
    "FlangerUIWrapper\0delay\0IChangeableParameter*\0"
    "flangerWidth\0depth\0feedback\0invertedMode\0"
    "lfoFrequency\0interpolation\0lfoShape"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlangerUIWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       8,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x00095409,
       3, 0x80000000 | 2, 0x00095409,
       4, 0x80000000 | 2, 0x00095409,
       5, 0x80000000 | 2, 0x00095409,
       6, 0x80000000 | 2, 0x00095409,
       7, 0x80000000 | 2, 0x00095409,
       8, 0x80000000 | 2, 0x00095409,
       9, 0x80000000 | 2, 0x00095409,

       0        // eod
};

void FlangerUIWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FlangerUIWrapper *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getDelay(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getFlangerWidth(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getDepth(); break;
        case 3: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getFeedback(); break;
        case 4: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getInvertedMode(); break;
        case 5: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getLfoFrequency(); break;
        case 6: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getInterpolation(); break;
        case 7: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getLfoShape(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
}

QT_INIT_METAOBJECT const QMetaObject FlangerUIWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<EffectUIWrapper::staticMetaObject>(),
    qt_meta_stringdata_FlangerUIWrapper.data,
    qt_meta_data_FlangerUIWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FlangerUIWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlangerUIWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FlangerUIWrapper.stringdata0))
        return static_cast<void*>(this);
    return EffectUIWrapper::qt_metacast(_clname);
}

int FlangerUIWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EffectUIWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
