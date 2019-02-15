#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsLineItem>
#include <QPointF>
#include <QLineF>
#include <QVBoxLayout>
#include <QLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setMinimumSize(1360, 768);
    QVBoxLayout *vbox = new QVBoxLayout(this);
    this->setLayout(vbox);


    QGraphicsScene *scene = new QGraphicsScene();
    //QGraphicsView *view = new QGraphicsView;
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setMinimumSize(640, 480);
    //ui->graphicsView->setGeometry(200, 100, 640, 480);

    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(":imm/map.png"));

    //QGraphicsLineItem *lineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(100, 100)));


    scene->addItem(item);

    item->setFlags(QGraphicsItem::ItemIsMovable);
    item->setPos(0, 0);



}

Widget::~Widget()
{
    delete ui;
}
