#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player->setVolume(50);
    ui->volume->setSliderPosition(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    loadMediaFile();
    ui->curr_song->setText(player->media().canonicalUrl().fileName());
    player->setPosition(0);
    player->play();
    
}

void MainWindow::loadMediaFile() {
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Audio File"));
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

}

void MainWindow::on_play_clicked()
{
    if(player->state() == player->PausedState) {
        player->play();
    } else {
        player->pause();
    }
}


void MainWindow::on_seek_sliderMoved(int ms)
{
    player->pause();
    player->setPosition(ms*1000);
    int seconds = ms / 1000;
    int minutes = seconds / 60;
    int hours = minutes / 60 ;
    QTime currentTime(hours % 60, minutes % 60, seconds % 60, ms % 1000);
    QString format = "mm:ss";
    if(hours > 0){
        format = "hh:mm:ss";
    }
    ui->time_passed->setText(currentTime.toString(format));

}

void MainWindow::on_seek_sliderReleased()
{
    player->play();
}


void MainWindow::on_volume_sliderMoved(int volume)
{
    player->setVolume(volume);
}

