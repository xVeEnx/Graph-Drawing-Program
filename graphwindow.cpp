#include "graphwindow.h"
#include <QPainter>
#include <QRect>
#include <QLayout>
#include <mainwindow.h>
graphWindow::graphWindow(QWidget *parent) : QFrame(parent)
{
    //QWidget *widget= new QWidget;

    //layout->add
   // auto options=new MainWindow(this);
    //QMenuBar *menuBar=new QMenuBar(this);
  //  menuBar->addMenu("&File");
    //QHBoxLayout* leftSide= new QHBoxLayout();
  //  m_rectangle= QRect(15,15,100,100);
    setFrameStyle(Box | Plain);


}
void graphWindow::paintEvent(QPaintEvent *event)
{

        QPainter painter(this);
    m_rectangle= QRect(0,0,300,300);
    painter.drawRect(m_rectangle);

}

