#ifndef MINIMIZEBUTTON_H
#define MINIMIZEBUTTON_H

#include "Button.h"

class MinimizeButton : public Button
{
    Q_OBJECT
public:
    MinimizeButton(QWidget *pParent = NULL);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QLinearGradient m_SepLineGradient;
};


#endif // MINIMIZEBUTTON_H
