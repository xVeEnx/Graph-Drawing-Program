#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H
#include <graphmanaging.h>
#include <QWidget>
#include <QPainter>
#include <QStaticText>

class graphSpace : public QWidget
{
    Q_OBJECT
public:
    explicit graphSpace(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
     int _iSpace;
public slots:
    void addGraphs();

private:
    QVector<QRect> graphsVect;
    QVector<QLine> _qLinia;
    int _iWidth;
    int _iScale;
};

#endif // GRAPHSPACE_H
