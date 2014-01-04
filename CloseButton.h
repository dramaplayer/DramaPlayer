#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include "Button.h"

class CloseButton : public Button
{
    Q_OBJECT
public:
    CloseButton(QWidget *pParent = NULL);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QLinearGradient m_SepLineGradient;
};

#endif // CLOSEBUTTON_H
