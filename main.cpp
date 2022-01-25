#include "mainwindow.h"
#include "windowwithrects.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   // WindowWithRects w1;
   // w1.show();
    return a.exec();
}

