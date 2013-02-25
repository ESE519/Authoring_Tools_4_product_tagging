/****************************************************************************
** Meta object code from reading C++ file 'vios_gui.h'
**
** Created: Wed Jan 16 12:23:30 2013
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
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      30,    8,    8,    8, 0x05,
      55,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,    8,    8,    8, 0x08,
      88,    8,    8,    8, 0x08,
     107,    8,    8,    8, 0x08,
     128,    8,    8,    8, 0x08,
     141,    8,    8,    8, 0x08,
     156,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViosGui[] = {
    "ViosGui\0\0map_buttons(QString)\0"
    "obj_map_buttons(QString)\0mouseClickEvent()\0"
    "browse_files()\0change_skip_step()\0"
    "menu_decode(QString)\0set_slider()\0"
    "show_margins()\0change_margins(double)\0"
};

void ViosGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViosGui *_t = static_cast<ViosGui *>(_o);
        switch (_id) {
        case 0: _t->map_buttons((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->obj_map_buttons((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->mouseClickEvent(); break;
        case 3: _t->browse_files(); break;
        case 4: _t->change_skip_step(); break;
        case 5: _t->menu_decode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->set_slider(); break;
        case 7: _t->show_margins(); break;
        case 8: _t->change_margins((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ViosGui::map_buttons(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ViosGui::obj_map_buttons(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ViosGui::mouseClickEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
