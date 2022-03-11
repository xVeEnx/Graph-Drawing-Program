#ifndef SCALELAYOUT_H
#define SCALELAYOUT_H

#include <QWidget>
#include <QPainter>
#include <QStaticText>
#include <QSize>

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
    int _iScale;
    QVector<QLine>_qLinia;
    QVector<QStaticText> _qText;
    scaleLayout* _qScaleLayout;
    scaleLayout* _qScaleWidget;
};

#endif // SCALELAYOUT_H
