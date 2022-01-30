#include "graphmanaging.h"

GraphManaging::GraphManaging(QWidget *parent)
    : QWidget(parent)
{
    _qLabelWidth=new QLabel(parent);
    setQLabel(this,"Width");
    _qLabelHeight=new QLabel(parent);
    setQLabel(this,"Height");

    _qButtons[0].setText(tr("Add"));
    _qButtons[0].setParent(this);
    _qButtons[1].setText(tr("Add"));
    _qButtons[1].setParent(this);

      _qLabelLayout=new QHBoxLayout;

      _qLabelLayout->addWidget(_qLabelWidth);
      _qLabelLayout->addWidget(&_qButtons[0]);

      _qVerticalLayout=new QVBoxLayout;

      _qVerticalLayout->addLayout(_qLabelLayout);

      _qLabelLayout2=new QHBoxLayout;

      _qLabelLayout2->addWidget(_qLabelHeight);
      _qLabelLayout2->addWidget(&_qButtons[1]);

      _qVerticalLayout->addLayout(_qLabelLayout2);

        setLayout(_qVerticalLayout);
       // setFixedSize(280,620);

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
    if(str=="Width")
    {
        _qLabelWidth->setText(str);
        _qLabelWidth->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        _qLabelWidth->setFixedSize(100,25);
    }
    else if(str=="Height")
    {
                _qLabelHeight->setText(str);
                _qLabelHeight->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                _qLabelHeight->setFixedSize(100,25);
    }

}
