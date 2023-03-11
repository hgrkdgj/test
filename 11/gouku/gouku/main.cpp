#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("酷狗");
    w.setFixedSize(1080,760);
    //w.show();

    return a.exec();
}
