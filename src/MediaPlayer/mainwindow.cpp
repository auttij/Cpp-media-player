#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mediawidget.h"

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
    player = new MediaPlayer(this);
    ui->setupUi(this);

    btn_play = ui->play;
    btn_open = ui->open;
    btn_mute = ui->mute;
    lbl_media_name = ui->media_name;
    lbl_time_passed = ui->time_passed;
    lbl_media_length = ui->media_length;
    sldr_seek = ui->seek;
    sldr_volume = ui->volume;
    meta_table = ui->metaTable;
    widget_video = ui->videoWidget;

    icon_play = style()->standardIcon(QStyle::SP_MediaPlay);
    icon_pause = style()->standardIcon(QStyle::SP_MediaPause);
    icon_unmute = style()->standardIcon(QStyle::SP_MediaVolume);
    icon_mute = style()->standardIcon(QStyle::SP_MediaVolumeMuted);

    btn_play->setFixedSize(60,60);
    btn_play->setIcon(icon_play);

    btn_mute->setFixedSize(40,40);
    btn_mute->setIcon(icon_unmute);
    btn_mute->setFocusPolicy(Qt::NoFocus);

    btn_open->setFocusPolicy(Qt::NoFocus);

    btn_open->setFixedSize(90,40);
    lbl_media_name->setFixedSize(200, 40);
    sldr_volume->setSliderPosition(50);
    player->setVideoOutput(widget_video);

    meta_table->setFocusPolicy(Qt::NoFocus);

    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::set_duration);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::update_seek_slider);
    connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::end_of_media);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::status_changed);

    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
}

void MainWindow::end_of_media() {

    if (player->state() == player->StoppedState) {
        player->setPosition(0);
        pause_media();
    }

}

void MainWindow::on_open_clicked()
{
    if (player->open_file_browser()) {
        play_media();
    }
}

void MainWindow::on_play_clicked()
{
    player->is_playing() ? pause_media() : play_media();
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
    if (!sldr_seek->isSliderDown()) {
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        on_play_clicked();
    }
}

QMap<QString, QVariant> MainWindow::get_meta_data()
{
   // Get the list of keys there is metadata available for
   QStringList metadatalist = player->availableMetaData();
   int list_size = metadatalist.size();
   QString metadata_key;
   QMap<QString, QVariant> metadata;

   for (int i = 0; i < list_size; i++) {
     metadata_key = metadatalist.at(i);
     metadata[metadata_key] = player->metaData(metadata_key);
   }
   return metadata;
}

void MainWindow::display_meta_data(QMap<QString, QVariant> metadata)
{
    int list_size = metadata.size();
    QStringList headers = { "Name", "Value" };

    meta_table->clear();
    meta_table->setColumnCount(2);
    meta_table->setRowCount(list_size);
    meta_table->setHorizontalHeaderLabels(headers);
    meta_table->verticalHeader()->setVisible(false);
    meta_table->horizontalHeader()->setStretchLastSection(true);
    meta_table->setColumnWidth(0, 104);
    meta_table->setColumnWidth(1, 104);

    QMapIterator<QString, QVariant> i(metadata);
    int j = 0;
    while (i.hasNext()) {
        i.next();
        meta_table->setItem(j, 0, new QTableWidgetItem(i.key()));
        meta_table->setItem(j++, 1, new QTableWidgetItem(i.value().toString()));
    }
}

void MainWindow::status_changed()
{
    if (player->mediaStatus() == QMediaPlayer::BufferedMedia || player->mediaStatus() == QMediaPlayer::LoadedMedia) {
        QMap<QString, QVariant> metadata = get_meta_data();
        display_meta_data(metadata);
        QString title = metadata["Title"].toString();
        lbl_media_name->setText(title.length() != 0 ? title : player->media().canonicalUrl().fileName());
    }
}
