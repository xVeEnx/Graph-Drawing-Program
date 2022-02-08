#include "graphmanaging.h"
#include "QIntValidator"

GraphManaging::GraphManaging(QWidget *parent)
    : QWidget(parent)
{
    _qButtons=new QPushButton;
    _qButtons->setText(tr("Add"));
    _qButtons->setMaximumSize(200,50);

    _qTextHeightBox=new QLineEdit();
    _qTextHeightBox->setValidator( new QIntValidator(1,999999999, this));

    _qLabelLayout=new QFormLayout();
    _qLabelLayout->setSpacing(10);
    _qLabelLayout->addRow(tr("Add graph"),_qTextHeightBox);
    _qLabelLayout->addWidget(_qButtons);

    setLayout(_qLabelLayout);
    setFixedSize(280,620);

}
QPushButton* GraphManaging::getPushButton()
{
    return _qButtons;
}
QString GraphManaging::getGraphHeight()
{
    return _qTextHeightBox->text();
}
void GraphManaging::clearGraphHeight()
{
    _qTextHeightBox->setText("");
}
