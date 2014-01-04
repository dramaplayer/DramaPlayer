#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H


#include <QWidget>

class TabButton;
class StackWidget;

class PageWidget : public QWidget
{
    Q_OBJECT
public:
    PageWidget(QWidget *pParent = NULL);

private slots:

    void TabButtonClicked();

signals:
    void FileClicked(const QString &);
private:
    TabButton *m_DramaTab;
    TabButton *m_InfoTab;
    TabButton *m_ChatTab;

    StackWidget *m_StackWidget;
};

#endif // PAGEWIDGET_H
