/****************************************************************************
** Meta object code from reading C++ file 'alexlabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LectureMediatorFonts/alexlabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alexlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AlexLabel_t {
    QByteArrayData data[8];
    char stringdata[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlexLabel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlexLabel_t qt_meta_stringdata_AlexLabel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AlexLabel"
QT_MOC_LITERAL(1, 10, 7), // "setFont"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "setFontByText"
QT_MOC_LITERAL(4, 33, 24), // "modifyFontByCheckboxBold"
QT_MOC_LITERAL(5, 58, 26), // "modifyFontByCheckboxItalic"
QT_MOC_LITERAL(6, 85, 29), // "modifyFontByCheckboxUnderline"
QT_MOC_LITERAL(7, 115, 24) // "modifyFontByCheckboxSize"

    },
    "AlexLabel\0setFont\0\0setFontByText\0"
    "modifyFontByCheckboxBold\0"
    "modifyFontByCheckboxItalic\0"
    "modifyFontByCheckboxUnderline\0"
    "modifyFontByCheckboxSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlexLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       3,    1,   47,    2, 0x0a /* Public */,
       4,    1,   50,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       6,    1,   56,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QFont,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void AlexLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlexLabel *_t = static_cast<AlexLabel *>(_o);
        switch (_id) {
        case 0: _t->setFont((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 1: _t->setFontByText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->modifyFontByCheckboxBold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->modifyFontByCheckboxItalic((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->modifyFontByCheckboxUnderline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->modifyFontByCheckboxSize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AlexLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_AlexLabel.data,
      qt_meta_data_AlexLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AlexLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlexLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AlexLabel.stringdata))
        return static_cast<void*>(const_cast< AlexLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int AlexLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
