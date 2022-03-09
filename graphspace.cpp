#include "graphspace.h"
//#include <iostream>

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
        if(graphsVect[graphsVect.size()-1].x()+_iWidth>this->width()) validateSize();
    }
    for(int i=0; i<_qLine.size(); i++) painter.drawLine(_qLine[i]);

    painter.setPen(Qt::black);
    for(int i=0; i<graphsVect.size(); i++) painter.fillRect(graphsVect[i],_qColor[i]);

    for(int i=0; i<graphsVect.size(); i++) painter.drawRect(graphsVect[i]);

}

void graphSpace::refreshGraphs(){
    int height=QWidget::height();
    for(int i=0; i<graphsVect.size(); i++)
    {
        int temp=graphsVect[i].height();
        graphsVect[i].setBottomLeft(QPoint(_iSpace*i+_iWidth*i,height));
        graphsVect[i].setWidth(_iWidth);
        graphsVect[i].setHeight(temp);
    }
    emit layoutSetting();
    update();
}
void graphSpace::validateSize(){
    int i=0;
    qDebug()<<"iSpace=> "<<_iSpace<<"iwidth"<<_iWidth<<"gr size"<<graphsVect.size();
    if(_iSpace>5) _iSpace/=1.5;
    qDebug()<<"iwidth*gr= "<<_iWidth*graphsVect.size()+_iWidth<<"\nSize width=> "<<size().width();
    qDebug()<<"iwidth*size= "<<_iWidth*graphsVect.size()+_iSpace*graphsVect.size();

    while((_iWidth*(graphsVect.size()+1)+_iSpace*(graphsVect.size()+1))>=size().width()) {
        i++;
        _iWidth=_iWidth/2;
        refreshGraphs();
    }
}
void graphSpace::swapRect(QVector<QRect>& qVec, int i,int j)
{
    if(i==j) return;
    QRect qR=qVec[i];
    qVec[i]=qVec[j];
    qVec[j]=qR;
}
int graphSpace::Partition(QVector<QRect> &v, int start, int end){

    int pivot = end;
    int j = start;
    for(int i=start;i<end;++i){
        if(v[i].height()<v[pivot].height()){
            swapRect(v,i,j);
            ++j;
        }
    }
    swapRect(v,j,pivot);
    return j;
}
void graphSpace::sort(QVector<QRect>& vect,int left, int right)
{
    if(left<right){
            int p = Partition(vect,left,right);
            sort(vect,left,p-1);
            sort(vect,p+1,right);
        }
    emit graphSorted(graphsVect);
}
void graphSpace::sortFunc()
{
    sort(graphsVect,0,graphsVect.size()-1);
    update();
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
