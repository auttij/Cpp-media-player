#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mediaplayer.h>

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QVideoWidget>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update_seek_slider(int position);

    void update_media_name(QString name);

    void set_duration(int duration);

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

    QPushButton *btn_play, *btn_open, *btn_mute;
    QLabel *lbl_media_name, *lbl_time_passed, *lbl_media_length;
    QSlider *sldr_seek, *sldr_volume;
    QVideoWidget *widget_video;

    QIcon icon_play, icon_pause, icon_unmute, icon_mute;

    void play_media();

    void pause_media();

    //[DRAG & DROP]
    void dropEvent(QDropEvent* event);

    void dragEnterEvent(QDragEnterEvent *event);

    QString format_time(int seconds);
};


#endif // MAINWINDOW_H
