#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QTime>
#include <QStyle>
#include <QVideoWidget>
#include <QMimeData>
#include <QDropEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->play->setFixedSize(40,40);

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
    init_media(player->media().canonicalUrl().fileName()); //TODO: media name has file extension suffix in the end
    play_media();
}

void MainWindow::init_media(QString name)
{
    ui->curr_song->setText(name);
    player->setPosition(0);
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
  const QMimeData* mimeData = event->mimeData();

  // check for our needed mime type, here a file or a list of files

    QStringList pathList;
    QList<QUrl> urlList = mimeData->urls();

    // extract the local paths of the files
    for (int i = 0; i < urlList.size() && i < 32; ++i)
    {
      pathList.append(urlList.at(i).toLocalFile());
    }

    // call a function to open the files
    player->setMedia(mimeData->urls()[0]);
    init_media(player->media().canonicalUrl().fileName());
    play_media();
}
