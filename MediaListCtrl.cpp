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

QList<DramaListInfo> MediaListCtrl::GetDramaLists()
{
    QList<DramaListInfo> dramaLsts;

    if(m_Db.open())
    {
        QSqlQuery query;
        QString sql = QString("select * from drama_list");
        query.exec(sql);
        while(query.next())
        {
            DramaListInfo lst;
            lst.m_Id = query.value("id").toString();
            lst.m_DbId = query.value("db_id").toString();
            lst.m_Name = query.value("name").toString();
            dramaLsts << lst;
        }

        m_Db.close();
    }

    return dramaLsts;
}

QList<MusicListInfo> MediaListCtrl::GetMusicLists()
{
    QList<MusicListInfo> musicLst;

    if(m_Db.open())
    {


        m_Db.close();
    }

    return musicLst;
}

bool MediaListCtrl::InsertDramaList(const DramaListInfo &dramaList)
{
    if(m_Db.open())
    {
        QSqlQuery query;
        QString sql = QString("insert into drama_list values('%1', '%2', '%3')")
                .arg(dramaList.m_Id.toString())
                .arg(dramaList.m_DbId.toString())
                .arg(dramaList.m_Name);
        query.exec(sql);
qDebug()<<"Insert dramaList";
        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::InsertMusicList(const MusicListInfo &musicList)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::InsertDramaSource(const DramaSourceInfo &dramaSource)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::InsertMusicSource(const MusicSourceInfo &musicSource)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::DeleteDramaList(const QUuid &id)
{
    if(m_Db.open())
    {
        QSqlQuery query;
        QString sql = QString("delete from drama_list where id = '%1'").arg(id.toString());
        query.exec(sql);
qDebug()<<sql;
        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::DeleteMusicList(const QUuid &id)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::DeleteDramaSource(const QUuid &id)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::DeleteMusicSource(const QUuid &id)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::UpdateDramaList(const QUuid &id, const DramaListInfo &dramaList)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::UpdateMusicList(const QUuid &id, const MusicListInfo &musicList)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::UpdateDramaSource(const QUuid &id, const DramaSourceInfo &dramaSource)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::UpdateMusicSource(const QUuid &id, const MusicSourceInfo &musicSource)
{
    if(m_Db.open())
    {


        m_Db.close();
        return true;
    }

    return false;
}

bool MediaListCtrl::UpdateDramaListName(const QUuid &id, const QString &newName)
{
    if(m_Db.open())
    {
        QSqlQuery query;
        QString sql = QString("update drama_list set name = '%1' where id = '%2'")
                .arg(newName)
                .arg(id.toString());
        query.exec(sql);

        m_Db.close();
        return true;
    }

    return false;
}
