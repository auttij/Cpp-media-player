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
    ui->setupUi(this);
    setAcceptDrops(true);

    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->play->setFixedSize(60,60);

    ui->mute->setIcon(style()->standardIcon((QStyle::SP_MediaVolume)));
    ui->mute->setFixedSize(40,40);

    ui->curr_song->setFixedSize(200, 40);
    ui->open->setFixedSize(90,40);
    player->setVolume(50);
    ui->volume->setSliderPosition(50);
    ui->metaTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::set_duration);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::progress_media);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::status_changed);


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
}

void MainWindow::loadMediaFile() {
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Media File"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath())); //TODO: Change start location

    if (fileDialog.exec()) {
        open_media(fileDialog.selectedUrls()[0]);
    }
}

void MainWindow::open_media(QUrl url)
{
    player->setMedia(url);
    player->setPosition(0);
    play_media();
}

void MainWindow::update_title(QString title)
{
    QUrl url = player->media().canonicalUrl();
    QString name = title.length() != 0 ? title : url.fileName();
    ui->curr_song->setText(name);
}

void MainWindow::play_media()
{
    player->play();
    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}

void MainWindow::pause_media()
{
    player->pause();
    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void MainWindow::on_play_clicked()
{
    player->state() == player->PausedState ? play_media() : pause_media();
}

void MainWindow::on_mute_clicked()
{
    player->setMuted(!player->isMuted());
    ui->mute->setIcon(style()->standardIcon(player->isMuted() ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
}

void MainWindow::on_seek_sliderMoved(int ms)
{
    ui->time_passed->setText(format_time(ms / 1000));
}

void MainWindow::on_seek_sliderReleased()
{
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
    open_media(event->mimeData()->urls()[0]);
}

QMap<QString, QVariant> MainWindow::get_meta_data()
{
   // Get the list of keys there is metadata available for
   QStringList metadatalist = player->availableMetaData();
   int list_size = metadatalist.size();
   QString metadata_key;
   QVariant var_data;
   QMap<QString, QVariant> metadata;

   for (int i = 0; i < list_size; i++)
   {
     metadata_key = metadatalist.at(i);
     var_data = player->metaData(metadata_key);
     metadata[metadata_key] = var_data;
   }
   return metadata;
}

void MainWindow::display_meta_data(QMap<QString, QVariant> metadata)
{
    int list_size = metadata.size();
    QStringList headers = { "Name", "Value" };

    ui->metaTable->clear();
    ui->metaTable->setColumnCount(2);
    ui->metaTable->setRowCount(list_size);
    ui->metaTable->setHorizontalHeaderLabels(headers);
    ui->metaTable->verticalHeader()->setVisible(false);
    //ui->metaTable->horizontalHeader()->setStretchLastSection(true);
    ui->metaTable->setColumnWidth(0, 104);
    ui->metaTable->setColumnWidth(1, 104);

    QMapIterator<QString, QVariant> i(metadata);
    int j = 0;
    while (i.hasNext()) {
        i.next();
        ui->metaTable->setItem(j, 0, new QTableWidgetItem(i.key()));
        ui->metaTable->setItem(j++, 1, new QTableWidgetItem(i.value().toString()));
    }
}

void MainWindow::status_changed()
{
    if (player->mediaStatus() == QMediaPlayer::BufferedMedia ||
            player->mediaStatus() == QMediaPlayer::LoadedMedia)
    {
        QMap<QString, QVariant> metadata = get_meta_data();
        display_meta_data(metadata);
        update_title(metadata["Title"].toString());
    }
}
