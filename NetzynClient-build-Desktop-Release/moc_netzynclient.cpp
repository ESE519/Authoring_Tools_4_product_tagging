/****************************************************************************
** Meta object code from reading C++ file 'netzynclient.h'
**
** Created: Fri Mar 8 20:46:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NetzynClient/netzynclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netzynclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NetzynClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   14,   13,   13, 0x05,
      57,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   13,   13,   13, 0x08,
      83,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NetzynClient[] = {
    "NetzynClient\0\0socketError\0"
    "error(QTcpSocket::SocketError)\0"
    "updateScene()\0readyRead()\0disconnected()\0"
};

void NetzynClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NetzynClient *_t = static_cast<NetzynClient *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->updateScene(); break;
        case 2: _t->readyRead(); break;
        case 3: _t->disconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NetzynClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NetzynClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetzynClient,
      qt_meta_data_NetzynClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NetzynClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NetzynClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NetzynClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetzynClient))
        return static_cast<void*>(const_cast< NetzynClient*>(this));
    return QObject::qt_metacast(_clname);
}

int NetzynClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NetzynClient::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetzynClient::updateScene()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
