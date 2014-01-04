#ifndef STACKWIDGET_H
#define STACKWIDGET_H


#include <QWidget>

class DramaTree;

class StackWidget : public QWidget
{
    Q_OBJECT
public:
    StackWidget(QWidget *pParent = NULL);

protected:
    virtual void paintEvent(QPaintEvent *);

signals:
    void FileClicked(const QString &);
private:
    DramaTree *m_DramaTree;
};

#endif // STACKWIDGET_H
