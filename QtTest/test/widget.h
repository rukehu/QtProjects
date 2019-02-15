#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushbutton>
#include <QLineEdit>    //行编辑器

#include "myqlineedit.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *b1;
    QPushButton *b2;
    MyQLineEdit *le;    //自定义类
};

#endif // WIDGET_H
