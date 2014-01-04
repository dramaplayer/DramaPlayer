#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets/QWidget>

#include <QLinearGradient>

class QPixmap;

class Button : public QWidget
{
    Q_OBJECT
public:
    enum STATE{NORMAL, HOVERING, PRESSING, CHECKED};

    Button(QWidget *parent = 0);

    void SetCheckable(bool checkable);

    void SetChecked(bool checked);
protected:

    virtual void paintEvent(QPaintEvent *);

    virtual void enterEvent(QEvent *);

    virtual void leaveEvent(QEvent *);

    virtual void mousePressEvent(QMouseEvent *);

    virtual void mouseReleaseEvent(QMouseEvent *);
protected slots:
    virtual void ButtonClicked();
signals:
    void Clicked();


protected:


    bool m_IsCheckable;
    bool m_IsChecked;
    STATE m_State;
    QPixmap m_SrcPixmap;

    QLinearGradient m_HoveringGradient;
    QLinearGradient m_PressingGradient;
    QLinearGradient m_CheckedGradient;
};

#endif // BUTTON_H
