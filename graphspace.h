#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H
#include <graphmanaging.h>
#include <QWidget>
#include <QPainter>
#include <QStaticText>
#include <scalelayout.h>
#include <grect.h>

class graphSpace : public QWidget
{
    Q_OBJECT
public:
    explicit graphSpace(QWidget *parent = nullptr,QSize size={1000,500});
    QVector<GRect> getGRectVect();
    QVector<QStaticText> getQName();
    int getSpace();
signals:
    void layoutSetting();
    void graphSorted();
    void changeScale();
protected:
    void paintEvent(QPaintEvent *event);
     int _iSpace;
public slots:
    void addGraphs();
    void sortFunc();

private:
    void sort(QVector<GRect>& vect,int left, int right);
    void refreshGraphs();
    QVector<GRect> graphsVect;
    QVector<QLine> _qLine;
    QVector<QColor> _qColor;
    QVector<QStaticText> _qName;
    void widthChanging();
    int _iWidth;
    double _iScale;
    void swapRect(QVector<GRect>& qVec, int i,int j);
    int Partition(QVector<GRect> &v, int start, int end);
    void swapText(QVector<QStaticText>& qVec, int i,int j);
    int heightChanging(int height);
};

#endif // GRAPHSPACE_H
