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

private:
     void exportToXml(QFile& file);
    void createMenus();
    std::unique_ptr<GraphManaging> _qGraphManager;
    QString _qGraphs;
    Ui::MainWindow *_qUi;
    std::unique_ptr<QMenu>_qFile;
    std::unique_ptr<QHBoxLayout> _qLayoutLeft;
    std::unique_ptr<QHBoxLayout> _qLayoutRight;
    std::unique_ptr<QHBoxLayout> _qFinalLayout;
    std::unique_ptr<graphWindow> _qGraphWindow;
    std::unique_ptr<QAction> _qSaveAction;
    std::unique_ptr<QAction> _qOpenAction;
    std::unique_ptr<QAction> _qSortAction;

};
#endif // MAINWINDOW_H
