#include "graphspace.h"

graphSpace::graphSpace(QWidget *parent)
    : QWidget{parent},_iWidth{15},_iSpace{5},_iScale{1}
{
    double height=50*_iScale;

    for(int i=10; i>=0; i--)
    {
        _qLinia.push_back(QLine(0,height*i,1001,height*i));
    }
}
void graphSpace::addGraphs()
{
    int height=QWidget::height();
    GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
    int graphHeight=(manager->getGraphHeight()).toInt();

    if(graphHeight<1) return;
    _qColor.push_back(manager->getGraphColor());

    manager->clearGraphHeight();

    int numOfGraphs= graphsVect.size();

    graphsVect.push_back(QRect(_iSpace*numOfGraphs+_iWidth*numOfGraphs,height,_iWidth,-graphHeight));
    //graphsVect[1].
    update();
}
void graphSpace::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
   // painter.setBrush(Qt::yellow);
    for(int i=0; i<graphsVect.size(); i++)
    {
         //painter.setBrush(QColor::fromRgbF(i*20,1,115));
        painter.fillRect(graphsVect[i],_qColor[i]);
    }
    for(int i=0; i<graphsVect.size(); i++) painter.drawRect(graphsVect[i]);

    for(int i=0; i<_qLinia.size(); i++) painter.drawLine(_qLinia[i]);
}
