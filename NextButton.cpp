#include "NextButton.h"

#include <QPainter>
#include <QLinearGradient>


NextButton::NextButton(QWidget *pParent)
    :Button(pParent)
{
    m_SrcPixmap = QPixmap(":/image/next.png");
    setFixedSize(m_SrcPixmap.size());

    //
    m_HoveringGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_HoveringGradient.setColorAt(0, QColor(255, 255, 255, 20));
    m_HoveringGradient.setColorAt(1.0, QColor(255, 255, 255, 20));
    //
    m_PressingGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_PressingGradient.setColorAt(0, QColor(255, 0, 0, 10));
    m_PressingGradient.setColorAt(1.0, QColor(255, 0, 0, 10));

}

void NextButton::paintEvent(QPaintEvent *)
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

}


