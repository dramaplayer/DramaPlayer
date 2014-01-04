#include "Player.h"

#include <QPainter>
#include <QPen>
#include <QApplication>

Player::Player(QWidget *pParent)
    :QWidget(pParent)
{
    setFixedSize(300, 600);

    setWindowFlags(Qt::FramelessWindowHint);

    Init();
}

void Player::Init()
{
    m_BackgroundImage = QPixmap(":/image/background.jpg");

    m_pCloseBtn = new CloseButton(this);
    //m_pCloseBtn->setFixedSize(200, 50);
    m_pCloseBtn->move(265, 0);
    connect(m_pCloseBtn, SIGNAL(Clicked()), qApp, SLOT(quit()));

    m_pMinimizeBtn = new MinimizeButton(this);
    m_pMinimizeBtn->move(230, 0);
    connect(m_pMinimizeBtn, SIGNAL(Clicked()), this, SLOT(showMinimized()));

    m_pPortraitBtn = new PortraitButton(this);
    m_pPortraitBtn->move(5, 30);

    m_pPreBtn = new PreviouseButton(this);
    m_pPreBtn->move(75, 75);

    m_pPlayOrPauseBtn = new PlayOrPauseButton(this);
    m_pPlayOrPauseBtn->move(110, 75);

    m_pNextBtn = new NextButton(this);
    m_pNextBtn->move(145, 75);

    m_pSeekSlider = new SeekSlider(this);
    m_pSeekSlider->move(5, 110);

    m_pVolSlider = new VolumeSlider(this);
    m_pVolSlider->move(180, 80);

//    m_VolumeSlider->move(180, 80);
//    m_SeekSlider->move(5, 110);

    m_pPageWgt = new PageWidget(this);
    m_pPageWgt->move(5, 150);
}

void Player::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, m_BackgroundImage);


    QPen pen(QColor(30, 30, 30, 120), 1);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    painter.drawRect(rect().adjusted(0, 0, -1, -1));
}

void Player::mouseMoveEvent(QMouseEvent *e)
{
    QPoint sep = e->globalPos()- m_tPos;

    if(m_isPressing)
    {
        move(this->pos() + sep);
    }
    m_tPos = e->globalPos();

    QWidget::mouseMoveEvent(e);
}

void Player::mousePressEvent(QMouseEvent *e)
{
    m_tPos = e->globalPos();
    m_isPressing = true;

    QWidget::mousePressEvent(e);

}

void Player::mouseReleaseEvent(QMouseEvent *e)
{
    m_isPressing = false;

    QWidget::mouseReleaseEvent(e);
}
