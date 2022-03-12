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
    int width=QInputDialog::getInt(this,"Podaj szerokość:","Szerokość: (500-1600)",1050,500,1600);
    int height=QInputDialog::getInt(this,"Podaj wysokość:","Wysokość: (200-850)",600,200,850);

    QWidget *widget=new QWidget;
    _qLayoutLeft=new QHBoxLayout;
    _qLayoutRight=new QHBoxLayout;
    _qFinalLayout=new QHBoxLayout;
    _qGraphWindow=new graphWindow(this,QSize(width,height));
    _qGraphManager=new GraphManaging(this);

    _qLayoutLeft->addWidget(_qGraphWindow);
    _qLayoutRight->addWidget(_qGraphManager);
    _qFinalLayout->addLayout(_qLayoutLeft);
    _qFinalLayout->addLayout(_qLayoutRight);
    widget->setLayout(_qFinalLayout);
    setCentralWidget(widget);
    createMenus();
    connect(_qGraphManager->getPushButton(),SIGNAL(pressed()),
            _qGraphWindow->getGraphSpace(),SLOT(addGraphs()));
    connect(_qGraphWindow->getGraphSpace(),SIGNAL(layoutSetting()),
            _qGraphWindow->getGraphFooter(),SLOT(setRects()));

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}
void MainWindow::createMenus()
{
    this->graphs="For now empty";
    // ui->setupUi(this);
    File=menuBar()->addMenu("File");
    saveAction=new QAction("Save");
    openAction=new QAction("Open");
    sortAction=new QAction("Sort graphs");

    connect(saveAction,SIGNAL(triggered()),
            this,SLOT(save()));
    connect(openAction,SIGNAL(triggered()),
            this,SLOT(open()));
    connect(sortAction,SIGNAL(triggered()),
            _qGraphWindow->getGraphSpace(),SLOT(sortFunc()));

    File->addAction(saveAction);
    File->addAction(openAction);
    File->addAction(sortAction);
}
void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("XML Files (*.xml)"));
    if(fileName!="")
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)) {
            file.close();
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured !");
            messageBox.setFixedSize(500,200);
        }
        else{
            exportToXml(file);
            file.close();
        }
    }
}
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("XML Files (*.xml)"));
    if(fileName!="")
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)) {

            file.close();
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured !");
            messageBox.setFixedSize(500,200);
        }
        else{
             importFromXml(file);
            file.close();
        }

    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::exportToXml(QFile& file)
{
    QTextStream stream(&file);
    qDebug()<<_qGraphWindow->exportToXML()<<" tresc";
    stream<<_qGraphWindow->exportToXML();
    stream.flush();
}
void MainWindow::importFromXml(QFile& file)
{
    _qGraphWindow->importFromXML(file);
}

