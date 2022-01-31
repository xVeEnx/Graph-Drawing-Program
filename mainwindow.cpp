#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QFileDialog>
#include <QTranslator>
#include <QLabel>
#include <QFile>
#include <QLayout>
#include <QMessageBox>
#include <QPushButton>

//#include <graphwindow.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QWidget *widget=new QWidget;
    resize(1280, 620);
    _qLayoutLeft=new QHBoxLayout;
    _qLayoutRight=new QHBoxLayout;
    _qFinalLayout=new QHBoxLayout;
    _qGraphWindow=new graphWindow(this);
    _qGraphManager=new GraphManaging(this);

    _qLayoutLeft->addWidget(_qGraphWindow);
    _qLayoutRight->addWidget(_qGraphManager);
    _qFinalLayout->addLayout(_qLayoutLeft);
    _qFinalLayout->addLayout(_qLayoutRight);

     widget->setLayout(_qFinalLayout);
     setCentralWidget(widget);
     createMenus();
     QObject::connect(_qGraphManager->getPushButton(),SIGNAL(pressed()),
                            _qGraphWindow,SLOT(graphAdding()));

}
void MainWindow::createMenus()
{
    this->graphs="For now empty";
   // ui->setupUi(this);
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if(fileName!="")
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
           file.close();
           QMessageBox messageBox;
           messageBox.critical(0,"Error","An error has occured !");
           messageBox.setFixedSize(500,200);
        }
        else{
            QTextStream stream(&file);
            stream<<this->graphs;
            stream.flush();
            file.close();
        }
    }
}
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if(fileName!="")
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)){

           file.close();
           QMessageBox messageBox;
           messageBox.critical(0,"Error","An error has occured !");
           messageBox.setFixedSize(500,200);
        }
        else{
            QTextStream stream(&file);
                graphs=stream.readAll();
            file.close();
        }
    }
}
void MainWindow::exportFunc()
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error","Not defined yet !");
    messageBox.setFixedSize(500,200);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

