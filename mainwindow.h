#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include <iostream>
#include <QLayout>
#include <QSlider>
#include <graphwindow.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void open();
    void save();
    void exportFunc();


private:

    void createMenus();
    QString graphs;
    Ui::MainWindow *ui;
    QMenu *File;
    QGridLayout _qLayout;
    graphWindow _qGraphWindow;
    QAction *saveAction;
    QAction *openAction;
    QAction *exportAction;
};
#endif // MAINWINDOW_H
