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
#include <QFormLayout>
#include <QColorDialog>
class GraphManaging : public QWidget
{
    Q_OBJECT
public:
    explicit GraphManaging(QWidget *parent = nullptr);
    QPushButton*  getPushButton();
    QString getGraphHeight();
    QString getGraphName();
    QColor getGraphColor();
    void clearGraphHeight(int i);
signals:
//        void addGraph(int sizeOfGraph);
private slots:


private:
     QColor* _qGraphColor;
     QPushButton*  _qButtons;
     QFormLayout* _qLabelLayout;
     QLineEdit* _qTextHeightBox;
     QLineEdit* _qTextNameBox;
     QColorDialog * _qColorWindow;
     QFormLayout* _qFormLayout;

};

#endif // GRAPHMANAGING_H
