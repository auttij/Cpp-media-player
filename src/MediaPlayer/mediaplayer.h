#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>

/*!
 * \class MediaPlayer
 * \brief The MediaPlayer class can be used to play media
 */
class MediaPlayer : public QMediaPlayer
{
    Q_OBJECT

public:
    MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

    /*!
     * \brief open_file_browser opens the file browser
     * \return bool
     */
    bool open_file_browser();

    /*!
     * \brief is_playing returns whether the current media is playing at the moment
     * \return bool
     */
    bool is_playing();

};

#endif // MEDIAPLAYER_H
