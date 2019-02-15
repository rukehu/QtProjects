#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void calculatorResult();
    void clearText();


private:
    QLineEdit *op1, *op2, *result;
    QLabel *equal;
    QComboBox *symbol;
    QPushButton *btn1, *btn2;
};

#endif // WIDGET_H
