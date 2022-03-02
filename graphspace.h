#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H
#include <graphmanaging.h>
#include <QWidget>
#include <QPainter>
#include <QStaticText>
#include <scalelayout.h>

class graphSpace : public QWidget
{
    Q_OBJECT
public:
    explicit graphSpace(QWidget *parent = nullptr,QSize size={1000,500});
    QVector<QRect> getQRectVect();
    QVector<QStaticText> getQName();
    int getSpace();
signals:
    void layoutSetting();
protected:
    void paintEvent(QPaintEvent *event);
     int _iSpace;
public slots:
    void addGraphs();
    void sortFunc();

private:
    void sort(QVector<QRect>& vect,int left, int right);
    void refreshGraphs();
    QVector<QRect> graphsVect;
    QVector<QLine> _qLine;
    QVector<QColor> _qColor;
    QVector<QStaticText> _qName;
    void validateSize();
    int _iWidth;
    int _iScale;
};

#endif // GRAPHSPACE_H
