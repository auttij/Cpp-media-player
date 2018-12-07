/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MediaPlayer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "on_play_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "on_meta_clicked"
QT_MOC_LITERAL(4, 44, 15), // "on_open_clicked"
QT_MOC_LITERAL(5, 60, 19), // "on_seek_sliderMoved"
QT_MOC_LITERAL(6, 80, 8), // "position"
QT_MOC_LITERAL(7, 89, 22), // "on_seek_sliderReleased"
QT_MOC_LITERAL(8, 112, 21), // "on_volume_sliderMoved"
QT_MOC_LITERAL(9, 134, 12), // "set_duration"
QT_MOC_LITERAL(10, 147, 8), // "duration"
QT_MOC_LITERAL(11, 156, 14), // "progress_media"
QT_MOC_LITERAL(12, 171, 8), // "progress"
QT_MOC_LITERAL(13, 180, 18), // "update_seek_slider"
QT_MOC_LITERAL(14, 199, 13), // "get_meta_data"
QT_MOC_LITERAL(15, 213, 23), // "on_media_status_changed"
QT_MOC_LITERAL(16, 237, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(17, 263, 6), // "status"
QT_MOC_LITERAL(18, 270, 11), // "format_time"
QT_MOC_LITERAL(19, 282, 7) // "seconds"

    },
    "MainWindow\0on_play_clicked\0\0on_meta_clicked\0"
    "on_open_clicked\0on_seek_sliderMoved\0"
    "position\0on_seek_sliderReleased\0"
    "on_volume_sliderMoved\0set_duration\0"
    "duration\0progress_media\0progress\0"
    "update_seek_slider\0get_meta_data\0"
    "on_media_status_changed\0"
    "QMediaPlayer::MediaStatus\0status\0"
    "format_time\0seconds"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      11,    1,   87,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    1,   94,    2, 0x08 /* Private */,
      18,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::QString, QMetaType::Int,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_play_clicked(); break;
        case 1: _t->on_meta_clicked(); break;
        case 2: _t->on_open_clicked(); break;
        case 3: _t->on_seek_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_seek_sliderReleased(); break;
        case 5: _t->on_volume_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->set_duration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->progress_media((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->update_seek_slider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->get_meta_data(); break;
        case 10: _t->on_media_status_changed((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 11: { QString _r = _t->format_time((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
