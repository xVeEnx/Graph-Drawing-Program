#include "graphspace.h"

graphSpace::graphSpace(QWidget *parent,QSize size)
    : QWidget{parent},_iWidth{300},_iSpace{40},_iScale{1}
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
    if(graphsVect.size()!=0)
    {
        if(graphsVect[graphsVect.size()-1].x()+_iWidth>this->width())validateSize();
    }
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
int graphSpace::getSpace()
{
    return _iSpace;
}
void graphSpace::refreshGraphs(){
    int numOfGraphs= graphsVect.size();
    int height=QWidget::height();
    for(int i=0;i<graphsVect.size();i++)
    {
        int temp=-graphsVect[i].height();
        graphsVect[i].setBottomLeft(QPoint(_iSpace*i+_iWidth*i,height));
        graphsVect[i].setWidth(_iWidth);
        graphsVect[i].setHeight(temp);
        _qLine.push_back(QLine(_iSpace*i+_iWidth*i,height-50,0,0));
        qDebug()<<graphsVect[i].x()<<"<---Vect nr. "<<i;
        qDebug()<<graphsVect[i].width()<<"<--- Vect width nr. "<<i;
        qDebug()<<graphsVect[i].height()<<"<--- Vect height nr. "<<i;
        qDebug()<<height<<"<---  height ";
        //,height,_iWidth,-graphHeight
    }
    emit layoutSetting();
    update();
}
void graphSpace::validateSize(){
    int i=0;
    if(_iSpace>5) _iSpace/=1.5;
    while((_iWidth*graphsVect.size()+_iWidth)>size().width()){
        i++;
        qDebug()<<"Imin"<<i;
        _iWidth=_iWidth/2;
        refreshGraphs();
    }
    qDebug()<<"Imout";
}
