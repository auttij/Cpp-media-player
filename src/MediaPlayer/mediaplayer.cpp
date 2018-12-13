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

bool MediaPlayer::open_file_browser() {
    QFileDialog fileDialog(new QWidget());
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Media File"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));

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
