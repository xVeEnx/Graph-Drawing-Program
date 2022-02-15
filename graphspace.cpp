#include "graphspace.h"

graphSpace::graphSpace(QWidget *parent,QSize size)
    : QWidget{parent},_iWidth{10},_iSpace{5},_iScale{1}
{
    setFixedSize(size);
    double height=size.height()/10;

    for(int i=10; i>=0; i--)
    {
        _qLine.push_back(QLine(0,height*i,size.width(),height*i));
    }
}
void graphSpace::addGraphs()
{
    GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
    int graphHeight=(manager->getGraphHeight()).toInt();

    if(graphHeight<1) return;

    _qColor.push_back(manager->getGraphColor());
    _qName.push_back(QStaticText(manager->getGraphName()));
    manager->clearGraphHeight(_qName.size()+1);

    int numOfGraphs= graphsVect.size();
    int height=QWidget::height();
    graphsVect.push_back(QRect(_iSpace*numOfGraphs+_iWidth*numOfGraphs,height,_iWidth,-graphHeight));

    emit layoutSetting();

    update();
}
void graphSpace::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::gray);
    for(int i=0; i<_qLine.size(); i++) painter.drawLine(_qLine[i]);

    painter.setPen(Qt::black);
    for(int i=0; i<graphsVect.size(); i++)painter.fillRect(graphsVect[i],_qColor[i]);

    for(int i=0; i<graphsVect.size(); i++) painter.drawRect(graphsVect[i]);

}
QVector<QRect> graphSpace::getQRectVect()
{
    return graphsVect;
}
QVector<QStaticText> graphSpace::getQName()
{
    return _qName;
}
