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
            for(int i=0; i<_qName.size(); i++)
            {
                t.translate(0,-_qRect[i].width()-_iSpaceBetweenRects);
                painter.setTransform(t);
                painter.drawStaticText(0,_iSpaceBetweenRects+_qRect[i].width()/2-_qName[i].size().height()/2,_qName[i]);
            }

}
void GraphFooter::setRects()
{
    QPointer<graphSpace> manager=qobject_cast<graphSpace*>(sender());
    _qRect=manager->getQRectVect();
    _qName=manager->getQName();
    _iSpaceBetweenRects=manager->getSpace();
    update();
}
void GraphFooter::sortFooter()
{
}
