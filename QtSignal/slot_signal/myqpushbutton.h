#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class myQPushButton : public QPushButton
{
    Q_OBJECT
public:
    myQPushButton(const QString &,QWidget * parent = 0);
    //定义激发的信号
signals:
    void sendsig(QString);   //emit 信号不能被调用，只能被激发

};

#endif // MYQPUSHBUTTON_H
