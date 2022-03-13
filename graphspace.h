#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H
#include <graphmanaging.h>
#include <QWidget>
#include <QPainter>
#include <QStaticText>
#include <scalelayout.h>
#include <grect.h>
#include <QFile>
#include <iostream>
#include <sstream>
#include <string>
#include <QtXml>
class graphSpace : public QWidget
{
Q_OBJECT

public:

explicit graphSpace(QWidget *parent = nullptr,QSize size={1000,500});
QVector<GRect> getGRectVect();
QVector<QStaticText> getQName();
int getSpace();
double getScale();
void importFromXML(QFile& file);
QString exportToXML();

signals:
void layoutSetting();
void graphSorted();
void changeScale();

protected:
void paintEvent(QPaintEvent *event);
int _iSpace;

public slots:
void addGraphs();
void sortFunc();

private:
QString listElements(QDomElement root,QString tagname,QString attribute);
int Partition(QVector<GRect> &v, int start, int end);
void addingProcedure(int graphHeight,QColor color,QStaticText label);
void sort(QVector<GRect>& vect,int left, int right);
void refreshGraphs();
void swapRect(QVector<GRect>& qVec, int i,int j);
void heightChanging(int graphHeight);
void widthChanging();

QVector<GRect> _qGraph;
QVector<QLine> _qLine;
int _iGraphWidth;
double _iScale;


};

#endif // GRAPHSPACE_H
