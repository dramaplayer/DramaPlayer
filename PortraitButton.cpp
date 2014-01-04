#include "PortraitButton.h"

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
PortraitButton::PortraitButton(QWidget *pParent)
    :Button(pParent)
{
    m_SrcPixmap = QPixmap(":/image/portrait.jpg");
    setFixedSize(QSize(70, 70));
}

void PortraitButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor("#DDDDDD")));

    switch(m_State)
    {
    case NORMAL:
        painter.drawPixmap(rect(), m_SrcPixmap);
        break;
    case HOVERING:
        painter.drawPixmap(rect().adjusted(0, -1, 0, -1), m_SrcPixmap);
        break;
    case PRESSING:
        painter.drawPixmap(rect().adjusted(0, 1, 0, 1), m_SrcPixmap);
        break;
    }

    QPen pen = painter.pen();
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}


