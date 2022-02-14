#include "scalelayout.h"
#include <qDebug>
#include <QPalette>
scaleLayout::scaleLayout(QWidget *parent,int qScale)
    : QWidget{parent}
{
    qDebug()<<this->height()<<"height ins scaleLayout";
    int height=50;
    setContentsMargins(0,0,0,0);
    _iScale=qScale;
    _iScale=1;
    for(int i=10; i>=0; i--)
    {
        double iscl=_iScale*height*i;
    QString str=QString::number(iscl);
   _qText.push_back(QStaticText(str));
    }
    for(int i=10; i>=0; i--)_qLinia.push_back(QLine(0,height*i,1001,height*i));
}

void scaleLayout::paintEvent(QPaintEvent *event)
{
    double height=_iScale*50;
   // qDebug()<<height<<"height";
    QPainter painter(this);
    int tWidth=_qText[0].textWidth();
    qDebug()<<tWidth;
    qDebug()<<this->width()<<"<- this->width";
    painter.drawLine(QLine(0,0,150,0));
   // painter.drawLine(QLine(0,540,100,700));
    for(int i=0; i<_qText.size(); i++) painter.drawStaticText(this->width()-25,height*i+1,_qText[i]);
    for(int i=0; i<_qLinia.size(); i++) painter.drawLine(_qLinia[i]);
}
