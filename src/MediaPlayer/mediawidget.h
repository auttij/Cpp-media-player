#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QVideoWidget>
/*!
 * \class MediaWidget
 * \brief The MediaWidget class is used to display videos
 *
 * MediaWidget extends QVideoWidget adding only one feature: full screen.
 */
class MediaWidget : public QVideoWidget
{
    Q_OBJECT

public:
    explicit MediaWidget(QWidget *parent = nullptr);

protected:
    /*!
     * \brief keyPressEvent is a handler for key presses
     * \param event
     *
     * Checks if the user has pressed 'ESC' to return from full screen.
     */
    void keyPressEvent(QKeyEvent *event) override;

    /*!
     * \brief mouseDoubleClickEvent is handler for mouse double click events
     * \param event
     *
     * Checks if the video widget has been double clicked and enters/leaves full screen.
     */
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MEDIAWIDGET_H
