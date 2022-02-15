#include "graphfooter.h"
#include <QPushButton>
GraphFooter::GraphFooter(QWidget *parent,QSize size)
    : QWidget{parent}
{
    setMinimumSize(size);

}
void GraphFooter::paintEvent(QPaintEvent *event)
{
     QPainter painter(this);
            for(int i=0; i<_qName.size(); i++)
            {
                _qName[i].setTextWidth(1);
                qDebug()<<"bottomleft"<<_qRect[i].bottomLeft().x();
                painter.drawStaticText(_qRect[i].bottomLeft().x()+12,0,_qName[i]);
            }
}
void GraphFooter::setRects()
{
    QPointer<graphSpace> manager=qobject_cast<graphSpace*>(sender());
    _qRect=manager->getQRectVect();
    _qName=manager->getQName();
}
