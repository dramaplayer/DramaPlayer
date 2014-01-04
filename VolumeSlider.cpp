#include "VolumeSlider.h"

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>

VolumeSlider::VolumeSlider(QWidget *pParent)
    :QWidget(pParent),
      m_IsMute(false),
      m_Volumn(0)
{
    m_VolumnPixmap.load(":/image/volume.png");
    m_VolumnMutePixmap.load(":/image/volume_mute.png");

    setMouseTracking(true);

    setFixedSize(110, 25);
}

void VolumeSlider::SetVolumn(int volumn)
{
    m_Volumn = volumn;

    update();
}

void VolumeSlider::SetMute(bool mute)
{
    m_IsMute = mute;
}

void VolumeSlider::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    m_LogoRect = QRect(0, 0, rect().height(), rect().height());
    m_SliderRect = rect().adjusted(m_LogoRect.width(), 10, -1, -10);

    if(m_IsMute)
    {
        painter.drawPixmap(m_LogoRect, m_VolumnMutePixmap);
    }
    else
    {
        painter.drawPixmap(m_LogoRect, m_VolumnPixmap);
    }

    painter.setPen(QPen(QColor(100, 100, 100, 100)));
    painter.fillRect(m_SliderRect, QBrush(QColor(50, 50, 50, 180)));

    painter.setPen(QPen(QColor(250, 250, 250, 200)));
    painter.fillRect(m_SliderRect.adjusted(0, 0, - (100 - m_Volumn) / 100.0 * m_SliderRect.width() , 0), QBrush(QColor(255, 255, 255, 200)));
    painter.drawRect(m_SliderRect);

//    painter.setPen(QPen(QColor(0, 0, 0, 200)));
//    painter.setFont(QFont("", 11, QFont::Bold));

    //painter.fillRect(m_SliderRect.adjusted(5, 10, -5, -10), QBrush(QColor("#FFFFFF")));

}

void VolumeSlider::mousePressEvent(QMouseEvent *e)
{
    if(m_LogoRect.contains(e->pos()))
    {
        m_IsMute = !m_IsMute;

        if(m_IsMute)
        {
            emit MuteChanged(true);
        }
        else
        {
            emit MuteChanged(false);
        }

        update();
    }
    else if(m_SliderRect.contains(e->pos()))
    {
        m_Position = e->pos().x() - m_SliderRect.x();

        emit VolumnChanged(m_Position / (float) m_SliderRect.width() * 100);
    }
    QWidget::mousePressEvent(e);
}

void VolumeSlider::mouseMoveEvent(QMouseEvent *e)
{
    if(m_LogoRect.contains(e->pos()))
    {
        update();
    }

    QWidget::mouseMoveEvent(e);
}

