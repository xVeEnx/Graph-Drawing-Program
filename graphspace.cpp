#include "graphspace.h"
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QtXml>
#include <iostream>
//#include <iostream>

graphSpace::graphSpace(QWidget *parent,QSize size)
    : QWidget{parent},_iGraphWidth{300},_iSpace{40},_iScale{1}
{
    setFixedSize(size);
    double height=size.height()/10;

    for(int i=10; i>=0; i--)
    {
        _qLine.push_back(QLine(0,height*i,size.width(),height*i)); //draw "scale" lines
    }

}
void graphSpace::addingProcedure(int graphHeight,QColor color,QStaticText label)
{
    int orgHeight=graphHeight;
    if(graphHeight<1) return;
    if(_qGraph.size()>1000) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Osiągnięto maksymalną liczbe wykresów!");
        messageBox.setFixedSize(500,200);
    }
    if(graphHeight*_iScale>this->height()) heightChanging(graphHeight);
    int numOfGraphs= _qGraph.size();
    int screenHeight=QWidget::height();

    int graphLeftPos=_iSpace*numOfGraphs+_iGraphWidth*numOfGraphs;
    int graphBottomPos=screenHeight;  //positions of graph
    int graphWidth= _iGraphWidth;
    int finalGraphHeight =-(graphHeight*_iScale);

    _qGraph.push_back(QRect(graphLeftPos,graphBottomPos,graphWidth,finalGraphHeight));
    _qGraph[_qGraph.size()-1].setQText(label);
    _qGraph[_qGraph.size()-1].setQColor(color);
    _qGraph[_qGraph.size()-1].setOriginalHeight(orgHeight);

    emit layoutSetting();
    update();
}
void graphSpace::addGraphs()
{
    GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
    int graphHeight=(manager->getGraphHeight()).toInt();

    QColor graphColor=manager->getGraphColor();
    QStaticText graphLabel=QStaticText(manager->getGraphName());

    addingProcedure(graphHeight,graphColor,graphLabel);
    manager->clearGraphHeight(_qGraph.size()+1); //clear label input window


}
void graphSpace::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::gray);
    if(_qGraph.size()!=0) if(_qGraph[_qGraph.size()-1].getQRectangle().x()+_iGraphWidth>this->width()) widthChanging();
    //if last rect is not fitting on screen turn widthChanging which make space between graphs and graph width smaller
    for(int i=0; i<_qLine.size(); i++) painter.drawLine(_qLine[i]);

    painter.setPen(Qt::black);
    for(int i=0; i<_qGraph.size(); i++) painter.fillRect(_qGraph[i].getQRectangle(),_qGraph[i].getQColor());

    for(int i=0; i<_qGraph.size(); i++) painter.drawRect(_qGraph[i].getQRectangle());

}

void graphSpace::refreshGraphs()
{//function that change width of graph if it`s not fitting on screen
    int screenHeight=QWidget::height();
    for(int i=0; i<_qGraph.size(); i++)
    {
        int graphHeight=_qGraph[i].height();
        _qGraph[i].setBottomLeft(QPoint(_iSpace*i+_iGraphWidth*i,screenHeight));
        _qGraph[i].setWidth(_iGraphWidth);
        _qGraph[i].setHeight(graphHeight);
    }
    update();
}
void graphSpace::widthChanging()
{
    int i=0;
    if(_iSpace>5) _iSpace/=1.5; //if graphs dont fit on screen make smaller spaces between them if it`s not enough change width
    while((_iGraphWidth*(_qGraph.size()+1)+_iSpace*(_qGraph.size()+1))>=size().width())
    {
        i++;
        _iGraphWidth=_iGraphWidth/1.3;// width of rect/2 HERE YOU CAN CHANGE DIVIDER OF WIDTH
        refreshGraphs();
    }
    emit layoutSetting(); //emiting signal that fit labels under graphs to graphs

}
void graphSpace::swapRect(QVector<GRect>& qVec, int i,int j)
{
    if(i==j) return;
    GRect qR=qVec[i];
    qVec[i]=qVec[j];
    qVec[j]=qR;
}
int graphSpace::Partition(QVector<GRect> &v, int start, int end)
{
    int pivot = end;
    int j = start;
    for(int i=start; i<end; ++i) {
        if(v[i].height()<v[pivot].height()) {
            swapRect(v,i,j);
            ++j;
        }
    }
    swapRect(v,j,pivot);
    return j;
}
void graphSpace::sort(QVector<GRect>& vect,int left, int right)
{
    if(left<right) {
        int p = Partition(vect,left,right);
        sort(vect,left,p-1);
        sort(vect,p+1,right);
    }
}
void graphSpace::sortFunc()
{
    sort(_qGraph,0,_qGraph.size()-1);
    if(_qGraph.size()>1) emit graphSorted();
    refreshGraphs();
}

QVector<GRect> graphSpace::getGRectVect()
{
    return _qGraph;
}
double graphSpace::getScale()
{
    return _iScale;
}

QVector<QStaticText> graphSpace::getQName()
{
    //return _qName;
    return QVector<QStaticText>();
}
int graphSpace::getSpace()
{
    return _iSpace;
}
void graphSpace::heightChanging(int graphHeight)
{
    int screenHeight=this->height();
    int tempGraphHeight=graphHeight;
    while(graphHeight>screenHeight) {
        graphHeight=tempGraphHeight;
        _iScale/=2;
        graphHeight*=_iScale;
    }

    for(int i=0; i<_qGraph.size(); i++)
    {
        _qGraph[i].setHeight(-(_qGraph[i].getOriginalHeight()*_iScale));
    }

    emit changeScale();
}

QString graphSpace::exportToXML()
{
    QDomDocument document;
    for(int i=0; i<_qGraph.size(); i++)
    {
        QDomElement root= document.createElement("graph");
        QDomElement label=document.createElement("label");
        QDomElement height=document.createElement("height");
        QDomElement color=document.createElement("color");
        label.setAttribute("label",_qGraph[i].getQText().text());
        height.setAttribute("height",_qGraph[i].getOriginalHeight());
        color.setAttribute("color",_qGraph[i].getQColor().name());
        document.appendChild(root);
        root.appendChild(label);
        root.appendChild(height);
        root.appendChild(color);
    }
    return document.toString();
}
void graphSpace::importFromXML(QFile& file)
{
    _qGraph.clear();
    QDomDocument document;
    std::string s=file.readAll().toStdString();

    while(s.size()>10)
    {
        document.setContent(QString::fromStdString(s));
        int pos= s.find("/graph>\n")+8;
         s= s.substr(pos);
        QDomElement root=document.firstChildElement();

        QStaticText label=QStaticText(listElements(root,"label","label"));
        if(label.text()=="ERROR") return;

        if(listElements(root,"height","height")=="ERROR") return;
        int height=listElements(root,"height","height").toInt();


        if(listElements(root,"color","color")=="ERROR") return;
        QColor color;
        color.setNamedColor(listElements(root,"color","color"));

        addingProcedure(height,color,label);
    }
}

QString graphSpace::listElements(QDomElement root,QString tagname,QString attribute)
{
    QDomNodeList items=root.elementsByTagName(tagname);
    QDomNode itemNode=items.at(0);
    if(itemNode.isElement())
    {
        QDomElement itemEle=itemNode.toElement();
        return itemEle.attribute(attribute);
    }
    else return QString("ERROR");
}
