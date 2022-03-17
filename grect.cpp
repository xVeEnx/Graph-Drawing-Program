#include "grect.h"


GRect::GRect(QRect qrect)
{
    _qRectangle=qrect;
}
GRect::GRect(QRect qrect,QColor col,QStaticText text)
{
    _qRectangle=qrect;
    _qColor=col;
    _qText=text;
}
QRect GRect::getQRectangle()
{
    return _qRectangle;
}
QColor GRect::getQColor()
{
    return _qColor;
}
QStaticText GRect::getQText()
{
    return _qText;
}
void GRect::setBottomLeft(QPoint pt)
{
    _qRectangle.setBottomLeft(pt);
}
void GRect::setWidth(int w)
{
    _qRectangle.setWidth(w);
}
int GRect::height()
{
    return _qRectangle.height();
}
int GRect::width()
{
    return _qRectangle.width();
}
void GRect::setHeight(int h) noexcept
{
    _qRectangle.setHeight(h);
}
void GRect::setQColor(QColor col)
{
    _qColor=col;
}
void GRect::setQText(QStaticText text)
{
    _qText=text;
}
int GRect::getOriginalHeight()
{
    return _iOriginalHeight;
}
void GRect::setOriginalHeight(int height)
{
    _iOriginalHeight=height;
}
