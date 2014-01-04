#include "DramaTree.h"
//#include "MusicListCtrl.h"
//#include "DramaListCtrl.h"

#include "MediaListCtrl.h"

#include <QTreeWidgetItem>
#include <QHeaderView>
#include <QIcon>
#include <QMenu>
#include <QContextMenuEvent>
#include <QAction>
#include <QFileDialog>
#include <QFileInfo>

#include <QDebug>

DramaTree::DramaTree(QWidget *pParent)
    :QTreeWidget(pParent)
{
    m_MediaLstCtrl = MediaListCtrl::GetInstance();

    setColumnCount(1);
    setStyleSheet("background: transparent; border-top: 0px; margin-top: 10px");

    m_AddAction = new QAction(tr("添加"), this);
    m_DelAction = new QAction(tr("删除"), this);
    m_RenameAction = new QAction(tr("重命名"), this);
    m_NewDrama = new QAction(tr("新建广播剧列表"), this);

    connect(m_AddAction, SIGNAL(triggered()), this, SLOT(Add()));
    connect(m_DelAction, SIGNAL(triggered()), this, SLOT(Delete()));
    connect(m_RenameAction, SIGNAL(triggered()), this, SLOT(Rename()));
    connect(this, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(ItemChanged(QTreeWidgetItem*,int)));

    m_ListMenu.addAction(m_AddAction);
    m_ListMenu.addAction(m_DelAction);
    m_ListMenu.addAction(m_RenameAction);
    m_FileMenu.addAction(m_DelAction);
    m_FileMenu.addAction(m_RenameAction);

    m_DramaList = new QAction(tr("New drama list"), this);
    connect(m_DramaList, SIGNAL(triggered()), this, SLOT(NewDramaList()));
    m_DramaTreeMenu.addAction(m_DramaList);


    m_DramaTitleMenu.addAction(m_DelAction);
    m_DramaTitleMenu.addAction(m_RenameAction);



    setContextMenuPolicy(Qt::CustomContextMenu);
    setEditTriggers(QAbstractItemView::AllEditTriggers);
    header()->hide();

    ReadMusiList();
    ReadDramaList();

    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ShowMenu(QPoint)));
    connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(ItemClicked(QTreeWidgetItem*,int)));
}

void DramaTree::ReadMusiList()
{/*
    clear();
    QMap<QString, QStringList> map = dMusicListCtrl::GetInstance().GetMusiList();
    //qDebug()<<map;
    QMapIterator<QString, QStringList> i(map);
    while (i.hasNext())
    {
        i.next();

        QString listName = i.key();
        QStringList files = i.value();

        QTreeWidgetItem *pListItem = new QTreeWidgetItem(this, QStringList() << listName);
        pListItem->setData(0, TYPE_ROLE, LIST);

        for(int j = 0; j < files.size(); ++j)
        {
            QTreeWidgetItem *pFileItem = new QTreeWidgetItem(pListItem, QStringList() << QFileInfo(files.at(j)).baseName());
            pFileItem->setData(0, TYPE_ROLE, FILE);
            pFileItem->setData(0, FILE_PATH, files.at(j));
        }

        insertTopLevelItem(0, pListItem);
    }*/
}

void DramaTree::ReadDramaList()
{
    clear();

    QList<DramaListInfo> dramaLst = m_MediaLstCtrl->GetDramaLists();

    foreach(DramaListInfo dramaInfo, dramaLst)
    {
//        QString listName = dramaInfo.m_Name;

//        QTreeWidgetItem *pLstItem = new QTreeWidgetItem(this, QStringList() << listName <<"T");

        insertTopLevelItem(0, CreateItem(dramaInfo));
    }

    /*
    clear();

    QMap<QString, QStringList> map = dDramaListCtrl::GetInstance().GetDramaList();
    QMapIterator<QString, QStringList> i(map);
    while (i.hasNext())
    {
        i.next();

        QString listName = i.key();
        QStringList files = i.value();

        QTreeWidgetItem *pListItem = new QTreeWidgetItem(this, QStringList() << listName);
        pListItem->setData(0, TYPE_ROLE, LIST);

        for(int j = 0; j < files.size(); ++j)
        {
            QTreeWidgetItem *pFileItem = new QTreeWidgetItem(pListItem, QStringList() << QFileInfo(files.at(j)).baseName());
            pFileItem->setData(0, TYPE_ROLE, FILE);
            pFileItem->setData(0, FILE_PATH, files.at(j));
        }

        insertTopLevelItem(0, pListItem);
    }*/

}

QTreeWidgetItem *DramaTree::CreateItem(const DramaListInfo &dramaLst)
{
    QTreeWidgetItem *pLstItem = new QTreeWidgetItem(this, QStringList() << dramaLst.m_Name);

    pLstItem->setData(0, TYPE_ROLE, QVariant(DRAMA_TITLE));
    pLstItem->setData(0, ID, QVariant(dramaLst.m_Id));

    QTreeWidgetItem *pTrailerItem = new QTreeWidgetItem(pLstItem, QStringList() << tr("Trailer"));
    QTreeWidgetItem *pDramaItem = new QTreeWidgetItem(pLstItem, QStringList() << tr("Drama"));
    QTreeWidgetItem *pFanItem = new QTreeWidgetItem(pLstItem, QStringList() << tr("Fan"));
    QTreeWidgetItem *pFtItem = new QTreeWidgetItem(pLstItem, QStringList() << tr("FT"));
    QTreeWidgetItem *pEdItem = new QTreeWidgetItem(pLstItem, QStringList() << tr("ED"));
    QTreeWidgetItem *pBgmItem = new QTreeWidgetItem(pLstItem, QStringList() << tr("BGM"));


    return pLstItem;
}

void DramaTree::ShowMenu(QPoint pos)
{
    m_pTriggerItem = itemAt(pos);

    if(m_pTriggerItem)
    {
        if(m_pTriggerItem->data(0, TYPE_ROLE).toInt() == LIST)
        {
            m_ListMenu.move(mapToGlobal(pos + QPoint(5, 10)));
            m_ListMenu.exec();
        }
        else if(m_pTriggerItem->data(0, TYPE_ROLE).toInt() == FILE)
        {
            m_FileMenu.move(mapToGlobal(pos + QPoint(5, 10)));
            m_FileMenu.exec();
        }
        else if(m_pTriggerItem->data(0, TYPE_ROLE).toInt() == DRAMA_TITLE)
        {
            m_DramaTitleMenu.move(mapToGlobal(pos + QPoint(5, 10)));
            m_DramaTitleMenu.exec();
        }
    }
    else
    {
        m_DramaTreeMenu.move(mapToGlobal(pos));
        m_DramaTreeMenu.exec();
    }
}

void DramaTree::Add()
{/*
    QFileDialog dlg;

    QStringList list = dlg.getOpenFileNames(this, tr("Choose file"), "", "Audio(*.mp3 *.wma *.ogg)");

    dMusicListCtrl::GetInstance().AddFiles(m_pTriggerItem->text(0), list);
    ReadMusiList();*/
}

void DramaTree::Delete()
{
    //QTreeWidgetItem *pItem = itemAt(mapFromGlobal(QCursor::pos()));

    if(m_pTriggerItem == NULL)
    {
        return;
    }

    if(m_pTriggerItem->data(0, TYPE_ROLE).toInt() == DRAMA_TITLE)
    {
        m_MediaLstCtrl->DeleteDramaList(m_pTriggerItem->data(0, ID).toUuid().toString());
    }


    delete m_pTriggerItem;
}

void DramaTree::Rename()
{
    if(m_pTriggerItem == NULL)
    {
        return;
    }

    m_pTriggerItem->setFlags(m_pTriggerItem->flags() | Qt::ItemIsEditable);
    editItem(m_pTriggerItem, 0);
    m_pTriggerItem->setFlags(m_pTriggerItem->flags() & ~Qt::ItemIsEditable);

    qDebug() << m_pTriggerItem->text(0);
//    if(m_pTriggerItem->data(0, TYPE_ROLE).toInt() == DRAMA_TITLE)
//    {
//        m_MediaLstCtrl->DeleteDramaList(m_pTriggerItem->data(0, ID).toUuid().toString());
//    }
}

void DramaTree::NewDramaList()
{
    DramaListInfo dramaLst;
    dramaLst.m_Id = QUuid::createUuid();
    dramaLst.m_DbId = QUuid("0");
    dramaLst.m_Name = "Untitled";

    m_MediaLstCtrl->InsertDramaList(dramaLst);


    insertTopLevelItem(0, CreateItem(dramaLst));

}

void DramaTree::ItemClicked(QTreeWidgetItem * pItem, int column)
{
    Q_UNUSED(column)

    if(pItem->data(0, TYPE_ROLE).toInt() == FILE)
    {
        emit FileClicked(pItem->data(0, FILE_PATH).toString());
    }
}

void DramaTree::ItemChanged(QTreeWidgetItem *pItem, int column)
{
    Q_UNUSED(column);

    if(pItem->data(0, TYPE_ROLE).toInt() == DRAMA_TITLE)
    {
        QString newName = pItem->text(0);
        QUuid id = pItem->data(0, ID).toUuid();

        m_MediaLstCtrl->UpdateDramaListName(id, newName);

    }
}

