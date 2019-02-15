#include "widget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include <qabstractitemview.h>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{

    QGraphicsLineItem* lineItem;
    QGraphicsTextItem* textItem;
    QGraphicsPixmapItem* pixmapItem;

/*
    QGraphicsScene* _scene;  // data model
    QGraphicsView* _view;   // show the data model
*/

    _view = new QGraphicsView();

   // _view->setViewport();
   // _view->setBackgroundBrush(Qt::red);

    _view->setScene(_scene = new QGraphicsScene);

    _scene->addItem(lineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(100, 100))));
    _scene->addItem(textItem = new QGraphicsTextItem("Hello world"));
    _scene->addItem(pixmapItem = new QGraphicsPixmapItem(QPixmap(":/new/camera.png")));

    /*妈蛋:加了这一句就能实现拖拽效果了,无语*/
    pixmapItem->setFlags(QGraphicsItem::ItemIsMovable);
    lineItem->setFlags(QGraphicsItem::ItemIsMovable);

    QTransform trans;
    trans.rotate(30);
    textItem->setPos(QPointF(200, 300));
    textItem->setTransform(trans);
    textItem->setFont(QFont("aaa", 50, 700, true));

    pixmapItem->setPos(0, 0);


}


void MyWidget::resizeEvent(QResizeEvent *)
{
    // set the size of _view = MyWidget::size
    _view->setGeometry(QRect(QPoint(0, 0), size()));
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        /*其实,这里这样写:仅是为了测试关系,并且view需要单独show才能显示,并不能updata主窗口引起传布重绘*/
        qDebug()<<"My is Downed";
        _view->setParent(this);
        _view->show();
        //update();
       // repaint();
    }

}


