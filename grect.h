#ifndef GRECT_H
#define GRECT_H

#include <QRect>
#include <QObject>
#include <QColor>
#include <QStaticText>
#include <QPainter>

class GRect : public QRect
{
public:
    GRect(QRect qrect);
    GRect(QRect qrect,QColor col,QStaticText text);
    QRect getQRectangle();
    QColor getQColor();
    QStaticText getQText();
    void drawRect();
    void setBottomLeft(QPoint pt);
    void setWidth(int w);
    void setHeight(int h) noexcept;
    void setQColor(QColor col);
    void setQText(QStaticText text);
    int  height();
    int  width();
    int getOriginalHeight();
    void setOriginalHeight(int height);
private:
    QRect _qRectangle;
    QColor _qColor;
    QStaticText _qText;
    int  _iOriginalHeight;
};

#endif // GRECT_H
