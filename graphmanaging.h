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
     std::unique_ptr<QPushButton>  _qButtons;
     std::unique_ptr<QFormLayout> _qLabelLayout;
     std::unique_ptr<QLineEdit> _qTextHeightBox;
     std::unique_ptr<QLineEdit> _qTextNameBox;
     std::unique_ptr<QColorDialog> _qColorWindow;
     std::unique_ptr<QFormLayout> _qFormLayout;

};

#endif // GRAPHMANAGING_H
