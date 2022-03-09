#include "grect.h"

GRect::GRect()
{

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
