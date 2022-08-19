/****************************************************************************
** Meta object code from reading C++ file 'VibratoUIWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Effects/VibratoUIWrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VibratoUIWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VibratoUIWrapper_t {
    QByteArrayData data[6];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VibratoUIWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VibratoUIWrapper_t qt_meta_stringdata_VibratoUIWrapper = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VibratoUIWrapper"
QT_MOC_LITERAL(1, 17, 12), // "vibratoWidth"
QT_MOC_LITERAL(2, 30, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(3, 52, 12), // "lfoFrequency"
QT_MOC_LITERAL(4, 65, 13), // "interpolation"
QT_MOC_LITERAL(5, 79, 8) // "lfoShape"

    },
    "VibratoUIWrapper\0vibratoWidth\0"
    "IChangeableParameter*\0lfoFrequency\0"
    "interpolation\0lfoShape"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VibratoUIWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x00095409,
       3, 0x80000000 | 2, 0x00095409,
       4, 0x80000000 | 2, 0x00095409,
       5, 0x80000000 | 2, 0x00095409,

       0        // eod
};

void VibratoUIWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
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
        auto *_t = static_cast<VibratoUIWrapper *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getVibratoWidth(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getLfoFrequency(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getInterpolation(); break;
        case 3: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getLfoShape(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
}

QT_INIT_METAOBJECT const QMetaObject VibratoUIWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<EffectUIWrapper::staticMetaObject>(),
    qt_meta_stringdata_VibratoUIWrapper.data,
    qt_meta_data_VibratoUIWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VibratoUIWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VibratoUIWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VibratoUIWrapper.stringdata0))
        return static_cast<void*>(this);
    return EffectUIWrapper::qt_metacast(_clname);
}

int VibratoUIWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EffectUIWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
