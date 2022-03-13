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
#include <QSignalMapper>
#include <QTextStream>
class graphWindow : public QFrame
{
Q_OBJECT
public:
graphWindow(QWidget *parent=nullptr,QSize graphWindowSize=QSize(1050,500));
graphSpace* getGraphSpace();
GraphFooter* getGraphFooter();
QString exportToXML();
void importFromXML(QFile& file);

private:
std::unique_ptr<scaleLayout> _qScaleWidget;
std::unique_ptr<QHBoxLayout> _qLayout;
std::unique_ptr<QHBoxLayout> _qHorizontalLayout;
std::unique_ptr<QVBoxLayout> _qVerticalLayout;
std::unique_ptr<graphSpace>_qGraphWidget;
std::unique_ptr<GraphFooter> _qFooterWidget;
QGridLayout *_qMainLayout;
QMenuBar *menuBar;
QRect m_rectangle;
QSignalMapper* _qSignalMapper;

};

#endif // GRAPHWINDOW_H
