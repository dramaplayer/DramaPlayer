#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lable("Hello World!");
    lable.show();

    return a.exec();
}
