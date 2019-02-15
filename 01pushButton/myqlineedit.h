#ifndef MYQLINEEDIT_H
#define MYQLINEEDIT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>

class MyQLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyQLineEdit(QWidget * parent = 0);

public slots:
    void touper();
};

#endif // MYQLINEEDIT_H
