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
class graphWindow : public QFrame
{
    Q_OBJECT
public:
    graphWindow(QWidget *parent=nullptr);
protected:
    virtual void paintEvent(QPaintEvent *event);
public slots:
    void graphAdding();
private:
    void drawLabels();
    QGridLayout *_qMainLayout;
    QMenuBar *menuBar;
    QRect m_rectangle;
    QVector<QRect> graphsVect;
    QVector<QLine> _qLinia;
    int _qSpace;
    int _qWidth;
    int _qScale;
};

#endif // GRAPHWINDOW_H
