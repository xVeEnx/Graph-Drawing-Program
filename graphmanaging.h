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
class GraphManaging : public QWidget
{
    Q_OBJECT
public:
    explicit GraphManaging(QWidget *parent = nullptr);
    QPushButton*  getPushButton();
    QString getGraphHeight();
    void clearGraphHeight();
signals:
//        void addGraph(int sizeOfGraph);
private slots:


private:

     QPushButton*  _qButtons;
     QFormLayout* _qLabelLayout;
     QLineEdit* _qTextHeightBox;
     QFormLayout* _qFormLayout;

};

#endif // GRAPHMANAGING_H
