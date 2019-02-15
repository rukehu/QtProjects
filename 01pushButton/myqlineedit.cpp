#include "myqlineedit.h"
#include <QDebug>

MyQLineEdit::MyQLineEdit(QWidget * parent) : QLineEdit(parent)
{

}

void MyQLineEdit::touper()
{
    this->setText(this->text().toUpper());

    qDebug() << "slot is connect";
}

