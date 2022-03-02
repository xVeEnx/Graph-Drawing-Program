#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDockWidget>
#include <QObject>
#include <QFrame>
#include <QRect>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QObject>
#include <graphmanaging.h>
#include <graphspace.h>
#include <scalelayout.h>
#include <graphfooter.h>
class graphWindow : public QFrame
{
    Q_OBJECT
public:
    graphWindow(QWidget *parent=nullptr,QSize graphWindowSize=QSize(1050,500));
    graphSpace* getGraphSpace();
    GraphFooter* getGraphFooter();

private:
    void drawLabels();
    scaleLayout* _qScaleWidget;
    QHBoxLayout* _qLayout;
    QHBoxLayout* _qHorizontalLayout;
    QVBoxLayout* _qVerticalLayout;
    graphSpace *_qGraphWidget;
    GraphFooter* _qFooterWidget;
    QGridLayout *_qMainLayout;
    QMenuBar *menuBar;
    QRect m_rectangle;


};

#endif // GRAPHWINDOW_H
