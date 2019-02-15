#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void btnPush() {
        le->setText(le->text().toUpper());
    }

private:
    QLineEdit *le;
    QPushButton *btn;
};

#endif // WIDGET_H
