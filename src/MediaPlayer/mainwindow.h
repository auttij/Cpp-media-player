#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_play_clicked();
    //void seek(int seconds);
    //void jump(const QModelIndex &index);


    void on_open_clicked();

private:
    Ui::MainWindow *ui;
    void loadMediaFile();
    QMediaPlayer* player = new QMediaPlayer(this);
    QVideoWidget* videoWidget = nullptr;
    std::string currentSong;

};


#endif // MAINWINDOW_H
