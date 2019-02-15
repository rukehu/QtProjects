#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("新建文本文档.txt - 记事本");
    QObject::connect(ui->newAction, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    QObject::connect(ui->openAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));
    QObject::connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
    QObject::connect(ui->exitAction, SIGNAL(triggered()), this, SLOT(exitFileSlot()));
    QObject::connect(ui->fontAction, SIGNAL(triggered()), this, SLOT(setFontSlot()));
    QObject::connect(ui->colorAction, SIGNAL(triggered()), this, SLOT(setColorSlot()));
    QObject::connect(ui->dataAction, SIGNAL(triggered()), this, SLOT(currentDateSlot()));
    //以下为qt以实现的功能曹，直接连接
    QObject::connect(ui->cancelAction, SIGNAL(triggered()), ui->textEdit, SLOT(selectAll()));
    QObject::connect(ui->cutAction, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    QObject::connect(ui->copyAction, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    QObject::connect(ui->pasteAction, SIGNAL(triggered()), this, SLOT(paste()));
    //QObject::connect(ui->deleteAction, SIGNAL(triggered()), ui->textEdit, SLOT(currentDateSlot()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlot()
{
    //判断当前文本内容是否被改变
    if (ui->textEdit->document()->isModified()) {
        qDebug()<< "current file modified\n";
    } else {
        qDebug()<< "current file not modified\n";
        ui->textEdit->clear();  //清除当前文件
        this->setWindowTitle("新建文本文档.txt - 记事本"); //设置当前文本的头提示信息
    }

}

void MainWindow::openFileSlot()
{
    //get open file name,路径为currentpath当前路径
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath());
    qDebug() << "file direct is ：" << fileName;

    //打开文件
    if (fileName.isEmpty()) {
        QMessageBox::information(this, "Error Message", "Please select a text file");
        return ;
    }
    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);  //只读方式打开文件

    if (ok) {
        QTextStream in(file);   //使用输入文本流
        this->setWindowTitle(fileName);
        ui->textEdit->setText(in.readAll());    //将文本写入texEdit
        file->close();
        /*此处必须手动释放文件指针，文件指针不属于窗口部件，不受顶级窗口部件管理,
         *属于内核指针，窗口指针属于gui类指针，受保护指针所管理
         */
        delete file;
    } else {
        file->close();
        delete file;
        QMessageBox::information(this, "erro message", "file open error" + file->errorString());
    }
}

void MainWindow::saveFileSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, "save file", QDir::currentPath());
    if (fileName.isEmpty()) {
        QMessageBox::information(this, "error message", "please select a txt file");
    } else {
        QFile *file = new QFile;
        file->setFileName(fileName);
        bool ture = file->open(QIODevice::WriteOnly);   //只写的方式打开文件
        if (ture) {
            QTextStream out(file);  //输出流的方式到file
            out << ui->textEdit->toPlainText();//除去textedit中的纯文本
            file->close();
            delete file;
            qDebug() << "save file success!";
        } else {
            QMessageBox::information(this, "error message", "file open error");

        }
    }

}

void MainWindow::exitFileSlot()
{

}

void MainWindow::setFontSlot()
{
    bool ture;
    QFont font = QFontDialog::getFont(&ture, this);
    if (ture) {
        ui->textEdit->setFont(font);
    } else {
        QMessageBox::information(this, "error message", "set color error");
    }
}

void MainWindow::setColorSlot()
{
    QColor color = QColorDialog::getColor(Qt::red, this);
    if (color.isValid()) {
        ui->textEdit->setTextColor(color);
    } else {
        QMessageBox::information(this, "message eror", "color set error");
    }
}

void MainWindow::currentDateSlot()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("yyyy-M-dd hh:mm:ss");  //日期显示格式
    ui->textEdit->append(time);
}
