#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>

#include "CloseButton.h"
#include "MinimizeButton.h"

#include "PreviouseButton.h"
#include "PlayOrPauseButton.h"
#include "NextButton.h"

#include "PortraitButton.h"

#include "SeekSlider.h"
#include "VolumeSlider.h"

#include "PageWidget.h"

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *pParent = NULL);

    //~Player();
private:
    void Init();
protected:

    virtual void paintEvent(QPaintEvent *);

    virtual void mouseMoveEvent(QMouseEvent *);

    virtual void mousePressEvent(QMouseEvent *);

    virtual void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint m_tPos;
    bool m_isPressing;

    QPixmap m_BackgroundImage;

    CloseButton *m_pCloseBtn;
    MinimizeButton *m_pMinimizeBtn;

    PortraitButton *m_pPortraitBtn;

    PreviouseButton *m_pPreBtn;
    PlayOrPauseButton *m_pPlayOrPauseBtn;
    NextButton *m_pNextBtn;

    SeekSlider *m_pSeekSlider;
    VolumeSlider *m_pVolSlider;

    PageWidget *m_pPageWgt;
};

#endif // PLAYER_H
