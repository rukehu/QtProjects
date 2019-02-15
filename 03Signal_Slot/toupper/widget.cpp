#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    le = new QLineEdit(this);
    btn = new QPushButton("OK", this);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le);
    vbox->addWidget(btn);
    setLayout(vbox);

    connect(btn, SIGNAL(clicked()), this, SLOT(btnPush()));


}

Widget::~Widget()
{

}
