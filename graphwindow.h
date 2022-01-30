#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDockWidget>
#include <QObject>
#include <QFrame>
#include <QRect>
#include <QMenuBar>
class graphWindow : public QFrame
{
public:
    graphWindow(QWidget *parent=nullptr);
protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    QMenuBar *menuBar;
    QRect m_rectangle;


};

#endif // GRAPHWINDOW_H
