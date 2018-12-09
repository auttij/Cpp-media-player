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
    void init_media(QString name);

    void play_media();

    void pause_media();

    void on_play_clicked();

    void on_open_clicked();

    void on_seek_sliderMoved(int position);

    void on_seek_sliderReleased();

    //void on_seek_valueChanged(int value);

    void on_volume_sliderMoved(int position);

    void set_duration(int duration);

    void progress_media(int progress);

    void update_seek_slider(int progress);

    QString format_time(int seconds);

    void dropEvent(QDropEvent* event);

    void dragEnterEvent(QDragEnterEvent *event);


private:
    Ui::MainWindow *ui;
    void loadMediaFile();
    QMediaPlayer* player = new QMediaPlayer(this);
    QVideoWidget* videoWidget;
    std::string currentSong;
    int duration_in_ms;

};


#endif // MAINWINDOW_H
