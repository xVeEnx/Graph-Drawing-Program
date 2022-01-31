#include "graphwindow.h"
#include <QPainter>
#include <QRect>
#include <QLayout>
#include <mainwindow.h>
#include <QPushButton>

graphWindow::graphWindow(QWidget *parent): QFrame(parent)
{
    setFrameStyle(Box | Plain);

    setFixedSize(1000,620);
}

void graphWindow::paintEvent(QPaintEvent *event)
{
    graphsVect.push_back(QRect(-100,0,100,50));
    graphsVect.push_back(QRect(400,124,15,510));
    graphsVect.push_back(QRect(121,2,231,110));

        QPainter painter(this);
        for(int i=0;i<graphsVect.size();i++)
    painter.drawRect(graphsVect[i]);

}

void graphWindow::graphAdding()
{
   GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
   qDebug()<<manager->getGraphHeight();
}
