#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void newFileSlot(); //新建文件曹
    void openFileSlot();    //打开存在文本文件曹
    void saveFileSlot();    //save file slot
    void exitFileSlot();    //文件退出
    void setFontSlot();
    void setColorSlot();
    void currentDateSlot();
};

#endif // MAINWINDOW_H
