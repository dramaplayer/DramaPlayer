#ifndef MEDIALISTCTRL_H
#define MEDIALISTCTRL_H

#include "MediaBaiscInfo.h"

#include <QtSql/QSqlDatabase>


class MediaListCtrl
{
private:
    MediaListCtrl();
    ~MediaListCtrl();

public:
    static MediaListCtrl* GetInstance();

public:
    static bool InitMediaList();

    QList<DramaListInfo> GetDramaList();

    QList<MusicListInfo> GetMusicList();

    bool InsertDramaList(const DramaListInfo &dramaList);

    bool InsertMusicList(const MusicListInfo &musicList);

    bool InsertDramaSource(const DramaSourceInfo &dramaSource);

    bool InsertMusicSource(const MusicSourceInfo &musicSource);

    bool DeleteDramaList(const QUuid &id);

    bool DeleteMusicList(const QUuid &id);

    bool DeleteDramaSource(const QUuid &id);

    bool DeleteMusicSource(const QUuid &id);

    bool UpdateDramaList(const QUuid &id, const DramaListInfo &dramaList);

    bool UpdateMusicList(const QUuid &id, const MusicListInfo &musicList);

    bool UpdateDramaSource(const QUuid &id, const DramaSourceInfo &dramaSource);

    bool UpdateMusicSource(const QUuid &id, const MusicSourceInfo &musicSource);
private:
    static MediaListCtrl* m_pMediaLstCtrl;
    static QSqlDatabase m_Db;
};

#endif // MEDIALISTCTRL_H
