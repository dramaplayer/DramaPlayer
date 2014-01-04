#include "MediaListCtrl.h"

#include <QtSql/QSqlQuery>
#include <QFileInfo>
#include <QVariant>
#include <QDir>
#include <QDebug>

MediaListCtrl* MediaListCtrl::m_pMediaLstCtrl = NULL;
QSqlDatabase MediaListCtrl::m_Db = QSqlDatabase::addDatabase("QSQLITE");


MediaListCtrl::MediaListCtrl()
{

}


MediaListCtrl::~MediaListCtrl()
{

}

MediaListCtrl *MediaListCtrl::GetInstance()
{
    if(m_pMediaLstCtrl == NULL)
    {
        m_pMediaLstCtrl = new MediaListCtrl;

        QString mediaListDir = QDir::currentPath() + "/MediaList/";
        QString mediaListFile = "MediaList.lst";
qDebug() << mediaListDir <<"::" << mediaListFile;
        QDir mediaDir(mediaListDir);
        QFileInfo listFile(mediaListDir + mediaListFile);

        if(!mediaDir.exists())
        {
            mediaDir.mkdir(mediaListDir);
        }

        m_Db.setDatabaseName(mediaListDir + mediaListFile);
        InitMediaList();
    }
    return m_pMediaLstCtrl;
}

bool MediaListCtrl::InitMediaList()
{
    if(m_Db.open())
    {
        QSqlQuery query;
        query.exec("select count(*) from sqlite_master where type = 'table'select count(*) from sqlite_master where type = 'table' and name = 'drama_list'");

        if(query.next())
        {
            int cn = query.value(0).toInt();
            if(cn == 0)
            {
                query.exec("create table drama_list(id varchar primary key, db_id varchar, name varchar)");
                query.exec("create table drama_source(id varchar primary key, db_id varchar, list_id varchar, name varchar, path varchar)");
                query.exec("create table music_list(id varchar primary key, db_id varchar, name varchar)");
                query.exec("create table music_source(id varchar primary key, db_id varchar, list_id varchar, name varchar, path varchar)");
            }
        }

        m_Db.close();

        return true;
    }

    return false;
}
