/****************************************************************************
** Meta object code from reading C++ file 'HsmsDevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HsmsDevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HsmsDevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HsmsDevice_t {
    QByteArrayData data[52];
    char stringdata0[727];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HsmsDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HsmsDevice_t qt_meta_stringdata_HsmsDevice = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HsmsDevice"
QT_MOC_LITERAL(1, 11, 9), // "dataReady"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "HSMSMessages"
QT_MOC_LITERAL(4, 35, 11), // "dataMessage"
QT_MOC_LITERAL(5, 47, 17), // "selectReqReceived"
QT_MOC_LITERAL(6, 65, 16), // "selectReqMessage"
QT_MOC_LITERAL(7, 82, 17), // "selectRspReceived"
QT_MOC_LITERAL(8, 100, 16), // "selectRspMessage"
QT_MOC_LITERAL(9, 117, 19), // "deselectReqReceived"
QT_MOC_LITERAL(10, 137, 18), // "deselectReqMessage"
QT_MOC_LITERAL(11, 156, 19), // "deselectRspReceived"
QT_MOC_LITERAL(12, 176, 18), // "deselectRspMessage"
QT_MOC_LITERAL(13, 195, 19), // "linktestReqReceived"
QT_MOC_LITERAL(14, 215, 18), // "linktestReqMessage"
QT_MOC_LITERAL(15, 234, 19), // "linktestRspReceived"
QT_MOC_LITERAL(16, 254, 18), // "linktestRspMessage"
QT_MOC_LITERAL(17, 273, 19), // "separateReqReceived"
QT_MOC_LITERAL(18, 293, 18), // "separateReqMessage"
QT_MOC_LITERAL(19, 312, 17), // "rejectReqReceived"
QT_MOC_LITERAL(20, 330, 23), // "signals_eqp_recieve_S_F"
QT_MOC_LITERAL(21, 354, 2), // "u1"
QT_MOC_LITERAL(22, 357, 1), // "S"
QT_MOC_LITERAL(23, 359, 1), // "F"
QT_MOC_LITERAL(24, 361, 2), // "u4"
QT_MOC_LITERAL(25, 364, 2), // "sb"
QT_MOC_LITERAL(26, 367, 3), // "log"
QT_MOC_LITERAL(27, 371, 23), // "signals_eqp_send_S_F_sb"
QT_MOC_LITERAL(28, 395, 11), // "sendMessage"
QT_MOC_LITERAL(29, 407, 7), // "message"
QT_MOC_LITERAL(30, 415, 15), // "sendLinkTestReq"
QT_MOC_LITERAL(31, 431, 13), // "sendSelectReq"
QT_MOC_LITERAL(32, 445, 15), // "sendDeselectReq"
QT_MOC_LITERAL(33, 461, 15), // "sendSeparateReq"
QT_MOC_LITERAL(34, 477, 8), // "sendS1F1"
QT_MOC_LITERAL(35, 486, 9), // "sendS2F17"
QT_MOC_LITERAL(36, 496, 11), // "readMessage"
QT_MOC_LITERAL(37, 508, 13), // "sendSelectRsp"
QT_MOC_LITERAL(38, 522, 8), // "uint16_t"
QT_MOC_LITERAL(39, 531, 9), // "sessionID"
QT_MOC_LITERAL(40, 541, 8), // "uint32_t"
QT_MOC_LITERAL(41, 550, 11), // "systemBytes"
QT_MOC_LITERAL(42, 562, 26), // "HSMSMessages::SelectStatus"
QT_MOC_LITERAL(43, 589, 6), // "status"
QT_MOC_LITERAL(44, 596, 7), // "seleReq"
QT_MOC_LITERAL(45, 604, 15), // "sendDeselectRsp"
QT_MOC_LITERAL(46, 620, 28), // "HSMSMessages::DeselectStatus"
QT_MOC_LITERAL(47, 649, 7), // "deseReq"
QT_MOC_LITERAL(48, 657, 15), // "sendLinkTestRsp"
QT_MOC_LITERAL(49, 673, 11), // "linktestReq"
QT_MOC_LITERAL(50, 685, 12), // "displayError"
QT_MOC_LITERAL(51, 698, 28) // "QAbstractSocket::SocketError"

    },
    "HsmsDevice\0dataReady\0\0HSMSMessages\0"
    "dataMessage\0selectReqReceived\0"
    "selectReqMessage\0selectRspReceived\0"
    "selectRspMessage\0deselectReqReceived\0"
    "deselectReqMessage\0deselectRspReceived\0"
    "deselectRspMessage\0linktestReqReceived\0"
    "linktestReqMessage\0linktestRspReceived\0"
    "linktestRspMessage\0separateReqReceived\0"
    "separateReqMessage\0rejectReqReceived\0"
    "signals_eqp_recieve_S_F\0u1\0S\0F\0u4\0sb\0"
    "log\0signals_eqp_send_S_F_sb\0sendMessage\0"
    "message\0sendLinkTestReq\0sendSelectReq\0"
    "sendDeselectReq\0sendSeparateReq\0"
    "sendS1F1\0sendS2F17\0readMessage\0"
    "sendSelectRsp\0uint16_t\0sessionID\0"
    "uint32_t\0systemBytes\0HSMSMessages::SelectStatus\0"
    "status\0seleReq\0sendDeselectRsp\0"
    "HSMSMessages::DeselectStatus\0deseReq\0"
    "sendLinkTestRsp\0linktestReq\0displayError\0"
    "QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HsmsDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,
       5,    1,  147,    2, 0x06 /* Public */,
       7,    1,  150,    2, 0x06 /* Public */,
       9,    1,  153,    2, 0x06 /* Public */,
      11,    1,  156,    2, 0x06 /* Public */,
      13,    1,  159,    2, 0x06 /* Public */,
      15,    1,  162,    2, 0x06 /* Public */,
      17,    1,  165,    2, 0x06 /* Public */,
      19,    1,  168,    2, 0x06 /* Public */,
      20,    4,  171,    2, 0x06 /* Public */,
      27,    4,  180,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      28,    1,  189,    2, 0x0a /* Public */,
      30,    0,  192,    2, 0x0a /* Public */,
      31,    0,  193,    2, 0x0a /* Public */,
      32,    0,  194,    2, 0x0a /* Public */,
      33,    0,  195,    2, 0x0a /* Public */,
      34,    0,  196,    2, 0x0a /* Public */,
      35,    0,  197,    2, 0x0a /* Public */,
      36,    0,  198,    2, 0x0a /* Public */,
      37,    3,  199,    2, 0x09 /* Protected */,
      37,    2,  206,    2, 0x09 /* Protected */,
      45,    3,  211,    2, 0x09 /* Protected */,
      45,    2,  218,    2, 0x09 /* Protected */,
      48,    1,  223,    2, 0x09 /* Protected */,
      48,    1,  226,    2, 0x09 /* Protected */,
      50,    1,  229,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,   12,
    QMetaType::Void, 0x80000000 | 3,   14,
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void, 0x80000000 | 3,   18,
    QMetaType::Void, 0x80000000 | 3,   18,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 21, 0x80000000 | 24, QMetaType::QString,   22,   23,   25,   26,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 21, 0x80000000 | 24, QMetaType::QString,   22,   23,   25,   26,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 40, 0x80000000 | 42,   39,   41,   43,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 42,   44,   43,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 40, 0x80000000 | 46,   39,   41,   43,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 46,   47,   43,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 3,   49,
    QMetaType::Void, 0x80000000 | 51,    2,

       0        // eod
};

void HsmsDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HsmsDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReady((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 1: _t->selectReqReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 2: _t->selectRspReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 3: _t->deselectReqReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 4: _t->deselectRspReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 5: _t->linktestReqReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 6: _t->linktestRspReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 7: _t->separateReqReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 8: _t->rejectReqReceived((*reinterpret_cast< HSMSMessages(*)>(_a[1]))); break;
        case 9: _t->signals_eqp_recieve_S_F((*reinterpret_cast< u1(*)>(_a[1])),(*reinterpret_cast< u1(*)>(_a[2])),(*reinterpret_cast< u4(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 10: _t->signals_eqp_send_S_F_sb((*reinterpret_cast< u1(*)>(_a[1])),(*reinterpret_cast< u1(*)>(_a[2])),(*reinterpret_cast< u4(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 11: _t->sendMessage((*reinterpret_cast< const HSMSMessages(*)>(_a[1]))); break;
        case 12: _t->sendLinkTestReq(); break;
        case 13: _t->sendSelectReq(); break;
        case 14: _t->sendDeselectReq(); break;
        case 15: _t->sendSeparateReq(); break;
        case 16: _t->sendS1F1(); break;
        case 17: _t->sendS2F17(); break;
        case 18: _t->readMessage(); break;
        case 19: _t->sendSelectRsp((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2])),(*reinterpret_cast< HSMSMessages::SelectStatus(*)>(_a[3]))); break;
        case 20: _t->sendSelectRsp((*reinterpret_cast< const HSMSMessages(*)>(_a[1])),(*reinterpret_cast< HSMSMessages::SelectStatus(*)>(_a[2]))); break;
        case 21: _t->sendDeselectRsp((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2])),(*reinterpret_cast< HSMSMessages::DeselectStatus(*)>(_a[3]))); break;
        case 22: _t->sendDeselectRsp((*reinterpret_cast< const HSMSMessages(*)>(_a[1])),(*reinterpret_cast< HSMSMessages::DeselectStatus(*)>(_a[2]))); break;
        case 23: _t->sendLinkTestRsp((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 24: _t->sendLinkTestRsp((*reinterpret_cast< const HSMSMessages(*)>(_a[1]))); break;
        case 25: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::dataReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::selectReqReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::selectRspReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::deselectReqReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::deselectRspReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::linktestReqReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::linktestRspReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::separateReqReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(HSMSMessages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::rejectReqReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(u1 , u1 , u4 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::signals_eqp_recieve_S_F)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (HsmsDevice::*)(u1 , u1 , u4 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HsmsDevice::signals_eqp_send_S_F_sb)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HsmsDevice::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HsmsDevice.data,
    qt_meta_data_HsmsDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HsmsDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HsmsDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HsmsDevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HsmsDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void HsmsDevice::dataReady(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HsmsDevice::selectReqReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HsmsDevice::selectRspReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HsmsDevice::deselectReqReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HsmsDevice::deselectRspReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HsmsDevice::linktestReqReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void HsmsDevice::linktestRspReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void HsmsDevice::separateReqReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void HsmsDevice::rejectReqReceived(HSMSMessages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void HsmsDevice::signals_eqp_recieve_S_F(u1 _t1, u1 _t2, u4 _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void HsmsDevice::signals_eqp_send_S_F_sb(u1 _t1, u1 _t2, u4 _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
