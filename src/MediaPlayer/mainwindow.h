#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mediaplayer.h>

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QVideoWidget>
#include <QTableWidget>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //[CLICK HANDLERS]
    void on_play_clicked();

    void on_open_clicked();

    void on_seek_sliderMoved(int position);

    void on_seek_sliderReleased();

    void on_volume_sliderMoved(int position);

    void on_mute_clicked();

private:
    MediaPlayer* player;
    Ui::MainWindow *ui;

    QIcon icon_play, icon_pause, icon_unmute, icon_mute;

    //[UI ELEMENTS]
    QPushButton *btn_play, *btn_open, *btn_mute;
    QLabel *lbl_media_name, *lbl_time_passed, *lbl_media_length;
    QSlider *sldr_seek, *sldr_volume;
    QVideoWidget *widget_video;
    QTableWidget *meta_table;

    //[HELPERS]
    void update_title(QString title);

    void play_media();

    void pause_media();

    void update_seek_slider(int position);

    void set_duration(int duration);

    QString format_time(int seconds);

    void display_meta_data(QMap<QString, QVariant> metadata);

    QMap<QString, QVariant> get_meta_data();

    void status_changed();

    //[DRAG & DROP]
    void dropEvent(QDropEvent* event);

    void dragEnterEvent(QDragEnterEvent *event);
};

#endif // MAINWINDOW_H
