#ifndef GRAPHFOOTER_H
#define GRAPHFOOTER_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QStaticText>
#include <QPointer>
#include <graphspace.h>
#include <grect.h>

class GraphFooter : public QWidget
{
    Q_OBJECT
public slots:
    void setRects();
public:
        explicit GraphFooter(QWidget *parent = nullptr,QSize size={1000,25});
public slots:
protected:
    void paintEvent(QPaintEvent *event);




private:
    QVector<QStaticText> _qGraphLabel;
    QVector<GRect> _gGraphs;
    int _iSpaceBetweenRects;

};

#endif // GRAPHFOOTER_H
