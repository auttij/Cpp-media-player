#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>

class MediaPlayer : public QMediaPlayer
{
    Q_OBJECT

public:
    MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

    void set_video_widget(QVideoWidget* video_widget);

    bool open_file_browser();

    bool is_playing();

private:

    //[HELPERS]

    void init_media(QString name);

    void set_duration(int duration);

    void progress_media(int progress);

    void update_seek_slider(int progress);

};

#endif // MEDIAPLAYER_H
