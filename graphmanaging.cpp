#include "graphmanaging.h"

GraphManaging::GraphManaging(QWidget *parent)
    : QWidget(parent)
{

    _qLabelHeight=new QLabel();
    setQLabel(this,"Height");

    _qButtons=new QPushButton;
    _qButtons->setText(tr("Add"));

     _qTextHeightBox=new QLineEdit();
   //  _qTextHeightBox->setContentsMargins(-1,-1,-1,-1);

      _qLabelLayout=new QHBoxLayout;
      _qLabelLayout->addWidget(_qLabelHeight),Qt::AlignTop;
      _qLabelLayout->addWidget(_qTextHeightBox,Qt::AlignTop);
      _qLabelLayout->setSpacing(0);

      _qVerticalLayout=new QVBoxLayout;
      _qVerticalLayout->addLayout(_qLabelLayout,Qt::AlignTop);
      _qVerticalLayout->setSpacing(0);
      //_qVerticalLayout->setMargin(0);



      _qVerticalLayout->addLayout(_qLabelLayout,Qt::AlignTop);
      _qVerticalLayout->addWidget(_qButtons);


        setLayout(_qVerticalLayout);
        setFixedSize(280,620);

}
void GraphManaging::paintEvent(QPaintEvent *event)
{
//    auto SBM=new QLabel(this);

//    QPainter painter(this)
////    painter.drawRect(QRect(0,0,100,50));
//    painter.draw
}
void GraphManaging::setQLabel(QWidget *parent,QString str)
{
                _qLabelHeight->setText(str);
                _qLabelHeight->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                _qLabelHeight->setFixedSize(100,25);
}
