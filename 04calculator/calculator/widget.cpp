#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QString>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("多功能计算器");
    this->setMinimumSize(400, 200);
    this->setMaximumSize(400, 200);
    op1 = new QLineEdit(this);
    op2 = new QLineEdit(this);
    result = new QLineEdit(this);
    op1->setAlignment(Qt::AlignCenter);
    op2->setAlignment(Qt::AlignCenter);
    result->setAlignment(Qt::AlignCenter);
    //result->setEnabled(false);
    result->setFocusPolicy(Qt::NoFocus);

    symbol = new QComboBox(this);
    symbol->addItem("+");
    symbol->addItem("-");
    symbol->addItem("*");
    symbol->addItem("/");
    symbol->addItem("%");

    equal = new QLabel("=", this);


    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addWidget(op1);
    hbox1->addWidget(symbol);
    hbox1->addWidget(op2);
    hbox1->addWidget(equal);
    hbox1->addWidget(result);

    QHBoxLayout *hbox2 = new QHBoxLayout;
    btn1 = new QPushButton("计算", this);
    btn2 = new QPushButton("清除", this);

    hbox2->addStretch();
    hbox2->addWidget(btn1);
    hbox2->addWidget(btn2);
    hbox2->addStretch();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    setLayout(vbox);

    connect(btn1, SIGNAL(clicked(bool)), this, SLOT(calculatorResult()));
    connect(btn2, SIGNAL(clicked(bool)), this, SLOT(clearText()));
}

Widget::~Widget()
{

}

void Widget::calculatorResult()
{
    QString str1 = op1->text();
    QString str2 = op2->text();
    int num, dat1, dat2;
    bool ok = true;
    if (!str1.isEmpty() && !str2.isEmpty()) {
        dat1 = str1.toInt();
        dat2 = str2.toInt();
        switch (symbol->currentIndex())
        {
            case 0: {
                num = dat1 + dat2;
                break;
            }
            case 1: {
                num = dat1 - dat2;
                break;
            }
            case 2: {
                num = dat1 * dat2;
                break;
            }
            case 3: {
                if (0 != dat1){
                    num = dat1 / dat2;
                } else {
                    QMessageBox::information(this, "错误信息", "除数不能为0");
                    ok = false;
                }
                break;
            }
            case 4: {
            if (0 != dat1){
                num = dat1 % dat2;
            } else {
                QMessageBox::information(this, "错误信息", "除数不能为0");
                ok = false;
            }
                break;
            }
        }

        if (ok) {
            result->setText(QString::number(num));    //整数转字符串默认十进制
        }
    } else {
        QMessageBox::information(this, "错误信息", "计算数不能为空");
    }
}

void Widget::clearText()
{
    op1->clear();
    op2->clear();
    result->clear();
}
