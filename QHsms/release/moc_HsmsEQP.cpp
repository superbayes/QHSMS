/****************************************************************************
** Meta object code from reading C++ file 'HsmsEQP.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HsmsEQP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HsmsEQP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HsmsEQP_t {
    QByteArrayData data[8];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HsmsEQP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HsmsEQP_t qt_meta_stringdata_HsmsEQP = {
    {
QT_MOC_LITERAL(0, 0, 7), // "HsmsEQP"
QT_MOC_LITERAL(1, 8, 12), // "disconnected"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "newConnection"
QT_MOC_LITERAL(4, 36, 20), // "signals_listenStatus"
QT_MOC_LITERAL(5, 57, 14), // "isListenScuess"
QT_MOC_LITERAL(6, 72, 15), // "onNewConnection"
QT_MOC_LITERAL(7, 88, 14) // "onDisconnected"

    },
    "HsmsEQP\0disconnected\0\0newConnection\0"
    "signals_listenStatus\0isListenScuess\0"
    "onNewConnection\0onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HsmsEQP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x09 /* Protected */,
       7,    0,   45,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HsmsEQP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HsmsEQP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->newConnection(); break;
        case 2: _t->signals_listenStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onNewConnection(); break;
        case 4: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HsmsEQP::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsEQP::disconnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HsmsEQP::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsEQP::newConnection)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HsmsEQP::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsEQP::signals_listenStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HsmsEQP::staticMetaObject = { {
    &HsmsDevice::staticMetaObject,
    qt_meta_stringdata_HsmsEQP.data,
    qt_meta_data_HsmsEQP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HsmsEQP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HsmsEQP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HsmsEQP.stringdata0))
        return static_cast<void*>(this);
    return HsmsDevice::qt_metacast(_clname);
}

int HsmsEQP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HsmsDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HsmsEQP::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HsmsEQP::newConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HsmsEQP::signals_listenStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
