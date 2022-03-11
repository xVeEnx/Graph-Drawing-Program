#include "graphfooter.h"
#include <QPushButton>
#include <QFontMetrics>
GraphFooter::GraphFooter(QWidget *parent,QSize size)
    : QWidget{parent}
{
    setFixedSize(size);

}
void GraphFooter::paintEvent(QPaintEvent *event)
{
    QTransform t;
    t.rotate(90);
   // if(_qRect.size()==1)t.translate(0,);
     QPainter painter(this);
     painter.setPen(Qt::gray);
            for(int i=0; i<_gRect.size(); i++)
            {
                t.translate(0,-_gRect[i].width()-_iSpaceBetweenRects);
                painter.setTransform(t);
                painter.drawStaticText(0,_iSpaceBetweenRects+_gRect[i].width()/2-_qName[i].size().height()/2,_qName[i]);
            }

}
void GraphFooter::setRects()
{
    QPointer<graphSpace> manager=qobject_cast<graphSpace*>(sender());
    _gRect=manager->getGRectVect();
    if(_qName.size()<_gRect.size())_qName.push_back(_gRect[_gRect.size()-1].getQText());

    else for(int i=0;i<_gRect.size();i++)_qName[i]=_gRect[i].getQText();

    _iSpaceBetweenRects=manager->getSpace();
    qDebug()<<"rozmiar"<<_qName.size();
    update();
}
