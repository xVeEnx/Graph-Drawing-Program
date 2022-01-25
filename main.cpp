#include "mainwindow.h"
#include "graphwindow.h"
#include <QApplication>
#include <QDockWidget>
#include <QPainter>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    graphWindow *pierw=new graphWindow();
    QRect cos=pierw->q1;
    QPainter p;



    QDockWidget *dWidget=new QDockWidget("Graph creating",&w);
    p.begin(dWidget);
    p.drawRect(cos);

       w.addDockWidget(Qt::LeftDockWidgetArea,dWidget);

    w.show();
    return a.exec();
}

