#ifndef VOLUMESLIDER_H
#define VOLUMESLIDER_H


#include <QWidget>
#include <QPixmap>

class VolumeSlider : public QWidget
{
    Q_OBJECT
public:
    VolumeSlider(QWidget *pParent = NULL);
public slots:
    void SetVolumn(int volumn);

    void SetMute(bool);
protected:

    virtual void paintEvent(QPaintEvent *);

    virtual void mousePressEvent(QMouseEvent *);

    virtual void mouseMoveEvent(QMouseEvent *);

signals:
    void MuteChanged(bool);

    void VolumnChanged(int);
private:

    QPixmap m_VolumnPixmap;
    QPixmap m_VolumnMutePixmap;

    bool m_IsMute;
    int m_Volumn;

    QRect m_LogoRect;
    QRect m_SliderRect;

    qint64 m_Position;
};


#endif // VOLUMESLIDER_H
