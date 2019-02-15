#include "widget.h"
#include <QVBoxLayout>  //垂直布局
#include <QHBoxLayout>  //水平布局
#include <QGridLayout>  //网状布局



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this->setMinimumSize(640, 480); //设置this窗口的最小大小

    b1 = new QPushButton("OK", this);//按键依附于this窗口
    b2 = new QPushButton("Cancel", this);
    b3 = new QPushButton("up", this);
    le = new MyQLineEdit(this);
 #if 1
    //布局layout，按先后添加关系布局
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(b1);    //将需要布局的控件放入该布局
    vbox->addWidget(b2);
    vbox->addWidget(b3);

    this->setLayout(vbox);      //设置主窗口的布局
#else   //网状布局
    QGridLayout *gbox = new QGridLayout;
    gbox->addWidget(le, 0, 0, 1, 1);   //0行0裂占1行1格
    gbox->addWidget(b1, 1, 1, 1, 1);
    gbox->addWidget(b2, 2, 1, 1, 1);
    this->setLayout(gbox);
#endif

    //连接信号与曹
    connect(b2, SIGNAL(clicked()), le, SLOT(clear()));
    connect(b3, SIGNAL(clicked()), le, SLOT(touper()));



}

Widget::~Widget()
{

}
