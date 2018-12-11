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

    //[CLICK HANDLERS]
    void on_play_clicked();
    
    void on_meta_clicked();

    void on_open_clicked();

    void on_seek_sliderMoved(int position);

    void on_seek_sliderReleased();

    void on_volume_sliderMoved(int position);

    //[HELPERS]
    void open_media(QUrl url);

    void init_media(QString name);

    void play_media();

    void pause_media();

    void set_duration(int duration);

    void progress_media(int progress);

    void update_seek_slider(int progress);

    void display_meta_data(std::vector<std::pair<QString, QVariant>> metadata);

    //[DRAG & DROP]
    void dropEvent(QDropEvent* event);

    void dragEnterEvent(QDragEnterEvent *event);

    //[UTIL]
    void get_meta_data();

    QString format_time(int seconds);

    void on_mute_clicked();

private:
    Ui::MainWindow *ui;
    void loadMediaFile();
    QMediaPlayer* player = new QMediaPlayer(this);
    QVideoWidget* videoWidget;
    std::string currentSong;
    int duration_in_ms;

};


#endif // MAINWINDOW_H
