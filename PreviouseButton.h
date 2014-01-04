#ifndef PREVIOUSEBUTTON_H
#define PREVIOUSEBUTTON_H

#include "Button.h"

class PreviouseButton : public Button
{
    Q_OBJECT
public:

    PreviouseButton(QWidget *pParent = NULL);

protected:

    virtual void paintEvent(QPaintEvent *);
};

#endif // PREVIOUSEBUTTON_H
