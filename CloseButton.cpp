#include "CloseButton.h"

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

CloseButton::CloseButton(QWidget *pParent)
    :Button(pParent)
{
    m_SrcPixmap = QPixmap(":/image/close.png");
    setFixedSize(m_SrcPixmap.size());

    //
    m_HoveringGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_HoveringGradient.setColorAt(1.0, QColor(200, 0, 0, 10));
    m_HoveringGradient.setColorAt(0, QColor(200, 0, 0, 120));
    //
    m_PressingGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_PressingGradient.setColorAt(1.0, QColor(200, 10, 10, 10));
    m_PressingGradient.setColorAt(0, QColor(200, 10, 10, 120));
    //
    m_SepLineGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_SepLineGradient.setColorAt(0, QColor(200, 80, 200, 10));
    m_SepLineGradient.setColorAt(0.3, QColor(200, 80, 200, 120));
    m_SepLineGradient.setColorAt(0.7, QColor(200, 80, 200, 120));
    m_SepLineGradient.setColorAt(1.0, QColor(200, 80, 200, 10));


}

void CloseButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    switch(m_State)
    {
    case NORMAL:
        painter.drawPixmap(rect(), m_SrcPixmap);
        break;
    case HOVERING:
        painter.fillRect(rect(), QBrush(m_HoveringGradient));
        painter.drawPixmap(rect().adjusted(0, 1, 0, 1), m_SrcPixmap);
        break;
    case PRESSING:
        painter.fillRect(rect(), QBrush(m_PressingGradient));
        painter.drawPixmap(rect().adjusted(0, 2, 0, 2), m_SrcPixmap);
        break;
    }

    painter.setPen(QPen(QBrush(m_SepLineGradient), 1));
    painter.drawLine(rect().topLeft(), rect().bottomLeft());
}

