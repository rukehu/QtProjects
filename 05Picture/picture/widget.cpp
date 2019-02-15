#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

Widget::Widget(QWidget *parent) : QWidget(parent)
{

    sca = new QScrollArea(this);
    le = new QLabel(this);
    le->setScaledContents(true);    //自动放大显示

    le->setPixmap(QPixmap(":/img/map.png"));
    le->setFixedSize(640, 480); //设置固定大小
    sca->setWidget(le); //将图片标签放进容器

    but1 = new QPushButton("打开", this);
    but2 = new QPushButton("确定", this);
    //but1->setDisabled(true);    //关闭按键点击
    led = new QLineEdit(this);
    //led->setEchoMode(QLineEdit::Password);//密码方式回

    QHBoxLayout *scaBox = new QHBoxLayout;
    scaBox->addWidget(le);
    sca->setLayout(scaBox);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(but1);
    hbox->addWidget(but2);
    hbox->addStretch();

    QVBoxLayout *vbox = new QVBoxLayout;
    //vbox->addWidget(sca);
    vbox->addWidget(sca);
    vbox->addWidget(led);
    vbox->addLayout(hbox);

    this->setLayout(vbox);

    connect(but1, SIGNAL(clicked(bool)), this, SLOT(selectFileDir()));
    connect(but2, SIGNAL(clicked(bool)), this, SLOT(showPicture()));

}

Widget::~Widget()
{

}

void Widget::selectFileDir()
{
    //打开文件，指定打开目录，指定过录文件
    QString fileDir = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                                "../",
                                                                tr("Images (*.png *.xpm *.jpg *.bmp)"));
    led->setText(fileDir);
}
void Widget::showPicture()
{
    QString fileDir = led->text();
    le->setPixmap(QPixmap(fileDir));
}
