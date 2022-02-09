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
    QPushButton *button1 = new QPushButton("One");
      QPushButton *button2 = new QPushButton("Two");
      QPushButton *button3 = new QPushButton("Three");
      QPushButton *button4 = new QPushButton("Four");
      QPushButton *button5 = new QPushButton("Five");

      _qLayout =new QHBoxLayout();
      _qHorizontalLayout=new QHBoxLayout();
      _qVerticalLayout=new QVBoxLayout();
      _qLabelWidget=new QWidget();
      _qGraphWidget=new graphSpace();
      _qFooterWidget=new QWidget();
     _qLabelWidget->setFixedSize(100,600);
     _qGraphWidget->setFixedSize(1000,595);
     _qFooterWidget->setFixedSize(1000,25);
//     QWidget* _qLabelWidget;
//     QWidget* _qGraphWidget;
//     QWidget* _qFooterWidget;
     button1->setParent(_qLabelWidget);
     button1->show();
     button2->setParent(_qGraphWidget);
     button2->show();
     button3->setParent(_qFooterWidget);
     button3->show();
     _qHorizontalLayout->addWidget(_qLabelWidget);
     _qVerticalLayout->addWidget(_qGraphWidget);
     _qVerticalLayout->addWidget(_qFooterWidget);
     _qLayout->addLayout(_qHorizontalLayout);
     _qLayout->addLayout(_qVerticalLayout);

    setFrameStyle(Box|Plain);
    setLineWidth(3);
    setFixedSize(1000,620);

    //drawLabels();
    setLayout(_qLayout);

}

//void graphWindow::paintEvent(QPaintEvent *event)
//{
//    qDebug()<<_qGraphWidget<<" <-graphwidget \nthis:"<<this;

//}

//void graphWindow::graphAdding()
//{

//}
void graphWindow::drawLabels()
{
//    _qMainLayout= new QGridLayout;
////    _qMainLayout->setSpacing(0);
//    _qMainLayout->setContentsMargins(1,1,1,1);

////   _qMainLayout->addWidget(new QLabel("12"),0,0);
////   _qMainLayout->addWidget(new QLabel("12"),1,0);
////   _qMainLayout->addWidget(new QLabel("12"),2,0);
////   _qMainLayout->addWidget(new QLabel("12"),3,0);
//   QSpacerItem *spc= new QSpacerItem(40,20,QSizePolicy::Minimum,QSizePolicy::Expanding);
//    _qMainLayout->addItem(spc,4,0);
//    //pozniej odkomentowac - odzzielanie linia labelow _qLinia.push_back(QLine(100,0,100,QWidget::height()));

//    _qMainLayout->setVerticalSpacing(50);
//     setLayout(_qMainLayout);
}
graphSpace *graphWindow::getGraphSpace()
{
    return _qGraphWidget;
}
