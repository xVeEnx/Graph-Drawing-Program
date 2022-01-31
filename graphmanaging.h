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
#include <QLineEdit>
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
      QPushButton*  _qButtons;
     QLabel *_qLabelHeight;
     QHBoxLayout* _qLabelLayout;
     QHBoxLayout* _qLabelLayout2;
     QVBoxLayout* _qVerticalLayout;
     QLineEdit* _qTextWidthBox;
     QLineEdit* _qTextHeightBox;


};

#endif // GRAPHMANAGING_H
