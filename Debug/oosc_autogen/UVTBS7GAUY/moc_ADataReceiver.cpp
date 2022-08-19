/****************************************************************************
** Meta object code from reading C++ file 'ADataReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Charts/ADataReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ADataReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ADataReceiverSlots_t {
    QByteArrayData data[14];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ADataReceiverSlots_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ADataReceiverSlots_t qt_meta_stringdata_ADataReceiverSlots = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ADataReceiverSlots"
QT_MOC_LITERAL(1, 19, 10), // "dataUpdate"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "std::vector<float>"
QT_MOC_LITERAL(4, 50, 4), // "data"
QT_MOC_LITERAL(5, 55, 34), // "std::vector<float>::const_ite..."
QT_MOC_LITERAL(6, 90, 4), // "from"
QT_MOC_LITERAL(7, 95, 2), // "to"
QT_MOC_LITERAL(8, 98, 17), // "dataUpdateChannel"
QT_MOC_LITERAL(9, 116, 13), // "AudioChannel*"
QT_MOC_LITERAL(10, 130, 7), // "channel"
QT_MOC_LITERAL(11, 138, 16), // "lastNoteReceived"
QT_MOC_LITERAL(12, 155, 7), // "Note<3>"
QT_MOC_LITERAL(13, 163, 4) // "note"

    },
    "ADataReceiverSlots\0dataUpdate\0\0"
    "std::vector<float>\0data\0"
    "std::vector<float>::const_iterator\0"
    "from\0to\0dataUpdateChannel\0AudioChannel*\0"
    "channel\0lastNoteReceived\0Note<3>\0note"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ADataReceiverSlots[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x0a /* Public */,
       8,    1,   36,    2, 0x0a /* Public */,
      11,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void ADataReceiverSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ADataReceiverSlots *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataUpdate((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        case 1: _t->dataUpdateChannel((*reinterpret_cast< AudioChannel*(*)>(_a[1]))); break;
        case 2: _t->lastNoteReceived((*reinterpret_cast< const Note<3>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ADataReceiverSlots::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ADataReceiverSlots.data,
    qt_meta_data_ADataReceiverSlots,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ADataReceiverSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ADataReceiverSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ADataReceiverSlots.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ADataReceiverSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
