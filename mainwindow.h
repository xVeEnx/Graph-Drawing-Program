#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include <iostream>
#include <QLayout>
#include <QSlider>
#include <graphwindow.h>
#include <graphmanaging.h>
#include <graphspace.h>
#include <QInputDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
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
    GraphManaging* _qGraphManager;
    QString graphs;
    Ui::MainWindow *ui;
    QMenu *File;
    QHBoxLayout* _qLayoutLeft;
    QHBoxLayout* _qLayoutRight;
    QHBoxLayout* _qFinalLayout;
    graphWindow* _qGraphWindow;
    QAction *saveAction;
    QAction *openAction;
    QAction *exportAction;
    QAction *sortAction;

};
#endif // MAINWINDOW_H
