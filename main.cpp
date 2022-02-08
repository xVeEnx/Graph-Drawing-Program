#include "mainwindow.h"
#include "graphwindow.h"
#include <QApplication>
#include <QDockWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //graphWindow *pierw=new graphWindow(&w);
    //graphWindow graf=graphWindow(&w);
    w.show();
    //graf.show();
    return a.exec();
}

