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
    ,_qUi(new Ui::MainWindow)
{
    setWindowTitle("Graphs");
    const int width=QInputDialog::getInt(this,"Podaj szerokość:","Szerokość: (500-1600)",1050,500,1600);
    const int height=QInputDialog::getInt(this,"Podaj wysokość:","Wysokość: (200-850)",600,200,850);

    QWidget *widget=new QWidget;
    _qLayoutLeft=std::unique_ptr<QHBoxLayout>(new QHBoxLayout);
    _qLayoutRight=std::unique_ptr<QHBoxLayout>(new QHBoxLayout);
    _qFinalLayout=std::unique_ptr<QHBoxLayout>(new QHBoxLayout);
    _qGraphWindow=std::unique_ptr<graphWindow>(new graphWindow(this,QSize(width,height)));
    _qGraphManager=std::unique_ptr<GraphManaging>(new GraphManaging(this));

    _qLayoutLeft->addWidget(_qGraphWindow.get());
    _qLayoutRight->addWidget(_qGraphManager.get());
    _qFinalLayout->addLayout(_qLayoutLeft.get());
    _qFinalLayout->addLayout(_qLayoutRight.get());
    widget->setLayout(_qFinalLayout.get());
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
    this->_qGraphs="For now empty";
    _qFile=std::unique_ptr<QMenu>(menuBar()->addMenu("File"));
    _qSaveAction=std::unique_ptr<QAction>(new QAction("Save"));
    _qOpenAction=std::unique_ptr<QAction>(new QAction("Open"));
    _qSortAction=std::unique_ptr<QAction>(new QAction("Sort graphs"));

    connect(_qSaveAction.get(),SIGNAL(triggered()),
            this,SLOT(save()));
    connect(_qOpenAction.get(),SIGNAL(triggered()),
            this,SLOT(open()));
    connect(_qSortAction.get(),SIGNAL(triggered()),
            _qGraphWindow->getGraphSpace(),SLOT(sortFunc()));

    _qFile->addAction(_qSaveAction.get());
    _qFile->addAction(_qOpenAction.get());
    _qFile->addAction(_qSortAction.get());
}
void MainWindow::save()
{
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("XML Files (*.xml)"));
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
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("XML Files (*.xml)"));
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
            _qGraphWindow->importFromXML(file);
            file.close();
        }

    }
}
MainWindow::~MainWindow()
{
    delete _qUi;
}
void MainWindow::exportToXml(QFile& file)
{
    QTextStream stream(&file);
    stream<<_qGraphWindow->exportToXML();
    stream.flush();
}


