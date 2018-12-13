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

    bool open_file_browser();

    bool is_playing();

};

#endif // MEDIAPLAYER_H
