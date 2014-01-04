#include "Button.h"

#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

#include <QLinearGradient>

Button::Button(QWidget *parent)
    :QWidget(parent),
      m_IsCheckable(false),
      m_IsChecked(false),
      m_State(NORMAL)
{
    setMouseTracking(true);

    connect(this, SIGNAL(Clicked()), this, SLOT(ButtonClicked()));
}

void Button::SetCheckable(bool checkable)
{
    m_IsCheckable = checkable;

}

void Button::SetChecked(bool checked)
{
    m_IsChecked = checked;

    if(m_IsCheckable)
    {
        if(checked)
        {
            m_State = CHECKED;
        }
        else
        {
            if(rect().contains(mapFromGlobal(QCursor::pos())))
            {
                m_State = HOVERING;
            }
            else
            {
                m_State = NORMAL;
            }
        }
    }
    else
    {
        if(rect().contains(mapFromGlobal(QCursor::pos())))
        {
            m_State = HOVERING;
        }
        else
        {
            m_State = NORMAL;
        }
    }
    repaint();
}

void Button::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);


    QLinearGradient linearGradient(rect().topLeft(), rect().bottomLeft());


    switch(m_State)
    {
    case NORMAL:
        break;
    case HOVERING:
        linearGradient.setColorAt(0, QColor(0, 200, 0, 10));
        linearGradient.setColorAt(1.0, QColor(0, 200, 0, 120));
        painter.fillRect(rect(), QBrush(linearGradient));
        break;
    case CHECKED:
    case PRESSING:
        linearGradient.setColorAt(0, QColor(10, 200, 10, 10));
        linearGradient.setColorAt(1.0, QColor(10, 200, 10, 120));
        painter.fillRect(rect(), QBrush(linearGradient));
        break;
    }

    painter.drawPixmap(rect(), m_SrcPixmap);
}

void Button::enterEvent(QEvent *e)
{
    if(!m_IsCheckable)
    {
        m_State = HOVERING;
    }
    else if(!m_IsChecked)
    {
        m_State = HOVERING;
    }

    repaint();
    QWidget::enterEvent(e);
}

void Button::leaveEvent(QEvent *e)
{
    if(!m_IsCheckable)
    {
        m_State = NORMAL;
    }
    else if(!m_IsChecked)
    {
        m_State = NORMAL;
    }
    repaint();
    QWidget::leaveEvent(e);
}

void Button::mousePressEvent(QMouseEvent *e)
{
    //emit clicked();

//    if(m_IsCheckable)
//    {
//        SetChecked(!m_IsChecked);
//    }
//    else
    {
        m_State = PRESSING;
    }
    repaint();
    QWidget::mousePressEvent(e);

    e->accept();
}

void Button::mouseReleaseEvent(QMouseEvent *e)
{
    if(rect().contains(e->pos()))
    {
        if(!m_IsCheckable)
        {
            m_State = HOVERING;
        }

        emit Clicked();
    }

    repaint();
    QWidget::mouseReleaseEvent(e);
}

void Button::ButtonClicked()
{
    if(m_IsCheckable)
    {
        SetChecked(!m_IsChecked);
    }
}

