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
    int _iHeight;
    double _iScale;
    QVector<QLine>_qLinia;
    QVector<QStaticText> _qText;
    scaleLayout* _qScaleLayout;
    scaleLayout* _qScaleWidget;
    void setScale();
};

#endif // SCALELAYOUT_H
