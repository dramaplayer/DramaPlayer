#include <QLabel>
#include <QApplication>

#include "MediaListCtrl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lable("Hello World!\ndfdf\n\n");
    lable.show();

    MediaListCtrl *ctrl = MediaListCtrl::GetInstance();


    return a.exec();
}
