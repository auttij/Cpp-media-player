#include <QtTest/QtTest>

class TestMediaPlayer: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

void TestMediaPlayer:: toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_APPLESS_MAIN(TestMediaPlayer)
#include "testmediaplayer.moc"
