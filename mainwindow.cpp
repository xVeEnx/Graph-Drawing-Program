#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QFileDialog>
#include <QTranslator>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    File=menuBar()->addMenu("File");
    saveAction=new QAction("Save");
    openAction=new QAction("Open");
    exportAction=new QAction("Export");

    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));
    connect(exportAction,SIGNAL(triggered()),this,SLOT(exportFunc()));

    File->addAction(saveAction);
    File->addAction(openAction);
    File->addAction(exportAction);
}
void MainWindow::save()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
}
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
}
void MainWindow::exportFunc()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

