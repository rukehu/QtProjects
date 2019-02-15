#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>  //消息对话框

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //元对象编辑器宏，会启用元对象编辑器
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void calSlot();
};

#endif // MAINWINDOW_H
