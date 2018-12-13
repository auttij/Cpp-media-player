#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mediaplayer.h"
#include "mediawidget.h"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QVideoWidget>
#include <QTableWidget>

namespace Ui {
    class MainWindow;
}

/*!
 * \class MainWindow
 * \brief The MainWindow class is the main window and UI of the program
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //[CLICK HANDLERS]
    /*!
     * \brief on_play_clicked plays or pauses the current media
     */
    void on_play_clicked();

    /*!
     * \brief on_open_clicked opens the file browser and plays selected media
     */
    void on_open_clicked();

    /*!
     * \brief on_seek_sliderMoved updates the current position text
     * \param int position
     */
    void on_seek_sliderMoved(int position);

    /*!
     * \brief on_seek_sliderReleased updates the media's position according to seek slider position
     */
    void on_seek_sliderReleased();

    /*!
     * \brief on_volume_sliderMoved updates the volume according to volume slider position
     * \param int position
     */
    void on_volume_sliderMoved(int position);

    /*!
     * \brief on_mute_clicked mutes or unmutes the sound
     */
    void on_mute_clicked();

private:
    /*!
     * \brief player is the player that is used to play media files
     */
    MediaPlayer* player;

    /*!
     * \brief ui is the main UI of the program
     */
    Ui::MainWindow *ui;

    QIcon icon_play, icon_pause, icon_unmute, icon_mute;

    //[UI ELEMENTS]
    QPushButton *btn_play, *btn_open, *btn_mute;
    QLabel *lbl_media_name, *lbl_time_passed, *lbl_media_length;
    QSlider *sldr_seek, *sldr_volume;
    QVideoWidget *widget_video;
    QTableWidget *meta_table;

    //[HELPERS]
    /*!
     * \brief play_media plays the current media
     * \return void
     */
    void play_media();

    /*!
     * \brief pause_media pauses the current media
     * \return void
     */
    void pause_media();

    /*!
     * \brief update_seek_slider updates the position of the position slider
     * \param position
     * \return void
     */
    void update_seek_slider(int position);

    /*!
     * \brief end_of_media puts the position of the current media back to the beginning and pauses it
     * \return void
     *
     * This function is called when QMediaPlayer emits positionChanged signal.
     */
    void end_of_media();

    /*!
     * \brief set_duration sets the slider's maximum duration and updates the corresponding text
     * \param int duration in milliseconds
     * \return void
     */
    void set_duration(int duration_in_ms);

    /*!
     * \brief format_time creates a QString (hh:mm:ss) from seconds
     * \param int seconds
     * \return QString
     */
    QString format_time(int seconds);

    /*!
     * \brief display_meta_data formats the metadata table to the \a metadata
     * \param metadata
     * \return void
     */
    void display_meta_data(QMap<QString, QVariant> metadata);

    /*!
     * \brief get_meta_data read metadata from the current media file
     * \return QMap<QString, QVariant>
     */
    QMap<QString, QVariant> get_meta_data();

    /*!
     * \brief status_changed updates the metadata table when new media is loaded
     * \return void
     */
    void status_changed();

protected:
    //[DRAG & DROP]

    /*!
     * \brief dropEvent is called when a new media file is dropped to the window. Updates current media to it
     * \param QDropEvent event
     * \return void
     */
    void dropEvent(QDropEvent* event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;
};

#endif // MAINWINDOW_H
