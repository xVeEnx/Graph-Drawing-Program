#ifndef GRAPHMANAGING_H
#define GRAPHMANAGING_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLayout>
#include <QPainter>
#include <QLabel>
#include <QTranslator>

class GraphManaging : public QWidget
{
    Q_OBJECT
public:
    explicit GraphManaging(QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent *event);
signals:

private:
     void setQLabel(QWidget *parent,QString str);
      QPushButton  _qButtons[2];
     QLabel *_qLabelWidth;
     QLabel *_qLabelHeight;
     QGridLayout* _qButtonLayout;
     QHBoxLayout* _qLabelLayout;
     QHBoxLayout* _qLabelLayout2;
     QVBoxLayout* _qVerticalLayout;



};

#endif // GRAPHMANAGING_H
