#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>

#include "myqpushbutton.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    MyQPushButton *b1;
    MyQPushButton *b2;
    QPushButton *b3;
    QLineEdit *le;  //行编辑器


};

#endif // WIDGET_H
