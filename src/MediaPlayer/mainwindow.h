#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

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
    void on_play_clicked();
    //void seek(int seconds);
    //void jump(const QModelIndex &index);


    void on_open_clicked();

    void on_seek_sliderMoved(int position);

    void on_seek_sliderReleased();

    //void on_seek_valueChanged(int value);

    void on_volume_sliderMoved(int position);

    void set_duration(int duration);

    void progress_media(int progress);

    void update_seek_slider(int progress);

    void get_meta_data(QMediaPlayer *player);

    void on_media_status_changed(QMediaPlayer::MediaStatus status);

    QString format_time(int seconds);


private:
    Ui::MainWindow *ui;
    void loadMediaFile();
    QMediaPlayer* player = new QMediaPlayer(this);
    QVideoWidget* videoWidget = nullptr;
    std::string currentSong;
    int duration_in_ms;

};


#endif // MAINWINDOW_H
