#include "graphwindow.h"
#include <QPainter>
#include <QRect>
#include <QLayout>
#include <mainwindow.h>
#include <QPushButton>
#include <QSpacerItem>
#include <QSizePolicy>
graphWindow::graphWindow(QWidget *parent,QSize graphWindowSize) : QFrame(parent)
{
    QSize scaleSize(50,graphWindowSize.height()+100);
    QSize graphSize(graphWindowSize);
    QSize footerFixedSize(graphWindowSize.width(),100);
    if(graphSize.height()+footerFixedSize.height()!=scaleSize.height()
            &&footerFixedSize.height()>=100
            &&graphSize.height()>=500)//footer size has to be >=100scalesizeheight=graphsize.height+footerminsize.height
    {
        qDebug()<<"scalesize height has to be graphsize.height+ footermin.height";
      exit(EXIT_FAILURE);//graphsize && scalesize must be the same or scale wont work good
    }

    setFrameStyle(Box|Plain);
      setLineWidth(3);

      _qLayout =new QHBoxLayout();
      _qHorizontalLayout=new QHBoxLayout();
      _qVerticalLayout=new QVBoxLayout();

      _qGraphWidget=new graphSpace(nullptr,graphSize);
      _qScaleWidget=new scaleLayout(nullptr,scaleSize,footerFixedSize);
      _qFooterWidget=new GraphFooter(nullptr,footerFixedSize);

      QObject::connect(_qGraphWidget,SIGNAL(graphSorted()),
                      _qFooterWidget,SLOT(setRects()));

     _qHorizontalLayout->addWidget(_qScaleWidget);
     _qVerticalLayout->setSpacing(0);
     _qVerticalLayout->addWidget(_qGraphWidget);
     _qVerticalLayout->addWidget(_qFooterWidget);

     _qLayout->addLayout(_qHorizontalLayout);
     _qLayout->addLayout(_qVerticalLayout);



    //drawLabels();
    setLayout(_qLayout);
}


graphSpace *graphWindow::getGraphSpace()
{
    return _qGraphWidget;
}

GraphFooter *graphWindow::getGraphFooter()
{
    return _qFooterWidget;
}
