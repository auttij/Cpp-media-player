#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QTime>
#include <QMediaMetaData>
#include <QStyle>
#include <QVideoWidget>
#include <QMimeData>
#include <QDropEvent>
#include <QVariant>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    player = new MediaPlayer();
    ui->setupUi(this);

    btn_play = ui->play;
    btn_open = ui->open;
    btn_mute = ui->mute;
    lbl_media_name = ui->media_name;
    lbl_time_passed = ui->time_passed;
    lbl_media_length = ui->media_length;
    sldr_seek = ui->seek;
    sldr_volume = ui->volume;
    //widget_video = ui->videoWidget;

    icon_play = style()->standardIcon(QStyle::SP_MediaPlay);
    icon_pause = style()->standardIcon(QStyle::SP_MediaPause);
    icon_unmute = style()->standardIcon(QStyle::SP_MediaVolume);
    icon_mute = style()->standardIcon(QStyle::SP_MediaVolumeMuted);

    setAcceptDrops(true);

    btn_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    btn_play->setFixedSize(60,60);

    btn_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    btn_mute->setFixedSize(40,40);

    lbl_media_name->setFixedSize(200, 40);
    btn_open->setFixedSize(90,40);
    sldr_volume->setSliderPosition(50);

    Q_ASSERT(connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::set_duration));
    Q_ASSERT(connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::update_seek_slider));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    if(player->open_file_browser()){
        play_media();
    }
}

void MainWindow::on_play_clicked()
{
    if(player->is_playing()){
        pause_media();
    }else{
        play_media();
    }
}

void MainWindow::on_mute_clicked()
{
    player->setMuted(!player->isMuted());
    btn_mute->setIcon(player->isMuted() ? icon_mute : icon_unmute);
}

void MainWindow::on_volume_sliderMoved(int volume)
{
    player->setVolume(volume);
}

void MainWindow::on_seek_sliderMoved(int ms)
{
    lbl_time_passed->setText(format_time(ms / 1000));
}

void MainWindow::on_seek_sliderReleased()
{
    int position = sldr_seek->value();
    update_seek_slider(position);
    player->setPosition(position);
}

void MainWindow::update_seek_slider(int progress)
{
    if(!sldr_seek->isSliderDown()){
        sldr_seek->setValue(progress);
        lbl_time_passed->setText(format_time(progress / 1000));
    }
}

void MainWindow::play_media()
{
    player->play();
    btn_play->setIcon(icon_pause);
}

void MainWindow::pause_media()
{
    player->pause();
    btn_play->setIcon(icon_play);
}

void MainWindow::set_duration(int duration_in_ms)
{
    sldr_seek->setMaximum(duration_in_ms);
    lbl_media_length->setText(format_time(duration_in_ms / 1000));
}

QString MainWindow::format_time(int seconds)
{
    int minutes = seconds / 60;
    int hours = minutes / 60 ;
    QTime currentTime(hours, minutes, seconds % 60); //TODO: current time for song is updated first time when 2 seconds are passed for some reason
    QString format = hours >= 1 ? "hh:mm:ss" : "mm:ss";
    return currentTime.toString(format);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent* event)
{
    player->setMedia(event->mimeData()->urls().first());
    play_media();
}
