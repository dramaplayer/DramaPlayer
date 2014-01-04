#ifndef NEXTBUTTON_H
#define NEXTBUTTON_H


#include "Button.h"

class NextButton : public Button
{
    Q_OBJECT
public:

    NextButton(QWidget *pParent = NULL);

protected:

    virtual void paintEvent(QPaintEvent *);
};

#endif // NEXTBUTTON_H
