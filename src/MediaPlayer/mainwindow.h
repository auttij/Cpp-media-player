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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void open();

    void seek(int seconds);
    void jump(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void loadMediaFile();
    QMediaPlayer* player = nullptr;
    QVideoWidget* videoWidget = nullptr;
    std::string currentSong;

};


#endif // MAINWINDOW_H
