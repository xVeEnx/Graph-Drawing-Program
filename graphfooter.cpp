#include "graphfooter.h"
#include <QPushButton>
GraphFooter::GraphFooter(QWidget *parent,QSize size)
    : QWidget{parent}
{
    setFixedSize(size);

}
void GraphFooter::paintEvent(QPaintEvent *event)
{
     QPainter painter(this);
     painter.setPen(Qt::gray);
            for(int i=0; i<_qName.size(); i++)
            {
                _qName[i].setTextWidth(10);
                //QPainter::setClipRect(QRect(0,0,10,100),Qt::NoClip); cos z tym sprawdzic
                qDebug()<<_qName[i].size()<<"width";
                painter.drawStaticText(_qRect[i].bottomLeft().x(),10,_qName[i]);
            }
}
void GraphFooter::setRects()
{
    QPointer<graphSpace> manager=qobject_cast<graphSpace*>(sender());
    _qRect=manager->getQRectVect();
    _qName=manager->getQName();
    update();
}
