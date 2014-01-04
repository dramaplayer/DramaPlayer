#ifndef PORTRAITBUTTON_H
#define PORTRAITBUTTON_H

#include "Button.h"

class PortraitButton : public Button
{
    Q_OBJECT
public:
    PortraitButton(QWidget *pParent = NULL);

protected:
    virtual void paintEvent(QPaintEvent *);

};


#endif // PORTRAITBUTTON_H
