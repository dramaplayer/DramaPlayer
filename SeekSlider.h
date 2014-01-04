#ifndef SEEKSLIDER_H
#define SEEKSLIDER_H


#include "Button.h"

class SeekSlider : public QWidget
{
    Q_OBJECT

public:

    SeekSlider(QWidget *pParent = NULL);

public slots:

    void SetDuration(qint64 duration);

    void SetPosition(qint64 position);
protected:

    virtual void mousePressEvent(QMouseEvent *e);

    virtual void paintEvent(QPaintEvent *);

signals:
    void SeekPostion(qint64);
private:

    qint64 m_Duration;
    qint64 m_Position;

    QRect m_SliderRect;
};

#endif // SEEKSLIDER_H
