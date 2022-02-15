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
    QSize scaleSize(50,600);
    QSize graphSize(1050,500);
    QSize footerMinSize(1000,25);
    if(graphSize.height()+100!=scaleSize.height())
    {
        qDebug()<<"graphsize height has to be 100 larger than scaleSize";
        exit(EXIT_FAILURE);//graphsize && scalesize must be the same or scale wont work good
    }
      setFrameStyle(Box|Plain);
      setLineWidth(3);

      _qLayout =new QHBoxLayout();
      _qHorizontalLayout=new QHBoxLayout();
      _qVerticalLayout=new QVBoxLayout();

      _qGraphWidget=new graphSpace(nullptr,graphSize);
      _qScaleWidget=new scaleLayout(nullptr,scaleSize);
      _qFooterWidget=new GraphFooter();


     qDebug()<<_qScaleWidget->height()<<"scalewidget  size";
     qDebug()<<_qGraphWidget->height()<<"graphwidget  size";

     _qHorizontalLayout->addWidget(_qScaleWidget);
     _qVerticalLayout->setSpacing(0);
     _qVerticalLayout->addWidget(_qGraphWidget);
     _qVerticalLayout->addWidget(_qFooterWidget);

     _qLayout->addLayout(_qHorizontalLayout);
     _qLayout->addLayout(_qVerticalLayout);



    //drawLabels();
    setLayout(_qLayout);
    qDebug()<<_qScaleWidget->height()<<"at the end scalewidget  size";
    qDebug()<<_qGraphWidget->height()<<"at the end graphwidget  size";
}


graphSpace *graphWindow::getGraphSpace()
{
    return _qGraphWidget;
}

GraphFooter *graphWindow::getGraphFooter()
{
    return _qFooterWidget;
}
