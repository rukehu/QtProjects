#include "widget.h"
#include <QVBoxLayout>  //垂直布局
#include <QHBoxLayout>  //水平布局
#include <QGridLayout>  //网状布局

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //步骤一：创建GUI
    this->setMinimumSize(100, 200);
    //this->setMaximumSize(700, 768);
    //b = new QPushButton;
    le = new MyQLineEdit(this);
    b1 = new QPushButton("ok", this);  //显示在父窗口this
    b2 = new QPushButton("cancel", this);
    //b->show();    //子窗口依附于父窗口显示

#if 1
    /*布局类垂直布局，依次垂直布局*/
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(b1);
    vbox->addWidget(b2);
    this->setLayout(vbox);  //布局在this窗口上
#endif
#if 0
    /*水平布局*/
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(le);
    hbox->addWidget(b1);
    hbox->addWidget(b2);
    this->setLayout(hbox);
#endif
#if 0
    /*网状布局*/
    QGridLayout *gbox = new QGridLayout;
    gbox->addWidget(le, 0, 0);  //一行一列，行列由参数决定
    gbox->addWidget(b1, 1, 1, 2, 2);
    gbox->addWidget(b2, 2, 2);
    this->setLayout(gbox);
#endif
    //步骤二：信号与曹
    //当点击clicedp1时，发送型号，连接到le标签，曹为清除
    connect(b2, SIGNAL(clicked()), le, SLOT(clear()));
    //touper 自定义曹
    connect(b1, SIGNAL(clicked()), le, SLOT(touper()));


}

Widget::~Widget()
{
    //所有依附于this的部件，均会随this部件销毁，C++自动释放类存

}
