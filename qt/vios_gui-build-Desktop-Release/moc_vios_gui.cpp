/****************************************************************************
** Meta object code from reading C++ file 'vios_gui.h'
**
** Created: Wed Dec 5 16:20:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vios_gui/vios_gui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vios_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViosGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      27,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,
      49,    8,    8,    8, 0x08,
      61,    8,    8,    8, 0x08,
      72,    8,    8,    8, 0x08,
      82,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViosGui[] = {
    "ViosGui\0\0changeDirectory()\0fillList()\0"
    "fwd_skip()\0prev_skip()\0frame_no()\0"
    "one_fwd()\0one_prev()\0"
};

void ViosGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViosGui *_t = static_cast<ViosGui *>(_o);
        switch (_id) {
        case 0: _t->changeDirectory(); break;
        case 1: _t->fillList(); break;
        case 2: _t->fwd_skip(); break;
        case 3: _t->prev_skip(); break;
        case 4: _t->frame_no(); break;
        case 5: _t->one_fwd(); break;
        case 6: _t->one_prev(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ViosGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViosGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViosGui,
      qt_meta_data_ViosGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViosGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViosGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViosGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViosGui))
        return static_cast<void*>(const_cast< ViosGui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViosGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
