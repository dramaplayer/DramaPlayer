#ifndef TABBUTTON_H
#define TABBUTTON_H

#include "Button.h"

class TabButton : public Button
{
    Q_OBJECT

public:
    TabButton(const QString &text, QWidget *pParent = NULL);

protected:

    virtual void paintEvent(QPaintEvent *);

protected slots:
    virtual void ButtonClicked();
private:
    QString m_Text;
};


#endif // TABBUTTON_H
