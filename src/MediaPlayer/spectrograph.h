#ifndef SPECTROGRAPH_H
#define SPECTROGRAPH_H

//#include "frequencyspectrum.h"

#include <QWidget>

/**
 * The spectrum that holds 
 */
class FrequencySpectrum : public QObject {
    Q_OBJECT
    
public:
    explicit FrequencySpectrum();
    ~FrequencySpectrum();
    
    
};


/**
 * The spectograph widget which displays fft frequencies with frequency spectrum
 */
class Spectrograph : public QWidget
{
    Q_OBJECT

public:
    explicit Spectrograph(QWidget *parent = 0);
    ~Spectrograph();

    void setParams(int nofFreqs, qreal maxFreq, qreal minFreq);

    // QObject
    void timerEvent(QTimerEvent *event) override;

    // QWidget
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    void reset();
    void changeSpectrum(const FrequencySpectrum &spectrum);

private:

    int timerId;
    int selectedFreq;
    qreal minFreq;
    qreal maxFreq;
    FrequencySpectrum spectrum;

};

#endif // SPECTROGRAPH_H
