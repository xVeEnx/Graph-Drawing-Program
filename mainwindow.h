#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include <iostream>
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
    QString graphs;
    Ui::MainWindow *ui;
    QMenu *File;
    QAction *saveAction;
    QAction *openAction;
    QAction *exportAction;
};
#endif // MAINWINDOW_H
