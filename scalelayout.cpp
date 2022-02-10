#include "scalelayout.h"
#include <qDebug>
scaleLayout::scaleLayout(QWidget *parent,int qScale)
    : QWidget{parent}
{
    qDebug()<<this->height()<<"height ins scaleLayout";

    setContentsMargins(0,0,0,0);
    _iScale=qScale;
    _iScale=this->height()/10;
    qDebug()<<this->height();
    for(int i=10; i>=0; i--)
    {
        double iscl=_iScale*i;
    QString str=QString::number(iscl);
   _qText.push_back(QStaticText(str));
    }
}

void scaleLayout::paintEvent(QPaintEvent *event)
{
    double height=55;
    QPainter painter(this);
    int tWidth=_qText[0].textWidth();
    qDebug()<<tWidth;
    qDebug()<<this->width()<<"<- this->width";
    painter.drawLine(QLine(0,0,100,0));
    for(int i=0; i<_qText.size(); i++) painter.drawStaticText(this->width()-25,height*i+1,_qText[i]);
}
