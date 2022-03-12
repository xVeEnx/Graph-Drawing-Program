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
#include<string>
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
    void addingProcedure(int graphHeight,QColor color,QStaticText label);
    QString listElements(QDomElement root,QString tagname,QString attribute);
    void sort(QVector<GRect>& vect,int left, int right);
    void refreshGraphs();
    QVector<GRect> graphsVect;
    QVector<QLine> _qLine;
   // QVector<QColor> _qColor;
  //  QStaticText _qName;
    void widthChanging();
    int _iWidth;
    double _iScale;
    void swapRect(QVector<GRect>& qVec, int i,int j);
    int Partition(QVector<GRect> &v, int start, int end);
    void swapText(QVector<QStaticText>& qVec, int i,int j);
    void heightChanging(int height);

};

#endif // GRAPHSPACE_H
