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
    QTransform labelTransformation;
    labelTransformation.rotate(90);
     QPainter painter(this);
     painter.setPen(Qt::gray);
            for(int i=0; i<_gGraphs.size(); i++)
            {
                labelTransformation.translate(0,-_gGraphs[i].width()-_iSpaceBetweenRects);
                painter.setTransform(labelTransformation);
                painter.drawStaticText(0,_iSpaceBetweenRects+_gGraphs[i].width()/2-_qGraphLabel[i].size().height()/2,_qGraphLabel[i]);//draw labels at middle of graph
            }

}
void GraphFooter::setRects()
{
    QPointer<graphSpace> manager=qobject_cast<graphSpace*>(sender());
    _gGraphs=manager->getGRectVect();
    if(_qGraphLabel.size()<_gGraphs.size())_qGraphLabel.push_back(_gGraphs[_gGraphs.size()-1].getQText());

    else for(int i=0;i<_gGraphs.size();i++)_qGraphLabel[i]=_gGraphs[i].getQText();

    _iSpaceBetweenRects=manager->getSpace();
    update();
}
