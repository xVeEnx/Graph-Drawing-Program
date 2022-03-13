#include "graphmanaging.h"
#include "QIntValidator"
#include <QFlags>
GraphManaging::GraphManaging(QWidget *parent)
    : QWidget(parent)
{

    _qButtons=std::unique_ptr<QPushButton>(new QPushButton());
    _qButtons->setText(tr("Add"));
    _qButtons->setMaximumSize(500,40);

    _qTextHeightBox=std::unique_ptr<QLineEdit>(new QLineEdit);
    _qTextNameBox=std::unique_ptr<QLineEdit>(new QLineEdit);
    _qTextHeightBox->setValidator( new QIntValidator(1,999999999, this));
    _qColorWindow=std::unique_ptr<QColorDialog>(new QColorDialog());
    _qColorWindow->setOptions(
                   QColorDialog::DontUseNativeDialog
                   | QColorDialog::NoButtons
       );
    _qLabelLayout=std::unique_ptr<QFormLayout>(new QFormLayout);
    clearGraphHeight(1);

    _qLabelLayout->addRow(tr("Add Graph"),_qTextHeightBox.get());
    _qLabelLayout->addRow(tr("Set Name"),_qTextNameBox.get());
    _qLabelLayout->addRow(tr("Set Color"),_qColorWindow.get());

    _qLabelLayout->addWidget(_qButtons.get());
    setLayout(_qLabelLayout.get());
    setFixedSize(550,620);

}
QPushButton* GraphManaging::getPushButton()
{
    return _qButtons.get();
}
QString GraphManaging::getGraphHeight()
{
    return _qTextHeightBox->text();
}
void GraphManaging::clearGraphHeight(int i)
{
    _qTextHeightBox->setText("1");
    _qTextNameBox->setText(QString::number(i));
}
QColor GraphManaging::getGraphColor()
{
    return _qColorWindow->currentColor();
}
QString GraphManaging::getGraphName()
{
    return _qTextNameBox->text();
}
