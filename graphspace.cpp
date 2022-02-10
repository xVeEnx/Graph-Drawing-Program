#include "graphspace.h"

graphSpace::graphSpace(QWidget *parent)
    : QWidget{parent}
{
    setContentsMargins(0,0,0,0);
    _iWidth=15;
    _iSpace=5;
    _iScale=100;
    double height=this->height()/10;

    qDebug()<<this->height()<<"height ins graphspace";
    for(int i=10; i>=0; i--)
    {
        _qLinia.push_back(QLine(0,height*i+1,1001,height*i+1));
    }
}
void graphSpace::addGraphs()
{
    int height=QWidget::height();
    GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
    int graphHeight=(manager->getGraphHeight()).toInt();

    if(graphHeight<1) return;

    qDebug()<<graphHeight;

    manager->clearGraphHeight();
    int numOfGraphs= graphsVect.size();
    graphsVect.push_back(QRect(_iSpace*numOfGraphs+_iWidth*numOfGraphs,height-1,_iWidth,-graphHeight));
    update();
}
void graphSpace::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0; i<graphsVect.size(); i++) painter.drawRect(graphsVect[i]);
    for(int i=0; i<_qLinia.size(); i++) painter.drawLine(_qLinia[i]);

}
