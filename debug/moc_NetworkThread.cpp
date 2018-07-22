/****************************************************************************
** Meta object code from reading C++ file 'NetworkThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test/NetworkThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkThread_t {
    QByteArrayData data[12];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkThread_t qt_meta_stringdata_NetworkThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetworkThread"
QT_MOC_LITERAL(1, 14, 16), // "sigConnectToHost"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 2), // "ip"
QT_MOC_LITERAL(4, 35, 4), // "port"
QT_MOC_LITERAL(5, 40, 10), // "sendLength"
QT_MOC_LITERAL(6, 51, 3), // "len"
QT_MOC_LITERAL(7, 55, 12), // "sigStartSend"
QT_MOC_LITERAL(8, 68, 10), // "sendStoped"
QT_MOC_LITERAL(9, 79, 16), // "connectionClosed"
QT_MOC_LITERAL(10, 96, 15), // "onConnectToHost"
QT_MOC_LITERAL(11, 112, 11) // "onStartSend"

    },
    "NetworkThread\0sigConnectToHost\0\0ip\0"
    "port\0sendLength\0len\0sigStartSend\0"
    "sendStoped\0connectionClosed\0onConnectToHost\0"
    "onStartSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,
       7,    0,   57,    2, 0x06 /* Public */,
       8,    0,   58,    2, 0x06 /* Public */,
       9,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   60,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,

       0        // eod
};

void NetworkThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkThread *_t = static_cast<NetworkThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigConnectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigStartSend(); break;
        case 3: _t->sendStoped(); break;
        case 4: _t->connectionClosed(); break;
        case 5: _t->onConnectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->onStartSend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkThread::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::sigConnectToHost)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::sendLength)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::sigStartSend)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::sendStoped)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NetworkThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkThread::connectionClosed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject NetworkThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkThread.data,
      qt_meta_data_NetworkThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetworkThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkThread.stringdata0))
        return static_cast<void*>(const_cast< NetworkThread*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void NetworkThread::sigConnectToHost(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkThread::sendLength(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkThread::sigStartSend()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void NetworkThread::sendStoped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void NetworkThread::connectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
