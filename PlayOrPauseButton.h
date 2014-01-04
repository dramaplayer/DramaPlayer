#ifndef PLAYORPAUSEBUTTON_H
#define PLAYORPAUSEBUTTON_H


#include "Button.h"


class PlayOrPauseButton : public Button
{
    Q_OBJECT
public:

    PlayOrPauseButton(QWidget *pParent = NULL);

    void SetPlayingState(bool isOnPlayingState);

protected:

    virtual void paintEvent(QPaintEvent *);

private:
    QPixmap m_PlayPixmap;
    QPixmap m_PausePixmap;

    bool m_IsOnPlayingState;
};


#endif // PLAYORPAUSEBUTTON_H
