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
     * \brief set_video_widget adds a video widget to this player
     * \param video_widget
     * \return void
     */
    void set_video_widget(QVideoWidget* video_widget);

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

private:

    //[HELPERS]

    void init_media(QString name);

    void set_duration(int duration);

    void progress_media(int progress);

    void update_seek_slider(int progress);

};

#endif // MEDIAPLAYER_H
