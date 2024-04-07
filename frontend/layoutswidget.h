#ifndef LAYOUTSWIDGET_H
#define LAYOUTSWIDGET_H

#include "frontend/sensorPanel.h"
#include <QStackedWidget>

class LayoutsWidget : public QStackedWidget
{
    Q_OBJECT
public:
    QWidget* sensWindow=new QWidget;
    QHBoxLayout* sensWindowLayout=new QHBoxLayout(sensWindow);

    QWidget *sensWidget;
    QVBoxLayout *sensLayout;

    QWidget *simuWidget;
    QHBoxLayout *simuLayout;

    LayoutsWidget(QWidget * parent = nullptr);
    LayoutsWidget(QVector<QWidget*> frame,QWidget *parent = nullptr);//Eliminabile(?)

    LayoutsWidget(QVector<Sensor*> s,QWidget *parent = nullptr);

    LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent = nullptr);//Eliminabile(?)
    ~LayoutsWidget();

};

#endif // LAYOUTSWIDGET_H
