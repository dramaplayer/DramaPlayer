#ifndef MEDIABAISCINFO_H
#define MEDIABAISCINFO_H

#include <QUuid>
#include <QString>
#include <QList>

struct DramaSourceInfo
{
    QUuid m_Id;
    QUuid m_DbId;
    QUuid m_ListId;

    QString m_Name;
    QString m_Path;
};

struct DramaListInfo
{
    QUuid m_Id;
    QUuid m_DbId;

    QString m_Name;

    QList<DramaSourceInfo> m_SourceInfoLst;
};

struct MusicSourceInfo
{
    QUuid m_Id;
    QUuid m_DbId;
    QUuid m_ListId;

    QString m_Name;
    QString m_Path;
};

struct MusicListInfo
{
    QUuid m_Id;
    QUuid m_DbId;

    QString m_Name;
    QList<MusicSourceInfo> m_SourceInfoLst;
};

#endif // MEDIABAISCINFO_H
