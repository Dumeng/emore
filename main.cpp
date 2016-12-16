#include "mainwindow.h"
#include "AffdexThread.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	affdexThread affdex;

    return a.exec();
}
