#include "graphspace.h"

graphSpace::graphSpace(QWidget *parent)
    : QWidget{parent}
{
    setContentsMargins(0,0,0,0);
    _iWidth=15;
    _iSpace=5;
    _iScale=100;
    auto _qMainLayout=new QVBoxLayout();
    double height=this->height()/10;
    _qMainLayout->setSpacing(40);

    qDebug()<<height;
    for(int i=10; i>=0; i--)
    {
        double iscl=_iScale*0.05*i;
        QString str=QString::number(iscl);
        _qMainLayout->addWidget(new QLabel(str));
        _qLinia.push_back(QLine(0,55*i+1,1001,55*i+1));
    }
    _qMainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));
    setLayout(_qMainLayout);
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
    for(int i=0; i<graphsVect.size(); i++) painter.drawRect(graphsVect[i]);

    for(int i=0; i<_qLinia.size(); i++) painter.drawLine(_qLinia[i]);
}
