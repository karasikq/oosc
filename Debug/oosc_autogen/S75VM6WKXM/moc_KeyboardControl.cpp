/****************************************************************************
** Meta object code from reading C++ file 'KeyboardControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/UI/Controls/KeyboardControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeyboardControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeyboardControl_t {
    QByteArrayData data[18];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyboardControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyboardControl_t qt_meta_stringdata_KeyboardControl = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KeyboardControl"
QT_MOC_LITERAL(1, 16, 15), // "keyColorChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "color"
QT_MOC_LITERAL(4, 39, 17), // "sharpColorChanged"
QT_MOC_LITERAL(5, 57, 21), // "activeKeyColorChanged"
QT_MOC_LITERAL(6, 79, 23), // "activeSharpColorChanged"
QT_MOC_LITERAL(7, 103, 6), // "noteOn"
QT_MOC_LITERAL(8, 110, 4), // "note"
QT_MOC_LITERAL(9, 115, 8), // "velocity"
QT_MOC_LITERAL(10, 124, 7), // "noteOff"
QT_MOC_LITERAL(11, 132, 10), // "allNoteOff"
QT_MOC_LITERAL(12, 143, 11), // "synthesizer"
QT_MOC_LITERAL(13, 155, 19), // "SynthesizerControl*"
QT_MOC_LITERAL(14, 175, 8), // "keyColor"
QT_MOC_LITERAL(15, 184, 10), // "sharpColor"
QT_MOC_LITERAL(16, 195, 14), // "keyActiveColor"
QT_MOC_LITERAL(17, 210, 16) // "sharpActiveColor"

    },
    "KeyboardControl\0keyColorChanged\0\0color\0"
    "sharpColorChanged\0activeKeyColorChanged\0"
    "activeSharpColorChanged\0noteOn\0note\0"
    "velocity\0noteOff\0allNoteOff\0synthesizer\0"
    "SynthesizerControl*\0keyColor\0sharpColor\0"
    "keyActiveColor\0sharpActiveColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyboardControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       5,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   61,    2, 0x0a /* Public */,
      10,    1,   66,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    8,    9,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void,

 // properties: name, type, flags
      12, 0x80000000 | 13, 0x0009500a,
      14, QMetaType::QColor, 0x00495103,
      15, QMetaType::QColor, 0x00495103,
      16, QMetaType::QColor, 0x00495003,
      17, QMetaType::QColor, 0x00495003,

 // properties: notify_signal_id
       0,
       0,
       1,
       2,
       3,

       0        // eod
};

void KeyboardControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KeyboardControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->keyColorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->sharpColorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->activeKeyColorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->activeSharpColorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->noteOn((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 5: _t->noteOff((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->allNoteOff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KeyboardControl::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyboardControl::keyColorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KeyboardControl::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyboardControl::sharpColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KeyboardControl::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyboardControl::activeKeyColorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KeyboardControl::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyboardControl::activeSharpColorChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SynthesizerControl* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<KeyboardControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getKeyColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getSharpColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->getActiveKeyColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getActiveSharpColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<KeyboardControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->attachSynthesizer(*reinterpret_cast< SynthesizerControl**>(_v)); break;
        case 1: _t->setKeyColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setSharpColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setActiveKeyColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setActiveSharpColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject KeyboardControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_KeyboardControl.data,
    qt_meta_data_KeyboardControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KeyboardControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyboardControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyboardControl.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int KeyboardControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void KeyboardControl::keyColorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KeyboardControl::sharpColorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KeyboardControl::activeKeyColorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KeyboardControl::activeSharpColorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
