#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextStream>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("无标题 - 记事本");

    QObject::connect(ui->newFile, SIGNAL(triggered(bool)), this, SLOT(newFileSlots()));
    QObject::connect(ui->openFile, SIGNAL(triggered(bool)), this, SLOT(openFileSlots()));
    QObject::connect(ui->saveFile, SIGNAL(triggered(bool)), this, SLOT(saveFileSlots()));
    QObject::connect(ui->saveAs, SIGNAL(triggered(bool)), this, SLOT(saveAsSlots()));
    QObject::connect(ui->exitFile, SIGNAL(triggered(bool)), this, SLOT(exitSlots()));





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlots()
{
    if (ui->textEdit->document()->isModified()) {   //如果当前textEdit内容改变
        QString fileName = this->windowTitle();
        if (fileName == QString("无标题 - 记事本")) {  //当前文件并未保存过
            Dialog dialog;
            dialog.setText(tr("是否将更改保存到 - 无标题?"));
            dialog.exec();
            if (dialog.getSaveFlag()) {
                fileName = QFileDialog::getSaveFileName(this, tr("另存为"), "*.txt", tr("(*.txt)"));
                if (!fileName.isEmpty()) {
                    QFile file;
                    file.setFileName(fileName);
                    file.open(QIODevice::WriteOnly);
                    QTextStream out(&file);
                    out << ui->textEdit->toPlainText(); //去除纯文本
                    file.close();
                    ui->textEdit->clear();
                    this->setWindowTitle(fileName);
                    ui->textEdit->document()->setModified(false);
                } else {
                    return;
                }
            } else if (dialog.getNoSaveFlag()) {
                ui->textEdit->clear();
                this->setWindowTitle("无标题 - 记事本");
                ui->textEdit->document()->setModified(false);
            } else {
                return;
            }
        } else {    //该文件已经保存过，直接清空文件，并写入文本
            QFile file(getFileDir());
            file.open(QFile::WriteOnly | QFile::Truncate);
            file.close();
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
            ui->textEdit->clear();
            this->setWindowTitle("无标题 - 记事本");
            ui->textEdit->document()->setModified(false);
        }
    } else {
        ui->textEdit->clear();
        this->setWindowTitle("无标题 - 记事本");
    }
}

void MainWindow::openFileSlots()
{
    if (ui->textEdit->document()->isModified()) {   //如果当前文件修改过
        QString fileName = this->windowTitle();
        Dialog dialog;
        if (fileName == QString("无标题 - 记事本")) {
            dialog.setText(tr("是否将更改保存到 - 无标题?"));
        } else {
             dialog.setText(tr("是否将更改保存到\n\r") + getFileDir() + "?");
        }
        dialog.exec();

        if (dialog.getSaveFlag()) {                 //点击保存按钮
            //qDebug() << "file name:" << this->windowTitle();
            if (fileName == QString("无标题 - 记事本")) {
                QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), "", tr("(*.txt)"));
                QFile file(fileName);
                file.open(QIODevice::WriteOnly);
                QTextStream out(&file);
                out << ui->textEdit->toPlainText();
                file.close();
                ui->textEdit->document()->setModified(false);
                this->setWindowTitle(fileName);
                setFileDir(fileName);

            } else {
                QFile file(getFileDir());
                file.open(QFile::WriteOnly | QFile::Truncate);
                file.close();
                file.open(QIODevice::WriteOnly);
                QTextStream out(&file);
                out << ui->textEdit->toPlainText();
                file.close();
                fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                                "",
                                                                tr("文本文档(*.txt)"));
                if (!fileName.isEmpty()) {
                    QFile file(fileName);
                    setFileDir(fileName);
                    if (file.open(QIODevice::ReadOnly)) {
                        QTextStream in(&file);
                        this->setWindowTitle(fileName);
                        ui->textEdit->clear();
                        ui->textEdit->setText(in.readAll());
                        file.close();
                        ui->textEdit->document()->setModified(false);
                    }
                }
            }
        } else if (dialog.getNoSaveFlag()) {    //不保存文件
            QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                            "",
                                                            tr("文本文档(*.txt)"));
            if (!fileName.isEmpty()) {
                QFile file(fileName);
                setFileDir(fileName);
                if (file.open(QIODevice::ReadOnly)) {
                    QTextStream in(&file);
                    this->setWindowTitle(fileName);
                    ui->textEdit->clear();
                    ui->textEdit->setText(in.readAll());
                    file.close();
                    ui->textEdit->document()->setModified(false);
                }
            }
        }
    } else {    //文件没改变
        QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                        "",
                                                        tr("文本文档(*.txt)"));
         if (!fileName.isEmpty()) {
             QFile file(fileName);
             setFileDir(fileName);
             //qDebug() << "file dir = " << fileName;
             if (file.open(QIODevice::ReadOnly)) {
                 QTextStream in(&file);
                 this->setWindowTitle(fileName);
                 ui->textEdit->clear();
                 ui->textEdit->setText(in.readAll());
                 file.close();
             }
         }
    }
}

void MainWindow::saveFileSlots()
{
    //qDebug() << "save file";
    QString fileName = this->windowTitle();
    if (fileName == QString("无标题 - 记事本")) {
        fileName = QFileDialog::getSaveFileName(this, tr("另存为"), "", tr("(*.txt)"));
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
            ui->textEdit->document()->setModified(false);
            this->setWindowTitle(fileName);
            setFileDir(fileName);
        }

    } else {
        if (ui->textEdit->document()->isModified()) {
            QFile file(getFileDir());
            file.open(QFile::WriteOnly | QFile::Truncate);
            file.close();
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
            ui->textEdit->document()->setModified(false);
        }
    }
}
void MainWindow::saveAsSlots()
{
    if (ui->textEdit->document()->isModified()) {
        QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), "", tr("(*.txt)"));
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
            ui->textEdit->document()->setModified(false);
            this->setWindowTitle(fileName);
            setFileDir(fileName);
        }
    }

}
void MainWindow::exitSlots()
{
    if (!(ui->textEdit->document()->isModified())) {
        QCoreApplication::quit();
    }
    QString fileName = this->windowTitle();
    if (fileName == QString("无标题 - 记事本")) {
        Dialog dialog;
        dialog.setText(tr("是否将更改保存到 - 无标题?"));
        dialog.exec();
        if (dialog.getSaveFlag()) {
            fileName = QFileDialog::getSaveFileName(this, tr("保存"), "", tr("(*.txt)"));
            if (!fileName.isEmpty()) {
                QFile file(fileName);
                file.open(QIODevice::WriteOnly);
                QTextStream out(&file);
                out << ui->textEdit->toPlainText();
                file.close();
            } else {
                return;
            }
        } else if (dialog.getCancelFlag()) {
            return;
        }

    } else {
        QFile file(getFileDir());
        file.open(QFile::WriteOnly | QFile::Truncate);
        file.close();
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
    }

    QCoreApplication::quit();
}

void MainWindow::cancelSlots()
{

}
void MainWindow::cutSlots()
{

}
void MainWindow::copySlots()
{

}
void MainWindow::pasteSlots()
{

}
void MainWindow::deleteSlots()
{

}

void MainWindow::lookupSlots()
{

}
void MainWindow::findNextSlots()
{

}
void MainWindow::replaceSlots()
{

}
void MainWindow::gotoSlots()
{

}
void MainWindow::checkAllSlots()
{

}
void MainWindow::dateSlots()
{

}

void MainWindow::wordWrapSlots()
{

}
void MainWindow::fontSlots()
{

}
void MainWindow::colorSlots()
{

}

void MainWindow::statusSlots()
{

}

void MainWindow::helpViewSlots()
{

}
void MainWindow::aboutNoteSlots()
{

}

void MainWindow::setFileDir(QString dir)
{
    m_fileDir = dir;
}
QString MainWindow::getFileDir(void)
{
    return m_fileDir;
}

Dialog::Dialog(QWidget * parent) : QDialog(parent)
{
    m_save = false;
    m_noSave = false;
    m_cancel = false;
    this->setWindowTitle("记事本");
    this->setMinimumSize(300, 100);
    this->setMaximumSize(300, 100);
    this->setWindowFlags(Qt::WindowCloseButtonHint);


    m_label = new QLabel(this);
    m_saveBut = new QPushButton("保存", this);
    m_noSaveBut = new QPushButton("不保存", this);
    m_cancelBut = new QPushButton("取消", this);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(m_saveBut);
    hbox->addWidget(m_noSaveBut);
    hbox->addWidget(m_cancelBut);

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(m_label);
    vbox->addLayout(hbox);
    this->setLayout(vbox);

    QObject::connect(m_saveBut, SIGNAL(clicked(bool)), this, SLOT(saveButton()));
    QObject::connect(m_noSaveBut, SIGNAL(clicked(bool)), this, SLOT(noSaveButton()));
    QObject::connect(m_cancelBut, SIGNAL(clicked(bool)), this, SLOT(cancelButton()));
}

Dialog::~Dialog()
{

}

void Dialog::setText(QString text)
{
    m_label->setText(text);
}

void Dialog::saveButton()
{
    m_save = true;
    this->reject();
}
void Dialog::noSaveButton()
{
    m_noSave = true;
    this->reject();
}
void Dialog::cancelButton()
{
    m_cancel = true;
    this->reject();
}

bool Dialog::getSaveFlag()
{
    return m_save;
}
bool Dialog::getNoSaveFlag()
{
    return m_noSave;
}
bool Dialog::getCancelFlag()
{
    return m_cancel;
}

