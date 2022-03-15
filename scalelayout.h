#ifndef SCALELAYOUT_H
#define SCALELAYOUT_H

#include <QWidget>
#include <QPainter>
#include <QStaticText>
#include <QSize>
#include <graphspace.h>
class scaleLayout : public QWidget
{
    Q_OBJECT
public:
    explicit scaleLayout(QWidget *parent,QSize size,QSize footerSize);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void scaleChanging();
private:
    void setScale();
    int _iScaleLayoutHeight;
    double _iScale;
    QVector<QLine> _qLines;
    QVector<QStaticText> _qText;
};

#endif // SCALELAYOUT_H
