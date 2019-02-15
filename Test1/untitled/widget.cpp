#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)  //ui 表示界面的对象
{
    ui->setupUi(this);

    this->setMaximumSize(392, 171);
    this->setMinimumSize(392, 171);
    //当按下回车按钮时returnPressed，连接确定按钮选择的曹
    QObject::connect(ui->cmdLineEdit, SIGNAL(returnPressed()), this, SLOT(on_submitButton_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_submitButton_clicked()
{
    //进程对象
    QProcess *process = new QProcess;
    //得到ui cmdLineEdit中的文本
    QString startProgram = ui->cmdLineEdit->text();
    //trimmed去掉字符串中特别的字符 ' ' , '\n' , '\r'...
    process->start(startProgram.trimmed());
    ui->cmdLineEdit->clear();
    this->close();
}

void Widget::on_browserButton_clicked()
{

}
