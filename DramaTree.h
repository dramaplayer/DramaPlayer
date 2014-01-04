#ifndef DRAMATREE_H
#define DRAMATREE_H


#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPoint>
#include <QMenu>

#include "MediaBaiscInfo.h"

class QAction;
class QTreeWidgetItem;
class MediaListCtrl;

class DramaTree : public QTreeWidget
{
public:
    enum ROLE
    {
        TYPE_ROLE = 1024,
        FILE_PATH,
        ID
    };
    enum TYPE
    {
        LIST = 2048,
        FILE,
        DRAMA_TITLE,
        TRAILER_MASTER,
        TRAILER,
        DRAMA_MASTER,
        DRAMA,
        FAN_MASTER,
        FAN,
        FT_MASTER,
        FT,
        ED_MASTER,
        ED
    };

    Q_OBJECT
public:
    DramaTree(QWidget *pParent = NULL);

private:
    void ReadMusiList();

    void ReadDramaList();

    QTreeWidgetItem *CreateItem(const DramaListInfo &dramaLst);
protected slots:
    virtual void ShowMenu(QPoint pos);

    void Add();

    void Delete();

    void Rename();

    void NewDramaList();

private slots:

    void ItemClicked(QTreeWidgetItem * pItem, int column);

    void ItemChanged(QTreeWidgetItem *pItem, int column);
signals:
    void FileClicked(const QString &path);
private:
    QMenu m_ListMenu;
    QMenu m_FileMenu;
    QMenu m_DramaMenu;

    QMenu m_DramaTreeMenu;

    QMenu m_DramaTitleMenu;

    QAction *m_DelAction;
    QAction *m_AddAction;
    QAction *m_RenameAction;

    QAction *m_NewDrama;

    QAction *m_DramaList;

    QTreeWidgetItem *m_pTriggerItem;

    MediaListCtrl *m_MediaLstCtrl;
};


#endif // DRAMATREE_H
