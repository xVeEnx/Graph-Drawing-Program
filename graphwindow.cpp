#include "graphwindow.h"
#include <QPainter>
#include <QRect>
#include <QLayout>
#include <mainwindow.h>
#include <QPushButton>
#include <QSpacerItem>
#include <QSizePolicy>
graphWindow::graphWindow(QWidget *parent) : QFrame(parent)
{

    setFrameStyle(Box);
    setLineWidth(3);
    setFixedSize(1000,620);
    _qWidth=15;
    _qSpace=5;
    _qScale=100;
    drawLabels();


}

void graphWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0; i<graphsVect.size(); i++)painter.drawRect(graphsVect[i]);

    for(int i=0;i<_qLinia.size();i++) painter.drawLine(_qLinia[i]);
}

void graphWindow::graphAdding()
{
    int height=QWidget::height();
    GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
    int graphHeight=(manager->getGraphHeight()).toInt();

    if(graphHeight<1) return;

    qDebug()<<graphHeight;
    int numOfGraphs= graphsVect.size();
    graphsVect.push_back(QRect(_qSpace*numOfGraphs+_qWidth*numOfGraphs,height-1,_qWidth,-graphHeight));
    //_qLinia;
    manager->clearGraphHeight();
    update();
}
void graphWindow::drawLabels()
{
    _qMainLayout= new QGridLayout;
//    _qMainLayout->setSpacing(0);
    _qMainLayout->setContentsMargins(1,1,1,1);
    for(int i=10;i>0;i--)
    {
        double iscl=_qScale*0.05*i;
        QString str=QString::number(iscl);
            //_qMainLayout->addWidget(new QLabel(str),i,0);
            _qLinia.push_back(QLine(0,QWidget::height()/10*i,50,QWidget::height()/10*i)); //cos spacing w gridzie wali
            _qLinia.push_back(QLine(20*i,QWidget::height()/10*i,20*i,0)); //linie pomocnicze sprawdzam wysokosci
    }
   _qMainLayout->addWidget(new QLabel("12"),0,0);
   _qMainLayout->addWidget(new QLabel("12"),1,0);
   _qMainLayout->addWidget(new QLabel("12"),2,0);
   _qMainLayout->addWidget(new QLabel("12"),3,0);
   QSpacerItem *spc= new QSpacerItem(40,20,QSizePolicy::Minimum,QSizePolicy::Expanding);
    _qMainLayout->addItem(spc,4,0);
    //pozniej odkomentowac - odzzielanie linia labelow _qLinia.push_back(QLine(100,0,100,QWidget::height()));

    _qMainLayout->setVerticalSpacing(50);
     setLayout(_qMainLayout);
}
