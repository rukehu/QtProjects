#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushbutton>
#include <QLineEdit>    //行编辑器

#include "myqpushbutton.h"



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    myQPushButton *b1;
    myQPushButton *b2;
    QLineEdit *le;    //自定义类
};

#endif // WIDGET_H
