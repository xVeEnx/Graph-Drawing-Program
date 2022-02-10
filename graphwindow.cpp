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

      setFrameStyle(Box|Plain);
      setLineWidth(3);
      setFixedSize(1000,620);

      _qLayout =new QHBoxLayout();
      _qHorizontalLayout=new QHBoxLayout();
      _qVerticalLayout=new QVBoxLayout();
      _qGraphWidget=new graphSpace();
      _qScaleWidget=new scaleLayout();
      _qFooterWidget=new QWidget();
      _qScaleWidget->setFixedSize(100,550);
     _qGraphWidget->setFixedSize(1000,550);
     qDebug()<<_qScaleWidget->height()<<"scalewidget  size";
     qDebug()<<_qGraphWidget->height()<<"graphwidget  size";
     _qFooterWidget->setMinimumSize(1000,25);
//     QWidget* _qLabelWidget;
//     QWidget* _qGraphWidget;
//     QWidget* _qFooterWidget;
    // button1->setParent(_qLabelWidget);
    // button1->show();
    // button2->setParent(_qGraphWidget);
    // button2->show();
    // button3->setParent(_qFooterWidget);
    // button3->show();
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
