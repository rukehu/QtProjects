#include "widget.h"
#include <QVBoxLayout>  //垂直布局
#include <QHBoxLayout>  //水平布局
#include <QGridLayout>  //网状布局
#include "myqpushbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //步骤一：创建GUI
    this->setMinimumSize(100, 200);

    b1 = new myQPushButton("ok", this);  //显示在父窗口this
    b2 = new myQPushButton("cancel", this);
    le = new QLineEdit(this);

    /*布局类垂直布局，依次垂直布局*/
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(b1);
    vbox->addWidget(b2);
    this->setLayout(vbox);  //布局在this窗口上

    //步骤二：信号与曹
    //touper 自定义信号曹
    connect(b1, SIGNAL(sendsig(QString)), le, SLOT(setText(QString)));


}

Widget::~Widget()
{
    //所有依附于this的部件，均会随this部件销毁，C++自动释放类存

}
