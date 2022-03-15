#include "mainwindow.h"
#include "graphwindow.h"
#include <QApplication>
#include <QDockWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

