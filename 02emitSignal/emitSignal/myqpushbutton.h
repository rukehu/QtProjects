#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>

class MyQPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyQPushButton(const QString &text, QWidget * parent = 0);

public slots:
    void buttonClicked() {
        emit sendtex(text());   //tex()是按键身上的文本
    }

signals:
    void sendtex(QString); //emit signal
};

#endif // MYQPUSHBUTTON_H
