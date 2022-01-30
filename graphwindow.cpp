#include "graphwindow.h"
#include <QPainter>
#include <QRect>
#include <QLayout>
#include <mainwindow.h>
graphWindow::graphWindow(QWidget *parent): QFrame(parent)
{
    setFrameStyle(Box | Plain);
    //horizontalLayout();
}
void graphWindow::paintEvent(QPaintEvent *event)
{
    graphsVect.push_back(QRect(0,0,100,50));
        QPainter painter(this);
        for(int i=0;i<graphsVect.size();i++)
    painter.drawRect(graphsVect[i]);

}

