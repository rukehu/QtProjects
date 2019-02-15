#ifndef WIDGET_H
#define WIDGET_H

#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>



//#include <QPrintPreviewDialog>  // preview
//#include <QPrintDialog>         // print

// display scene
#include <QGraphicsView>

#include <QTimer>
#include <QDateTime>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
  //  void paintEvent(QPaintEvent *);

    QGraphicsScene* _scene;  // data model
    QGraphicsView* _view;   // show the data model

    void resizeEvent(QResizeEvent *);

    void mousePressEvent(QMouseEvent *event);


signals:

public slots:
   // void slotPaintRequested(QPrinter*);


};
#endif // WIDGET_H
