#include <QLabel>
#include <QApplication>

#include "MediaListCtrl.h"
#include "DramaPlayer.h"
#include "Player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lable("Hello World!\ndfdf\n\n");
    lable.show();

    MediaListCtrl *ctrl = MediaListCtrl::GetInstance();

    DramaPlayer dp;
    dp.show();

//    Player player;
//    player.show();


    return a.exec();
}
