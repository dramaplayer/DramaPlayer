#include "SeekSlider.h"

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QMouseEvent>
#include <QRadialGradient>
#include <QTime>


SeekSlider::SeekSlider(QWidget *pParent)
    :QWidget(pParent),
      m_Duration(1),
      m_Position(0)
{
    setFixedSize(290, 20);

}

void SeekSlider::paintEvent(QPaintEvent *)
{
    QPainter painter(this);



    QRect startTimeRect = QRect(0, 0, 50, 20);
    QRect endTimeRect = QRect(240, 0, 50, 20);
    m_SliderRect = QRect(50, 8, 190, 4);

    painter.setPen(QPen(QColor(100, 100, 100, 100)));
    painter.fillRect(m_SliderRect, QBrush(QColor(50, 50, 50, 180)));

    painter.setPen(QPen(QColor(250, 250, 250, 200)));
    painter.fillRect(m_SliderRect.adjusted(0, 0, m_Position / (float) m_Duration * 190 - 190, 0), QBrush(QColor(255, 255, 255, 200)));
    painter.drawRect(m_SliderRect);

    painter.setPen(QPen(QColor(0, 0, 0, 200)));
    painter.setFont(QFont("", 11, QFont::Bold));


    painter.drawText(startTimeRect, Qt::AlignCenter, QTime(0, 0, 0).addMSecs(m_Position).toString("mm:ss"));
    painter.drawText(endTimeRect, Qt::AlignCenter, QTime(0, 0, 0).addMSecs(m_Duration).toString("mm:ss"));

}

void SeekSlider::SetDuration(qint64 duration)
{
    m_Duration = duration > 0 ? duration : 1;

    update();
}

void SeekSlider::SetPosition(qint64 position)
{
    m_Position = position;

    update();
}
#include<QDebug>
void SeekSlider::mousePressEvent(QMouseEvent *e)
{
    if(m_SliderRect.contains(e->pos()))
    {
        m_Position = e->pos().x() - m_SliderRect.x();

//        qDebug()<<m_Position<<e->pos()<<m_SliderRect;
//        update();
        emit SeekPostion(m_Position / (float) 190 * m_Duration);
    }

    QWidget::mousePressEvent(e);
}

