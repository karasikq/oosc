/****************************************************************************
** Meta object code from reading C++ file 'SubGeneratorControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/SubGeneratorControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SubGeneratorControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SubGeneratorControl_t {
    QByteArrayData data[17];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SubGeneratorControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SubGeneratorControl_t qt_meta_stringdata_SubGeneratorControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SubGeneratorControl"
QT_MOC_LITERAL(1, 20, 16), // "wavetableChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 18), // "std::vector<float>"
QT_MOC_LITERAL(4, 57, 4), // "data"
QT_MOC_LITERAL(5, 62, 34), // "std::vector<float>::const_ite..."
QT_MOC_LITERAL(6, 97, 4), // "from"
QT_MOC_LITERAL(7, 102, 2), // "to"
QT_MOC_LITERAL(8, 105, 22), // "wavetableDrawerChanged"
QT_MOC_LITERAL(9, 128, 21), // "updateWavetableDrawer"
QT_MOC_LITERAL(10, 150, 3), // "pan"
QT_MOC_LITERAL(11, 154, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(12, 176, 4), // "gain"
QT_MOC_LITERAL(13, 181, 12), // "octaveOffset"
QT_MOC_LITERAL(14, 194, 5), // "shape"
QT_MOC_LITERAL(15, 200, 15), // "wavetableDrawer"
QT_MOC_LITERAL(16, 216, 12) // "ArrayDrawer*"

    },
    "SubGeneratorControl\0wavetableChanged\0"
    "\0std::vector<float>\0data\0"
    "std::vector<float>::const_iterator\0"
    "from\0to\0wavetableDrawerChanged\0"
    "updateWavetableDrawer\0pan\0"
    "IChangeableParameter*\0gain\0octaveOffset\0"
    "shape\0wavetableDrawer\0ArrayDrawer*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SubGeneratorControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       5,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       8,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00095409,
      12, 0x80000000 | 11, 0x00095409,
      13, 0x80000000 | 11, 0x00095409,
      14, 0x80000000 | 11, 0x00095409,
      15, 0x80000000 | 16, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       1,

       0        // eod
};

void SubGeneratorControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SubGeneratorControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->wavetableChanged((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        case 1: _t->wavetableDrawerChanged(); break;
        case 2: _t->updateWavetableDrawer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SubGeneratorControl::*)(const std::vector<float> & , std::vector<float>::const_iterator , std::vector<float>::const_iterator );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SubGeneratorControl::wavetableChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SubGeneratorControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SubGeneratorControl::wavetableDrawerChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ArrayDrawer* >(); break;
        case 3:
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SubGeneratorControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getPan(); break;
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getGain(); break;
        case 2: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getOctaveOffset(); break;
        case 3: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getShape(); break;
        case 4: *reinterpret_cast< ArrayDrawer**>(_v) = _t->getWavetableDrawer(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SubGeneratorControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setWavetableDrawer(*reinterpret_cast< ArrayDrawer**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject SubGeneratorControl::staticMetaObject = { {
    QMetaObject::SuperData::link<AGeneratorControl::staticMetaObject>(),
    qt_meta_stringdata_SubGeneratorControl.data,
    qt_meta_data_SubGeneratorControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SubGeneratorControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubGeneratorControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubGeneratorControl.stringdata0))
        return static_cast<void*>(this);
    return AGeneratorControl::qt_metacast(_clname);
}

int SubGeneratorControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGeneratorControl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SubGeneratorControl::wavetableChanged(const std::vector<float> & _t1, std::vector<float>::const_iterator _t2, std::vector<float>::const_iterator _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SubGeneratorControl::wavetableDrawerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
