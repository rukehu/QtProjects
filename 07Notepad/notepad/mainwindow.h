#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setFileDir(QString dir);
    QString getFileDir(void);

public slots:
    void newFileSlots();
    void openFileSlots();
    void saveFileSlots();
    void saveAsSlots();
    void exitSlots();

    void cancelSlots();
    void cutSlots();
    void copySlots();
    void pasteSlots();
    void deleteSlots();

    void lookupSlots();
    void findNextSlots();
    void replaceSlots();
    void gotoSlots();
    void checkAllSlots();
    void dateSlots();

    void wordWrapSlots();
    void fontSlots();
    void colorSlots();

    void statusSlots();

    void helpViewSlots();
    void aboutNoteSlots();


private:
    Ui::MainWindow *ui;
    QString m_fileDir;

};

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget * parent = 0);
    ~Dialog();

    void setText(QString text);

public slots:
    void saveButton();
    void noSaveButton();
    void cancelButton();
    bool getSaveFlag();
    bool getNoSaveFlag();
    bool getCancelFlag();

private:
    QLabel *m_label;
    QPushButton *m_saveBut;
    QPushButton *m_noSaveBut;
    QPushButton *m_cancelBut;

    bool m_save;
    bool m_noSave;
    bool m_cancel;
};

#endif // MAINWINDOW_H
