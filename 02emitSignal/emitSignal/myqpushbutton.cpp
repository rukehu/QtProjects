#include "myqpushbutton.h"

MyQPushButton::MyQPushButton(const QString &text, QWidget * parent) : QPushButton(parent)
{
    setText(text);
    connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}

