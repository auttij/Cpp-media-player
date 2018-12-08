#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QTime>
#include <QStyle>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->play->setFixedSize(40,40);

    ui->open->setFixedSize(90,40);
    ui->curr_song->setFixedSize(200, 40);

    player->setVolume(50);
    ui->volume->setSliderPosition(50);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::set_duration);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::progress_media);



    videoWidget = ui->videoWidget;
    player->setVideoOutput(videoWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    loadMediaFile();
    ui->curr_song->setText(player->media().canonicalUrl().fileName()); //TODO: song name has file extension suffix in the end
    player->setPosition(0);
    player->play();
    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

}

void MainWindow::loadMediaFile() {
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Media File"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    QStringList supportedMimeTypes = player->supportedMimeTypes();

    if (!supportedMimeTypes.isEmpty()) {
        supportedMimeTypes.append("audio/x-m3u"); // MP3 playlists
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    }

    if (fileDialog.exec() == QDialog::Accepted) {
        for(auto &url: fileDialog.selectedUrls()){
            player->setMedia(url);
        }
    }
    //videoWidget->adjustSize();
    //videoWidget->setAspectRatioMode()
    //videoWidget->setFullScreen(true);
}

void MainWindow::on_play_clicked()
{
    if(player->state() == player->PausedState) {
        player->play();
        ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        player->pause();
        ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}


void MainWindow::on_seek_sliderMoved(int ms)
{
    ui->time_passed->setText(format_time(ms / 1000));
}

void MainWindow::on_seek_sliderReleased()
{
    qInfo() << ui->seek->value();
    update_seek_slider(ui->seek->value());

}


void MainWindow::on_volume_sliderMoved(int volume)
{
    player->setVolume(volume);
}

void MainWindow::set_duration(int duration_in_ms)
{
    ui->seek->setMaximum(duration_in_ms);
    ui->song_length->setText(format_time(duration_in_ms / 1000));
}

void MainWindow::update_seek_slider(int progress)
{
    progress_media(progress);
    player->setPosition(progress);
}

void MainWindow::progress_media(int progress)
{
    if(!ui->seek->isSliderDown()){
        ui->seek->setValue(progress);
        ui->time_passed->setText(format_time(progress / 1000));
    }
}

QString MainWindow::format_time(int seconds)
{

    int minutes = seconds / 60;
    int hours = minutes / 60 ;
    QTime currentTime(hours, minutes, seconds % 60); //TODO: current time for song is updated first time when 2 seconds are passed for some reason
    QString format = "mm:ss";
    if(hours > 0){
        format = "hh:mm:ss";
    }
    return currentTime.toString(format);
}
