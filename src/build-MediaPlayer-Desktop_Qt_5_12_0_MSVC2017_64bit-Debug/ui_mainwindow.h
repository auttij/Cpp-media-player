/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *seek;
    QSlider *volume;
    QLabel *time_passed;
    QLabel *song_length;
    QLabel *curr_song;
    QFrame *frame;
    QPushButton *play;
    QPushButton *open;
    QPushButton *meta;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(616, 397);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        seek = new QSlider(centralWidget);
        seek->setObjectName(QString::fromUtf8("seek"));
        seek->setGeometry(QRect(80, 240, 401, 20));
        seek->setOrientation(Qt::Horizontal);
        volume = new QSlider(centralWidget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(560, 200, 20, 71));
        volume->setOrientation(Qt::Vertical);
        time_passed = new QLabel(centralWidget);
        time_passed->setObjectName(QString::fromUtf8("time_passed"));
        time_passed->setGeometry(QRect(20, 240, 61, 20));
        song_length = new QLabel(centralWidget);
        song_length->setObjectName(QString::fromUtf8("song_length"));
        song_length->setGeometry(QRect(490, 240, 47, 21));
        curr_song = new QLabel(centralWidget);
        curr_song->setObjectName(QString::fromUtf8("curr_song"));
        curr_song->setGeometry(QRect(220, 210, 151, 21));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 0, 511, 191));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        play = new QPushButton(centralWidget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(250, 270, 61, 22));
        open = new QPushButton(centralWidget);
        open->setObjectName(QString::fromUtf8("open"));
        open->setEnabled(true);
        open->setGeometry(QRect(20, 270, 90, 40));
        meta = new QPushButton(centralWidget);
        meta->setObjectName(QString::fromUtf8("meta"));
        meta->setGeometry(QRect(120, 270, 40, 40));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        time_passed->setText(QApplication::translate("MainWindow", "0:00", nullptr));
        song_length->setText(QApplication::translate("MainWindow", "0:00", nullptr));
        curr_song->setText(QString());
#ifndef QT_NO_WHATSTHIS
        play->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>This is play/pause button</p><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        play->setText(QString());
        open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        meta->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
