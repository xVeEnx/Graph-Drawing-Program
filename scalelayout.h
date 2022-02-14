#ifndef SCALELAYOUT_H
#define SCALELAYOUT_H

#include <QWidget>
#include <QPainter>
#include <QStaticText>
class scaleLayout : public QWidget
{
    Q_OBJECT
public:
    explicit scaleLayout(QWidget *parent = nullptr,int qScale=5);
protected:
    void paintEvent(QPaintEvent *event);
signals:
private:
    QVector<QLine> _qLinia;
    QVector<QStaticText> _qText;
    int _iScale;
    scaleLayout* _qScaleLayout;
    scaleLayout* _qScaleWidget;
};

#endif // SCALELAYOUT_H
