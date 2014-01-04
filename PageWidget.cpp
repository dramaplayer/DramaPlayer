#include "PageWidget.h"
#include "TabButton.h"

#include "StackWidget.h"

#include <QVBoxLayout>

PageWidget::PageWidget(QWidget *pParent)
    :QWidget(pParent)
{
    m_DramaTab = new TabButton(tr("广播剧"), this);
    m_InfoTab = new TabButton(tr("信息"), this);
    m_ChatTab = new TabButton(tr("网聊"), this);

    m_StackWidget = new StackWidget(this);

    m_DramaTab->SetChecked(true);

    m_DramaTab->move(0, 0);
    m_InfoTab->move(96, 0);
    m_ChatTab->move(192, 0);
    m_StackWidget->move(0, 25);

    connect(m_DramaTab, SIGNAL(Clicked()), this, SLOT(TabButtonClicked()));
    connect(m_InfoTab, SIGNAL(Clicked()), this, SLOT(TabButtonClicked()));
    connect(m_ChatTab, SIGNAL(Clicked()), this, SLOT(TabButtonClicked()));
    connect(m_StackWidget, SIGNAL(FileClicked(QString)), this, SIGNAL(FileClicked(QString)));
}

void PageWidget::TabButtonClicked()
{
    if(m_DramaTab == sender())
    {
        m_DramaTab->SetChecked(true);
        m_InfoTab->SetChecked(false);
        m_ChatTab->SetChecked(false);
    }
    else if(m_InfoTab == sender())
    {
        m_DramaTab->SetChecked(false);
        m_InfoTab->SetChecked(true);
        m_ChatTab->SetChecked(false);
    }
    else if(m_ChatTab == sender())
    {
        m_DramaTab->SetChecked(false);
        m_InfoTab->SetChecked(false);
        m_ChatTab->SetChecked(true);
    }
}

