/****************************************************************************
** Meta object code from reading C++ file 'MixerQmlWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/MixerQmlWrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MixerQmlWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MixerQmlWrapper_t {
    QByteArrayData data[8];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MixerQmlWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MixerQmlWrapper_t qt_meta_stringdata_MixerQmlWrapper = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MixerQmlWrapper"
QT_MOC_LITERAL(1, 16, 17), // "attachSynthesizer"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "BasicSynthesizer*"
QT_MOC_LITERAL(4, 53, 11), // "synthesizer"
QT_MOC_LITERAL(5, 65, 18), // "attachTimeReceiver"
QT_MOC_LITERAL(6, 84, 14), // "ITimeReceiver*"
QT_MOC_LITERAL(7, 99, 8) // "receiver"

    },
    "MixerQmlWrapper\0attachSynthesizer\0\0"
    "BasicSynthesizer*\0synthesizer\0"
    "attachTimeReceiver\0ITimeReceiver*\0"
    "receiver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MixerQmlWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x02 /* Public */,
       5,    1,   27,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void MixerQmlWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MixerQmlWrapper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->attachSynthesizer((*reinterpret_cast< BasicSynthesizer*(*)>(_a[1]))); break;
        case 1: _t->attachTimeReceiver((*reinterpret_cast< ITimeReceiver*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MixerQmlWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_MixerQmlWrapper.data,
    qt_meta_data_MixerQmlWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MixerQmlWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MixerQmlWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MixerQmlWrapper.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int MixerQmlWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
