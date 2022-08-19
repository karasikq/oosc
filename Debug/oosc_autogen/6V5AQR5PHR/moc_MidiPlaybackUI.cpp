/****************************************************************************
** Meta object code from reading C++ file 'MidiPlaybackUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Midi/MidiPlaybackUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MidiPlaybackUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MidiPlaybackUI_t {
    QByteArrayData data[17];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MidiPlaybackUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MidiPlaybackUI_t qt_meta_stringdata_MidiPlaybackUI = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MidiPlaybackUI"
QT_MOC_LITERAL(1, 15, 18), // "synthesizerChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "playbackTimeChanged"
QT_MOC_LITERAL(4, 55, 10), // "timeChange"
QT_MOC_LITERAL(5, 66, 8), // "loadMidi"
QT_MOC_LITERAL(6, 75, 8), // "fileName"
QT_MOC_LITERAL(7, 84, 14), // "attachPlayback"
QT_MOC_LITERAL(8, 99, 14), // "detachPlayback"
QT_MOC_LITERAL(9, 114, 4), // "play"
QT_MOC_LITERAL(10, 119, 4), // "stop"
QT_MOC_LITERAL(11, 124, 5), // "pause"
QT_MOC_LITERAL(12, 130, 12), // "loadFromFile"
QT_MOC_LITERAL(13, 143, 15), // "loadFromFileUrl"
QT_MOC_LITERAL(14, 159, 12), // "playbackTime"
QT_MOC_LITERAL(15, 172, 11), // "synthesizer"
QT_MOC_LITERAL(16, 184, 19) // "SynthesizerControl*"

    },
    "MidiPlaybackUI\0synthesizerChanged\0\0"
    "playbackTimeChanged\0timeChange\0loadMidi\0"
    "fileName\0attachPlayback\0detachPlayback\0"
    "play\0stop\0pause\0loadFromFile\0"
    "loadFromFileUrl\0playbackTime\0synthesizer\0"
    "SynthesizerControl*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidiPlaybackUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       2,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   75,    2, 0x02 /* Public */,
       8,    0,   76,    2, 0x02 /* Public */,
       9,    0,   77,    2, 0x02 /* Public */,
      10,    0,   78,    2, 0x02 /* Public */,
      11,    0,   79,    2, 0x02 /* Public */,
      12,    1,   80,    2, 0x02 /* Public */,
      13,    1,   83,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    6,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    6,
    QMetaType::Void, QMetaType::QVariant,    6,

 // properties: name, type, flags
      14, QMetaType::Float, 0x00095401,
      15, 0x80000000 | 16, 0x0009510a,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

void MidiPlaybackUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MidiPlaybackUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->synthesizerChanged(); break;
        case 1: _t->playbackTimeChanged(); break;
        case 2: _t->timeChange(); break;
        case 3: _t->loadMidi((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 4: _t->attachPlayback(); break;
        case 5: _t->detachPlayback(); break;
        case 6: _t->play(); break;
        case 7: _t->stop(); break;
        case 8: _t->pause(); break;
        case 9: _t->loadFromFile((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 10: _t->loadFromFileUrl((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MidiPlaybackUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiPlaybackUI::synthesizerChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MidiPlaybackUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MidiPlaybackUI::playbackTimeChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SynthesizerControl* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MidiPlaybackUI *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->getPlaybackTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MidiPlaybackUI *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSynthesizer(*reinterpret_cast< SynthesizerControl**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MidiPlaybackUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_MidiPlaybackUI.data,
    qt_meta_data_MidiPlaybackUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MidiPlaybackUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MidiPlaybackUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MidiPlaybackUI.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int MidiPlaybackUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MidiPlaybackUI::synthesizerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MidiPlaybackUI::playbackTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
