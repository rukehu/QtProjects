#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置输入非明文显示
    ui->passlineEdit->setEchoMode(QLineEdit::Password);
    //QObject::connect(ui->calButton, SIGNAL(clicked()), this, SLOT(calSlot()));
    //QObject::connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(on_loginButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

#if 0
void MainWindow::calSlot()
{
    //toInt 将文本中的字符串转10进制
    int first = ui->firstlineEdit->text().toInt();
    int second = ui->secondlineEdit->text().toInt();
    int result;
    int flag = 1;

    /*判断combo Box悬着器中的字符，此处给出两种思路，
    1、获取文本中的字符串做对比，效率低此处不讨论
    2、使用comboBox的currentIndex下标索引较好
    */

    switch (ui->comboBox->currentIndex())
    {
    case 0: //+
        result  = first + second;
        break;
    case 1:
        result  = first - second;
        break;
    case 2:
        result  = first * second;
        break;
    case 3:
        if (0 == second) {
           flag = 0;
           QMessageBox::information(this, "Result", "The divisor cannot be 0!");
           break;
        }
        result  = first / second;
        break;
    }
    //setTex 将结果设置在文本中,调用Qstring域的number方法将十进制转string
    if (flag) {
        ui->resultlineEdit->setText(QString::number(result));
        QMessageBox::information(this, "Result", QString::number(result));
    }
}
#endif

void MainWindow::on_loginButton_clicked()
{
    if (ui->namelineEdit->text() == "hrk" && ui->passlineEdit->text() == "huruke") {
        QMessageBox::information(this, "Message infomation", "Loging Success");
    } else {
         QMessageBox::information(this, "Message infomation", "name or password error");
    }
}
