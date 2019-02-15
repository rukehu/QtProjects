#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>

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
    QPushButton *b3;
    MyQLineEdit *le;  //行编辑器


};

#endif // WIDGET_H
