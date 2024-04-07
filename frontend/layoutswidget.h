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
    LayoutsWidget(QVector<QWidget*> frame,QWidget *parent = nullptr);
    LayoutsWidget(QVector<Sensor*> frame,QWidget *parent = nullptr);
    LayoutsWidget(QVector<SensorPanel*> frame,QWidget *parent = nullptr);
    ~LayoutsWidget();

};

#endif // LAYOUTSWIDGET_H
