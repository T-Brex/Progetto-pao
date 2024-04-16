#ifndef LAYOUTSWIDGET_H
#define LAYOUTSWIDGET_H

#include "frontend/adddialog.h"
#include "frontend/searchMenu.h"
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

    SearchMenu *searchMenu;
    //Dialog *dialog;

    LayoutsWidget(QWidget * parent = nullptr);
    LayoutsWidget(QVector<QWidget*> frame,QWidget *parent = nullptr);//Eliminabile(?)

    LayoutsWidget(QVector<Sensor*> s,QWidget *parent = nullptr);

    LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent = nullptr);//Eliminabile(?)
    ~LayoutsWidget();

    void updateSensors();

};

#endif // LAYOUTSWIDGET_H
