#ifndef MYQLINEEDIT_H
#define MYQLINEEDIT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>

#include <QDebug>   //调试头文件

class MyQLineEdit : public QLineEdit
{
    //自定义类必须加
    Q_OBJECT

public:
    //MyQLineEdit();    //说明父亲是谁
    MyQLineEdit(QWidget *parent = 0);
    //~MyQLineEdit();

    //自定义曹函数格式
public slots:
    void touper() {
        qDebug() << "qt debug";
        this->setText(this->text().toUpper());    //lineEdit文本输出，文本变大写
    }

};

#endif // MYQLINEEDIT_H
