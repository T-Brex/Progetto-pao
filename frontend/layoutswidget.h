#ifndef LAYOUTSWIDGET_H
#define LAYOUTSWIDGET_H

#include "qgridlayout.h"
#include <QStackedWidget>

class LayoutsWidget : public QStackedWidget
{
    Q_OBJECT
public:
    /*
    QWidget *sensWidget;
    QGridLayout *sensLayout;
    QWidget *simuWidget;
    QHBoxLayout *simuLayout;
    //QStackedWidget *layoutsWidget;
*/
    LayoutsWidget(QWidget * parent = nullptr);
    LayoutsWidget(QVector<QWidget*> frame,QWidget *parent = nullptr);
    ~LayoutsWidget();

};

#endif // LAYOUTSWIDGET_H
