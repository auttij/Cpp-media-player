#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        player->play();
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

