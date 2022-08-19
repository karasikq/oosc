/****************************************************************************
** Meta object code from reading C++ file 'SynthesizerControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/SynthesizerControls/SynthesizerControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SynthesizerControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SynthesizerControl_t {
    QByteArrayData data[46];
    char stringdata0[660];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SynthesizerControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SynthesizerControl_t qt_meta_stringdata_SynthesizerControl = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SynthesizerControl"
QT_MOC_LITERAL(1, 19, 13), // "noteActivated"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "note"
QT_MOC_LITERAL(4, 39, 8), // "velocity"
QT_MOC_LITERAL(5, 48, 12), // "noteDisabled"
QT_MOC_LITERAL(6, 61, 15), // "allNoteDisabled"
QT_MOC_LITERAL(7, 77, 17), // "dataGeneratedLeft"
QT_MOC_LITERAL(8, 95, 18), // "std::vector<float>"
QT_MOC_LITERAL(9, 114, 4), // "data"
QT_MOC_LITERAL(10, 119, 34), // "std::vector<float>::const_ite..."
QT_MOC_LITERAL(11, 154, 4), // "from"
QT_MOC_LITERAL(12, 159, 2), // "to"
QT_MOC_LITERAL(13, 162, 18), // "dataGeneratedRight"
QT_MOC_LITERAL(14, 181, 18), // "dataGeneratedMixed"
QT_MOC_LITERAL(15, 200, 20), // "dataGeneratedChannel"
QT_MOC_LITERAL(16, 221, 13), // "AudioChannel*"
QT_MOC_LITERAL(17, 235, 7), // "channel"
QT_MOC_LITERAL(18, 243, 14), // "lastPlayedNote"
QT_MOC_LITERAL(19, 258, 7), // "Note<3>"
QT_MOC_LITERAL(20, 266, 19), // "extremaLeftReceived"
QT_MOC_LITERAL(21, 286, 13), // "MinMax<float>"
QT_MOC_LITERAL(22, 300, 7), // "extrema"
QT_MOC_LITERAL(23, 308, 20), // "extremaRightReceived"
QT_MOC_LITERAL(24, 329, 20), // "extremaMixedReceived"
QT_MOC_LITERAL(25, 350, 6), // "noteOn"
QT_MOC_LITERAL(26, 357, 7), // "noteOff"
QT_MOC_LITERAL(27, 365, 10), // "allNoteOff"
QT_MOC_LITERAL(28, 376, 12), // "attachEffect"
QT_MOC_LITERAL(29, 389, 7), // "Effect*"
QT_MOC_LITERAL(30, 397, 6), // "effect"
QT_MOC_LITERAL(31, 404, 22), // "attachGeneratorControl"
QT_MOC_LITERAL(32, 427, 18), // "AGeneratorControl*"
QT_MOC_LITERAL(33, 446, 16), // "generatorControl"
QT_MOC_LITERAL(34, 463, 15), // "connectToOutput"
QT_MOC_LITERAL(35, 479, 14), // "ADataReceiver*"
QT_MOC_LITERAL(36, 494, 8), // "receiver"
QT_MOC_LITERAL(37, 503, 19), // "connectToOutputLeft"
QT_MOC_LITERAL(38, 523, 20), // "connectToOutputRight"
QT_MOC_LITERAL(39, 544, 20), // "connectToOutputMixed"
QT_MOC_LITERAL(40, 565, 19), // "connectToOutputNote"
QT_MOC_LITERAL(41, 585, 17), // "generatorControls"
QT_MOC_LITERAL(42, 603, 4), // "gain"
QT_MOC_LITERAL(43, 608, 21), // "IChangeableParameter*"
QT_MOC_LITERAL(44, 630, 11), // "synthesizer"
QT_MOC_LITERAL(45, 642, 17) // "BasicSynthesizer*"

    },
    "SynthesizerControl\0noteActivated\0\0"
    "note\0velocity\0noteDisabled\0allNoteDisabled\0"
    "dataGeneratedLeft\0std::vector<float>\0"
    "data\0std::vector<float>::const_iterator\0"
    "from\0to\0dataGeneratedRight\0"
    "dataGeneratedMixed\0dataGeneratedChannel\0"
    "AudioChannel*\0channel\0lastPlayedNote\0"
    "Note<3>\0extremaLeftReceived\0MinMax<float>\0"
    "extrema\0extremaRightReceived\0"
    "extremaMixedReceived\0noteOn\0noteOff\0"
    "allNoteOff\0attachEffect\0Effect*\0effect\0"
    "attachGeneratorControl\0AGeneratorControl*\0"
    "generatorControl\0connectToOutput\0"
    "ADataReceiver*\0receiver\0connectToOutputLeft\0"
    "connectToOutputRight\0connectToOutputMixed\0"
    "connectToOutputNote\0generatorControls\0"
    "gain\0IChangeableParameter*\0synthesizer\0"
    "BasicSynthesizer*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SynthesizerControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       3,  194, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  119,    2, 0x06 /* Public */,
       5,    1,  124,    2, 0x06 /* Public */,
       6,    0,  127,    2, 0x06 /* Public */,
       7,    3,  128,    2, 0x06 /* Public */,
      13,    3,  135,    2, 0x06 /* Public */,
      14,    3,  142,    2, 0x06 /* Public */,
      15,    1,  149,    2, 0x06 /* Public */,
      18,    1,  152,    2, 0x06 /* Public */,
      20,    1,  155,    2, 0x06 /* Public */,
      23,    1,  158,    2, 0x06 /* Public */,
      24,    1,  161,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    2,  164,    2, 0x0a /* Public */,
      26,    1,  169,    2, 0x0a /* Public */,
      27,    0,  172,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      28,    1,  173,    2, 0x02 /* Public */,
      31,    1,  176,    2, 0x02 /* Public */,
      34,    1,  179,    2, 0x02 /* Public */,
      37,    1,  182,    2, 0x02 /* Public */,
      38,    1,  185,    2, 0x02 /* Public */,
      39,    1,  188,    2, 0x02 /* Public */,
      40,    1,  191,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 10,    9,   11,   12,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 10,    9,   11,   12,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 10,    9,   11,   12,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,    3,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 35,   36,

 // properties: name, type, flags
      41, QMetaType::QVariant, 0x00095102,
      42, 0x80000000 | 43, 0x00095409,
      44, 0x80000000 | 45, 0x00095409,

       0        // eod
};

void SynthesizerControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SynthesizerControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->noteActivated((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->noteDisabled((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->allNoteDisabled(); break;
        case 3: _t->dataGeneratedLeft((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        case 4: _t->dataGeneratedRight((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        case 5: _t->dataGeneratedMixed((*reinterpret_cast< const std::vector<float>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[2])),(*reinterpret_cast< std::vector<float>::const_iterator(*)>(_a[3]))); break;
        case 6: _t->dataGeneratedChannel((*reinterpret_cast< AudioChannel*(*)>(_a[1]))); break;
        case 7: _t->lastPlayedNote((*reinterpret_cast< const Note<3>(*)>(_a[1]))); break;
        case 8: _t->extremaLeftReceived((*reinterpret_cast< MinMax<float>(*)>(_a[1]))); break;
        case 9: _t->extremaRightReceived((*reinterpret_cast< MinMax<float>(*)>(_a[1]))); break;
        case 10: _t->extremaMixedReceived((*reinterpret_cast< MinMax<float>(*)>(_a[1]))); break;
        case 11: _t->noteOn((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 12: _t->noteOff((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: _t->allNoteOff(); break;
        case 14: _t->attachEffect((*reinterpret_cast< Effect*(*)>(_a[1]))); break;
        case 15: _t->attachGeneratorControl((*reinterpret_cast< AGeneratorControl*(*)>(_a[1]))); break;
        case 16: _t->connectToOutput((*reinterpret_cast< ADataReceiver*(*)>(_a[1]))); break;
        case 17: _t->connectToOutputLeft((*reinterpret_cast< ADataReceiver*(*)>(_a[1]))); break;
        case 18: _t->connectToOutputRight((*reinterpret_cast< ADataReceiver*(*)>(_a[1]))); break;
        case 19: _t->connectToOutputMixed((*reinterpret_cast< ADataReceiver*(*)>(_a[1]))); break;
        case 20: _t->connectToOutputNote((*reinterpret_cast< ADataReceiver*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AGeneratorControl* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SynthesizerControl::*)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::noteActivated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::noteDisabled)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::allNoteDisabled)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(const std::vector<float> & , std::vector<float>::const_iterator , std::vector<float>::const_iterator );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::dataGeneratedLeft)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(const std::vector<float> & , std::vector<float>::const_iterator , std::vector<float>::const_iterator );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::dataGeneratedRight)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(const std::vector<float> & , std::vector<float>::const_iterator , std::vector<float>::const_iterator );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::dataGeneratedMixed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(AudioChannel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::dataGeneratedChannel)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(const Note<3> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::lastPlayedNote)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(MinMax<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::extremaLeftReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(MinMax<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::extremaRightReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SynthesizerControl::*)(MinMax<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SynthesizerControl::extremaMixedReceived)) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IChangeableParameter* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SynthesizerControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: *reinterpret_cast< IChangeableParameter**>(_v) = _t->getGain(); break;
        case 2: *reinterpret_cast< BasicSynthesizer**>(_v) = _t->getSynthesizer(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SynthesizerControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGeneratorControls(*reinterpret_cast< QVariant*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject SynthesizerControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_SynthesizerControl.data,
    qt_meta_data_SynthesizerControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SynthesizerControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SynthesizerControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SynthesizerControl.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int SynthesizerControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
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
void SynthesizerControl::noteActivated(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SynthesizerControl::noteDisabled(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SynthesizerControl::allNoteDisabled()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SynthesizerControl::dataGeneratedLeft(const std::vector<float> & _t1, std::vector<float>::const_iterator _t2, std::vector<float>::const_iterator _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SynthesizerControl::dataGeneratedRight(const std::vector<float> & _t1, std::vector<float>::const_iterator _t2, std::vector<float>::const_iterator _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SynthesizerControl::dataGeneratedMixed(const std::vector<float> & _t1, std::vector<float>::const_iterator _t2, std::vector<float>::const_iterator _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SynthesizerControl::dataGeneratedChannel(AudioChannel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SynthesizerControl::lastPlayedNote(const Note<3> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SynthesizerControl::extremaLeftReceived(MinMax<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SynthesizerControl::extremaRightReceived(MinMax<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SynthesizerControl::extremaMixedReceived(MinMax<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
