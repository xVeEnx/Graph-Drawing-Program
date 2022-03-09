#ifndef GRECT_H
#define GRECT_H

#include <QRect>
#include <QObject>
#include <QColor>
#include <QStaticText>
class GRect : public QRect
{
public:
    GRect();
    QRect getQRectangle();
    QColor getQColor();
    QStaticText getQText();
private:
    QRect _qRectangle;
    QColor _qColor;
    QStaticText _qText;
};

#endif // GRECT_H
