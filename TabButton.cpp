#include "TabButton.h"

#include <QPainter>

TabButton::TabButton(const QString &text, QWidget *pParent)
    :Button(pParent),
      m_Text(text)
{
    SetCheckable(true);

    setFixedSize(97, 25);

    //
    m_HoveringGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_HoveringGradient.setColorAt(1.0, QColor(0, 200, 0, 10));
    m_HoveringGradient.setColorAt(0, QColor(0, 200, 0, 120));
    //
    m_PressingGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_PressingGradient.setColorAt(1.0, QColor(10, 200, 10, 10));
    m_PressingGradient.setColorAt(0, QColor(10, 200, 10, 120));

    //
    m_CheckedGradient = QLinearGradient(rect().topLeft(), rect().bottomLeft());
    m_CheckedGradient.setColorAt(1.0, QColor(200, 10, 10, 10));
    m_CheckedGradient.setColorAt(0, QColor(200, 10, 10, 120));


}

void TabButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    //QLinearGradient linearGradient(rect().topLeft(), rect().bottomLeft());

    painter.setPen(Qt::NoPen);
    painter.fillRect(rect(), QBrush(QColor(255, 255, 255, 150)));

    painter.setPen(QPen(QColor("#aaaaaa")));

    switch(m_State)
    {
    case NORMAL:
        painter.drawRect(rect().adjusted(0, 0, -1, -1));
        break;
    case HOVERING:
        //linearGradient.setColorAt(0, QColor(0, 200, 0, 10));
        //linearGradient.setColorAt(1.0, QColor(0, 200, 0, 120));
        painter.fillRect(rect(), QBrush(m_HoveringGradient));
        painter.drawRect(rect().adjusted(0, 0, -1, -1));
        break;
    case CHECKED:
        //linearGradient.setColorAt(0, QColor(200, 10, 10, 10));
        //linearGradient.setColorAt(1.0, QColor(200, 10, 10, 120));
        painter.fillRect(rect(), QBrush(m_CheckedGradient));
        painter.drawRect(rect().adjusted(0, 0, -1, 0));
        break;
    case PRESSING:
        //linearGradient.setColorAt(0, QColor(10, 200, 10, 10));
        //linearGradient.setColorAt(1.0, QColor(10, 200, 10, 120));
        painter.fillRect(rect(), QBrush(m_PressingGradient));
        painter.drawRect(rect().adjusted(0, 0, -1, -1));
        break;
    }

    painter.setPen(QPen(QColor("#000000")));
    painter.setFont(QFont("", 15, QFont::Bold));
    painter.drawText(rect(), Qt::AlignCenter, m_Text);

}

void TabButton::ButtonClicked()
{
    Button::ButtonClicked();
}



