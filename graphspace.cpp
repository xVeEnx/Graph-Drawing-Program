#include "graphspace.h"

graphSpace::graphSpace(QWidget *parent)
    : QWidget{parent}
{
    _iWidth=15;
    _iSpace=5;
    _iScale=100;

    for(int i=5;i>0;i--)
    {
        double iscl=_iScale*0.05*i;
        QString str=QString::number(iscl);
            //_qMainLayout->addWidget(new QLabel(str),i,0);
            _qLinia.push_back(QLine(0,QWidget::height()/10*i,50,QWidget::height()/10*i)); //cos spacing w gridzie wali
            _qLinia.push_back(QLine(20*i,QWidget::height()/10*i,20*i,0)); //linie pomocnicze sprawdzam wysokosci
    }
}
void graphSpace::addGraphs()
{
    int height=QWidget::height();
     GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
     int graphHeight=(manager->getGraphHeight()).toInt();

     if(graphHeight<1) return;

     qDebug()<<graphHeight;

     //_qLinia;
     manager->clearGraphHeight();
    int numOfGraphs= graphsVect.size();
    graphsVect.push_back(QRect(_iSpace*numOfGraphs+_iWidth*numOfGraphs,height-1,_iWidth,-graphHeight));
    update();
}
void graphSpace::paintEvent(QPaintEvent *event)
{
QPainter painter(this);
for(int i=0; i<graphsVect.size(); i++)painter.drawRect(graphsVect[i]);

for(int i=0;i<_qLinia.size();i++) painter.drawLine(_qLinia[i]);
}
