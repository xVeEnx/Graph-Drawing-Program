#include "graphmanaging.h"
#include "QIntValidator"
#include <QFlags>
GraphManaging::GraphManaging(QWidget *parent)
    : QWidget(parent)
{

    _qButtons=new QPushButton;
    _qButtons->setText(tr("Add"));
    _qButtons->setMaximumSize(500,40);

    _qTextHeightBox=new QLineEdit();
    _qTextNameBox=new QLineEdit();
    _qTextHeightBox->setValidator( new QIntValidator(1,999999999, this));
    _qColorWindow=new QColorDialog();
    _qColorWindow->setOptions(
                   QColorDialog::DontUseNativeDialog
                   | QColorDialog::NoButtons
       );
    _qLabelLayout=new QFormLayout();
    clearGraphHeight();

    _qLabelLayout->addRow(tr("Add Graph"),_qTextHeightBox);
    _qLabelLayout->addRow(tr("Set Name"),_qTextNameBox);
    _qLabelLayout->addRow(tr("Set Color"),_qColorWindow);

    qDebug()<<_qColorWindow;
    _qLabelLayout->addWidget(_qButtons);
    setLayout(_qLabelLayout);
    setFixedSize(550,620);

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
    _qTextHeightBox->setText("1");
    _qTextNameBox->setText("Graph ");
}
QColor GraphManaging::getGraphColor()
{
    return _qColorWindow->currentColor();
}
QString GraphManaging::getGraphName()
{
    return _qTextNameBox->text();
}
