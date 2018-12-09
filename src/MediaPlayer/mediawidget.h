#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QVideoWidget>
/**
 * @brief The MediaWidget class extends the basic QVideoWidget to add full screen
 *
 */
class MediaWidget : public QVideoWidget
{
    Q_OBJECT

public:
    explicit MediaWidget(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MEDIAPLAYER_H
