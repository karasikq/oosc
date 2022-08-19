/****************************************************************************
** Meta object code from reading C++ file 'GeneratorControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/GeneratorControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneratorControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneratorControl_t {
    QByteArrayData data[27];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneratorControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneratorControl_t qt_meta_stringdata_GeneratorControl = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GeneratorControl"
QT_MOC_LITERAL(1, 17, 16), // "wavetableChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 18), // "std::vector<float>"
QT_MOC_LITERAL(4, 54, 4), // "data"
QT_MOC_LITERAL(5, 59, 34), // "std::vector<float>::const_ite..."
QT_MOC_LITERAL(6, 94, 4), // "from"
QT_MOC_LITERAL(7, 99, 2), // "to"
QT_MOC_LITERAL(8, 102, 22), // "wavetableDrawerChanged"
QT_MOC_LITERAL(9, 125, 24), // "wavetablePositionChanged"
QT_MOC_LITERAL(10, 150, 21), // "updateWavetableDrawer"
QT_MOC_LITERAL(11, 172, 21), // "loadWavetableFromFile"
QT_MOC_LITERAL(12, 194, 8), // "fileName"
QT_MOC_LITERAL(13, 203, 24), // "loadWavetableFromFileUrl"
QT_MOC_LITERAL(14, 228, 3), // "pan"
QT_MOC_LITERAL(15, 232, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(16, 254, 4), // "gain"
QT_MOC_LITERAL(17, 259, 13), // "tablePosition"
QT_MOC_LITERAL(18, 273, 5), // "phase"
QT_MOC_LITERAL(19, 279, 5), // "cents"
QT_MOC_LITERAL(20, 285, 12), // "octaveOffset"
QT_MOC_LITERAL(21, 298, 14), // "semitoneOffset"
QT_MOC_LITERAL(22, 313, 12), // "unisonVoices"
QT_MOC_LITERAL(23, 326, 11), // "unisonLevel"
QT_MOC_LITERAL(24, 338, 10), // "unisonFine"
QT_MOC_LITERAL(25, 349, 15), // "wavetableDrawer"
QT_MOC_LITERAL(26, 365, 12) // "ArrayDrawer*"

    },
    "GeneratorControl\0wavetableChanged\0\0"
    "std::vector<float>\0data\0"
    "std::vector<float>::const_iterator\0"
    "from\0to\0wavetableDrawerChanged\0"
    "wavetablePositionChanged\0updateWavetableDrawer\0"
    "loadWavetableFromFile\0fileName\0"
    "loadWavetableFromFileUrl\0pan\0"
    "IChangeableParameter*\0gain\0tablePosition\0"
    "phase\0cents\0octaveOffset\0semitoneOffset\0"
    "unisonVoices\0unisonLevel\0unisonFine\0"
    "wavetableDrawer\0ArrayDrawer*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneratorControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
      11,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       8,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   52,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    1,   54,    2, 0x02 /* Public */,
      13,    1,   57,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariant,   12,
    QMetaType::Void, QMetaType::QVariant,   12,

 // properties: name, type, flags
      14, 0x80000000 | 15, 0x00095409,
      16, 0x80000000 | 15, 0x00095409,
      17, 0x80000000 | 15, 0x00095409,
      18, 0x80000000 | 15, 0x00095409,
      19, 0x80000000 | 15, 0x00095409,
      20, 0x80000000 | 15, 0x00095409,
      21, 0x80000000 | 15, 0x00095409,
      22, 0x80000000 | 15, 0x00095409,
      23, 0x80000000 | 15, 0x00095409,
      24, 0x80000000 | 15, 0x00095409,
      25, 0x80000000 | 26, 0x0049510b,

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
       0,
       1,

       0        // eod
};

void GeneratorControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneratorControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->wavetableChanged((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        case 1: _t->wavetableDrawerChanged(); break;
        case 2: _t->wavetablePositionChanged(); break;
        case 3: _t->updateWavetableDrawer(); break;
        case 4: _t->loadWavetableFromFile((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 5: _t->loadWavetableFromFileUrl((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GeneratorControl::*)(const std::vector<float> & , std::vector<float>::const_iterator , std::vector<float>::const_iterator );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneratorControl::wavetableChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GeneratorControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneratorControl::wavetableDrawerChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ArrayDrawer* >(); break;
        case 9:
        case 8:
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
        auto *_t = static_cast<GeneratorControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getPan(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getGain(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getTablePosition(); break;
        case 3: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getPhase(); break;
        case 4: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getCents(); break;
        case 5: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getOctaveOffset(); break;
        case 6: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getSemitoneOffset(); break;
        case 7: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getUnisonVoices(); break;
        case 8: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getUnisonLevel(); break;
        case 9: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getUnisonFine(); break;
        case 10: *reinterpret_cast< ArrayDrawer**>(_v) = _t->getWavetableDrawer(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<GeneratorControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 10: _t->setWavetableDrawer(*reinterpret_cast< ArrayDrawer**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject GeneratorControl::staticMetaObject = { {
    QMetaObject::SuperData::link<AGeneratorControl::staticMetaObject>(),
    qt_meta_stringdata_GeneratorControl.data,
    qt_meta_data_GeneratorControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeneratorControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneratorControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorControl.stringdata0))
        return static_cast<void*>(this);
    return AGeneratorControl::qt_metacast(_clname);
}

int GeneratorControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGeneratorControl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GeneratorControl::wavetableChanged(const std::vector<float> & _t1, std::vector<float>::const_iterator _t2, std::vector<float>::const_iterator _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GeneratorControl::wavetableDrawerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
