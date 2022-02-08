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
    _qWidth=15;
    _qSpace=5;
}

void graphWindow::paintEvent(QPaintEvent *event)
{
//    graphsVect.push_back(QRect(-100,0,100,50));
//    graphsVect.push_back(QRect(400,124,15,510));

        QPainter painter(this);
        for(int i=0;i<graphsVect.size();i++)
    painter.drawRect(graphsVect[i]);

}

void graphWindow::graphAdding()
{
   int height=QWidget::height();
   GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
   int graphHeight=(manager->getGraphHeight()).toInt();

            if(graphHeight<1)return;

   qDebug()<<graphHeight;
   int numOfGraphs= graphsVect.size();
   graphsVect.push_back(QRect(_qSpace*numOfGraphs+_qWidth*numOfGraphs,height-1,_qWidth,-graphHeight));
   update();

   manager->clearGraphHeight();

}
