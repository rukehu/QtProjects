#include "widget.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app (argc,argv);

    MyWidget w;
    w.showMaximized();
    return app.exec();
}
