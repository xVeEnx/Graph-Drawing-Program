#ifndef GRAPHFOOTER_H
#define GRAPHFOOTER_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QStaticText>
#include <QPointer>
#include <graphspace.h>
class GraphFooter : public QWidget
{
    Q_OBJECT
public slots:
    void setRects();
public:
        explicit GraphFooter(QWidget *parent = nullptr,QSize size={1000,25});
protected:
    void paintEvent(QPaintEvent *event);



signals:
private:
    QVector<QStaticText> _qName;
    QVector<QRect> _qRect;


};

#endif // GRAPHFOOTER_H