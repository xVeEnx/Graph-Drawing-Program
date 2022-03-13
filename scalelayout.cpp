#include "scalelayout.h"
#include <qDebug>
#include <QPalette>
#include <graphmanaging.h>

scaleLayout::scaleLayout(QWidget *parent,QSize size,QSize footerSize)
    : QWidget{parent},_iScale{1}
{
    setFixedSize(size);
    _iHeight=(size.height()-footerSize.height())/10;
    for(int i=10; i>=0; i--)
    {
        _qText.push_back(QStaticText());
    }
    setScale();
    for(int i=10; i>=0; i--) _qLinia.push_back(QLine(0,_iHeight*i,size.width(),_iHeight*i));
    _qLinia.push_back(QLine(0,0,100,0));
}

void scaleLayout::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0; i<_qText.size(); i++) painter.drawStaticText(this->width()-25,_iHeight*i,_qText[i]);
    for(int i=0; i<_qLinia.size(); i++) painter.drawLine(_qLinia[i]);
}
void scaleLayout::setScale()
{
    int k=0;
    for(int i=10; i>=0; i--,k++)
    {
        int iscl=_iHeight/_iScale*k;
        QString str=QString::number(iscl);
        _qText[i].setText(str);
    }
    update();
}
void scaleLayout::scaleChanging()
{
    auto manager = qobject_cast<graphSpace*>(sender());
    _iScale=(manager->getScale());
    setScale();
}

