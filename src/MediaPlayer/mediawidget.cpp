#include "mediawidget.h"

#include <QKeyEvent>
#include <QMouseEvent>

MediaWidget::MediaWidget(QWidget *parent)
    : QVideoWidget(parent)
{
}

void MediaWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape && isFullScreen()) {
        setFullScreen(false);
        event->accept();
    }
}

void MediaWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(!isFullScreen());
    event->accept();
}
