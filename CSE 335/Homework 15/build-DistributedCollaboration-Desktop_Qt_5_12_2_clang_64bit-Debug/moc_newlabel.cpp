/****************************************************************************
** Meta object code from reading C++ file 'newlabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DistributedCollaboration/newlabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewLabel_t {
    QByteArrayData data[10];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewLabel_t qt_meta_stringdata_NewLabel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NewLabel"
QT_MOC_LITERAL(1, 9, 20), // "changeSizeFromSlider"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "size"
QT_MOC_LITERAL(4, 36, 22), // "changeSizeFromComboBox"
QT_MOC_LITERAL(5, 59, 5), // "index"
QT_MOC_LITERAL(6, 65, 25), // "changeFontFromArielButton"
QT_MOC_LITERAL(7, 91, 7), // "toggled"
QT_MOC_LITERAL(8, 99, 23), // "changeFontFromTNRButton"
QT_MOC_LITERAL(9, 123, 25) // "changeFontFromComicButton"

    },
    "NewLabel\0changeSizeFromSlider\0\0size\0"
    "changeSizeFromComboBox\0index\0"
    "changeFontFromArielButton\0toggled\0"
    "changeFontFromTNRButton\0"
    "changeFontFromComicButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
       9,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void NewLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeSizeFromSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeSizeFromComboBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeFontFromArielButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->changeFontFromTNRButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->changeFontFromComicButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewLabel::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_NewLabel.data,
    qt_meta_data_NewLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int NewLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
