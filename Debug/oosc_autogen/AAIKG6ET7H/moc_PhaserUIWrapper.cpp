/****************************************************************************
** Meta object code from reading C++ file 'PhaserUIWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Effects/PhaserUIWrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PhaserUIWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PhaserUIWrapper_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PhaserUIWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PhaserUIWrapper_t qt_meta_stringdata_PhaserUIWrapper = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PhaserUIWrapper"
QT_MOC_LITERAL(1, 16, 8), // "lfoShape"
QT_MOC_LITERAL(2, 25, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(3, 47, 10), // "phaseWidth"
QT_MOC_LITERAL(4, 58, 5), // "depth"
QT_MOC_LITERAL(5, 64, 15), // "numberOfFilters"
QT_MOC_LITERAL(6, 80, 12), // "lfoFrequency"
QT_MOC_LITERAL(7, 93, 15), // "filterFrequency"
QT_MOC_LITERAL(8, 109, 8) // "feedback"

    },
    "PhaserUIWrapper\0lfoShape\0IChangeableParameter*\0"
    "phaseWidth\0depth\0numberOfFilters\0"
    "lfoFrequency\0filterFrequency\0feedback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PhaserUIWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
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

       0        // eod
};

void PhaserUIWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        auto *_t = static_cast<PhaserUIWrapper *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getLfoShape(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getPhaseWidth(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getDepth(); break;
        case 3: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getNumberOfFilters(); break;
        case 4: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getLfoFrequency(); break;
        case 5: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getFilterFrequency(); break;
        case 6: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getFeedback(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
}

QT_INIT_METAOBJECT const QMetaObject PhaserUIWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<EffectUIWrapper::staticMetaObject>(),
    qt_meta_stringdata_PhaserUIWrapper.data,
    qt_meta_data_PhaserUIWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PhaserUIWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PhaserUIWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PhaserUIWrapper.stringdata0))
        return static_cast<void*>(this);
    return EffectUIWrapper::qt_metacast(_clname);
}

int PhaserUIWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EffectUIWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
