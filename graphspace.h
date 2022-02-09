#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H
#include <graphmanaging.h>
#include <QWidget>
#include <QPainter>
class graphSpace : public QWidget
{
    Q_OBJECT
public:
    explicit graphSpace(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void addGraphs();
private:
    QVector<QRect> graphsVect;
    QVector<QLine> _qLinia;
    int _iSpace;
    int _iWidth;
    int _iScale;
};

#endif // GRAPHSPACE_H
