
#include "StackWidget.h"
#include "DramaTree.h"

#include <QStackedLayout>
#include <QPainter>

StackWidget::StackWidget(QWidget *pParent)
    :QWidget(pParent)
{
    setFixedSize(289, 400);

    m_DramaTree = new DramaTree;

    QStackedLayout *pMainLayout = new QStackedLayout(this);
    pMainLayout->addWidget(m_DramaTree);


    connect(m_DramaTree, SIGNAL(FileClicked(QString)), this, SIGNAL(FileClicked(QString)));

}

void StackWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.fillRect(rect(), QBrush(QColor(255, 255, 200, 180)));
    painter.setPen(QPen(QColor("#aaaaaa")));
    painter.drawRect(rect().adjusted(0, -1, -1, -1));

    QWidget::paintEvent(e);
}

