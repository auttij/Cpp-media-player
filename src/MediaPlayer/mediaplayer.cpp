#include "mediaplayer.h"

#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QTime>
#include <QStyle>
#include <QVideoWidget>
#include <QMimeData>
#include <QDropEvent>
#include <QVariant>

MediaPlayer::MediaPlayer(QWidget *parent) :
    QMediaPlayer(parent)
{

}

MediaPlayer::~MediaPlayer()
{
}

void MediaPlayer::set_video_widget(QVideoWidget* video_widget)
{
    this->setVideoOutput(video_widget);
}

bool MediaPlayer::open_file_browser() {
    QFileDialog fileDialog(new QWidget());
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Media File"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath())); //TODO: Change start location
    bool success = fileDialog.exec();
    if (success) {
        this->setMedia(fileDialog.selectedUrls().first());
    }
    return success;
}

bool MediaPlayer::is_playing()
{
    return this->state() == QMediaPlayer::PlayingState;
}
