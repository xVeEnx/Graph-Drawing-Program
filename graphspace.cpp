#include "graphspace.h"
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QtXml>
#include <iostream>
//#include <iostream>

graphSpace::graphSpace(QWidget *parent,QSize size)
    : QWidget{parent},_iWidth{300},_iSpace{40},_iScale{1}
{
    setFixedSize(size);
    double height=size.height()/10;

    for(int i=10; i>=0; i--)
    {
        _qLine.push_back(QLine(0,height*i,size.width(),height*i));
    }

}
void graphSpace::addingProcedure(int graphHeight,QColor color,QStaticText label)
{
    int orgHeight=graphHeight;
    if(graphHeight<1) return;
    if(graphHeight*_iScale>this->height()) heightChanging(graphHeight);
    int numOfGraphs= graphsVect.size();
    int height=QWidget::height();

    graphsVect.push_back(QRect(_iSpace*numOfGraphs+_iWidth*numOfGraphs,height,_iWidth,-(graphHeight*_iScale)));
    graphsVect[graphsVect.size()-1].setQText(label);
    graphsVect[graphsVect.size()-1].setQColor(color);
    graphsVect[graphsVect.size()-1].setOriginalHeight(orgHeight);

    emit layoutSetting();
    update();
}
void graphSpace::addGraphs()
{
    GraphManaging* manager = qobject_cast<GraphManaging* >(sender()->parent());
    int graphHeight=(manager->getGraphHeight()).toInt();
    QColor color=manager->getGraphColor();
    QStaticText label=QStaticText(manager->getGraphName());

    addingProcedure(graphHeight,color,label);
    manager->clearGraphHeight(graphsVect.size()+1);


}
void graphSpace::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::gray);
    if(graphsVect.size()!=0)if(graphsVect[graphsVect.size()-1].getQRectangle().x()+_iWidth>this->width()) widthChanging();
    //if last rect is not fitting on screen turn widthChanging which make space between graphs and graph width smaller
    for(int i=0; i<_qLine.size(); i++) painter.drawLine(_qLine[i]);

    painter.setPen(Qt::black);
    for(int i=0; i<graphsVect.size(); i++) painter.fillRect(graphsVect[i].getQRectangle(),graphsVect[i].getQColor());

    for(int i=0; i<graphsVect.size(); i++) painter.drawRect(graphsVect[i].getQRectangle());

}

void graphSpace::refreshGraphs()
{//function that change width of graph if it`s not fitting on screen
    int height=QWidget::height();
    for(int i=0; i<graphsVect.size(); i++)
    {
        int temp=graphsVect[i].height();
        graphsVect[i].setBottomLeft(QPoint(_iSpace*i+_iWidth*i,height));
        graphsVect[i].setWidth(_iWidth);
        graphsVect[i].setHeight(temp);
    }
    update();
}
void graphSpace::widthChanging()
{
    int i=0;

    if(_iSpace>5) _iSpace/=1.5;//if graphs dont fit on screen make smaller spaces between them if it`s not enough change width
    while((_iWidth*(graphsVect.size()+1)+_iSpace*(graphsVect.size()+1))>=size().width())
    {
        i++;
        _iWidth=_iWidth/1.3;// width of rect/2 HERE YOU CAN CHANGE DIVIDER OF WIDTH
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
    for(int i=start;i<end;++i){
        if(v[i].height()<v[pivot].height()){
            swapRect(v,i,j);
            ++j;
        }
    }
    swapRect(v,j,pivot);
    return j;
}
void graphSpace::sort(QVector<GRect>& vect,int left, int right)
{
    if(left<right){
            int p = Partition(vect,left,right);
            sort(vect,left,p-1);
            sort(vect,p+1,right);
        }
}
void graphSpace::sortFunc()
{
    sort(graphsVect,0,graphsVect.size()-1);
    if(graphsVect.size()>1) emit graphSorted();
    refreshGraphs();
}

QVector<GRect> graphSpace::getGRectVect()
{
    return graphsVect;
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
void graphSpace::heightChanging(int height)
{
    int screenHeight=this->height();
    int tempHeight=height;
    qDebug()<<"_iScale= :"<<_iScale;
    while(height>screenHeight) {
        qDebug()<<"height w petli: "<<height;
        height=tempHeight;
        qDebug()<<"height w petli2: "<<height;

        _iScale/=2;
        height*=_iScale;
    }
    qDebug()<<"_iScale po petli= :"<<_iScale;
    for(int i=0;i<graphsVect.size();i++)
    {
        graphsVect[i].setHeight(-(graphsVect[i].getOriginalHeight()*_iScale));
        qDebug()<<"org height * iscale= "<<graphsVect[i].getOriginalHeight()*_iScale<<"dla i= "<<i;
    }
        qDebug()<<" height="<<height;
    emit changeScale();
}

QString graphSpace::exportToXML()
{
    QDomDocument document;
    for(int i=0;i<graphsVect.size();i++)
          {
        QDomElement root= document.createElement("graph");
        QDomElement label=document.createElement("label");
        QDomElement height=document.createElement("height");
        QDomElement color=document.createElement("color");
        label.setAttribute("label",graphsVect[i].getQText().text());
        height.setAttribute("height",-graphsVect[i].height());
        color.setAttribute("color",graphsVect[i].getQColor().name());
        document.appendChild(root);
        root.appendChild(label);
        root.appendChild(height);
        root.appendChild(color);
          }
   return document.toString();
}
void graphSpace::importFromXML(QFile& file)
{
        QDomDocument document;
        document.setContent(file.readLine());
        qDebug()<<document.toString();

         QDomElement root=document.firstChildElement();

        QStaticText label=QStaticText(listElements(root,"label","label"));
        if(label.text()=="ERROR")return;

        if(listElements(root,"height","height")=="ERROR")return;
        int height=listElements(root,"height","height").toInt();


         if(listElements(root,"color","color")=="ERROR")return;
        QColor color;
        color.setNamedColor(listElements(root,"color","color"));

        addingProcedure(height,color,label);


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
