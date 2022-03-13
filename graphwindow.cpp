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

      _qLayout =std::unique_ptr<QHBoxLayout>(new QHBoxLayout());
      _qHorizontalLayout=std::unique_ptr<QHBoxLayout>(new QHBoxLayout());
      _qVerticalLayout=std::unique_ptr<QVBoxLayout>(new QVBoxLayout());
      _qGraphWidget=std::unique_ptr<graphSpace>(new graphSpace(nullptr,graphSize));
      _qScaleWidget=std::unique_ptr<scaleLayout>(new scaleLayout(nullptr,scaleSize,footerFixedSize));
      _qFooterWidget=std::unique_ptr<GraphFooter>(new GraphFooter(nullptr,footerFixedSize));

      QObject::connect(_qGraphWidget.get(),SIGNAL(graphSorted()),
                      _qFooterWidget.get(),SLOT(setRects()));
      QObject::connect(_qGraphWidget.get(),SIGNAL(changeScale()),
                      _qScaleWidget.get(),SLOT(scaleChanging()));

     _qHorizontalLayout->addWidget(_qScaleWidget.get());
     _qVerticalLayout->setSpacing(0);
     _qVerticalLayout->addWidget(_qGraphWidget.get());
     _qVerticalLayout->addWidget(_qFooterWidget.get());

     _qLayout->addLayout(_qHorizontalLayout.get());
     _qLayout->addLayout(_qVerticalLayout.get());




    setLayout(_qLayout.get());
}


graphSpace *graphWindow::getGraphSpace()
{
    return _qGraphWidget.get();
}

GraphFooter *graphWindow::getGraphFooter()
{
    return _qFooterWidget.get();
}
QString graphWindow::exportToXML()
{
        return _qGraphWidget->exportToXML();
}
void graphWindow::importFromXML(QFile& file)
{
    _qGraphWidget->importFromXML(file);
}
