#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollArea>  //容器
#include <QFileDialog>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void selectFileDir();
    void showPicture();


private:
    QLabel *le;
    QLineEdit *led;
    QPushButton *but1;
    QPushButton *but2;
    QScrollArea *sca;

};

#endif // WIDGET_H
