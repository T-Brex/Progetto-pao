#ifndef LAYOUTSWIDGET_H
#define LAYOUTSWIDGET_H

#include "frontend/adddialog.h"
#include "frontend/deletedialog.h"
#include "frontend/sensorwindow.h"
#include "frontend/simulation.h"
#include <QStackedWidget>

class LayoutsWidget : public QStackedWidget
{
    Q_OBJECT
public:

    sensorWindow* sensWindow;
    Simulation *simuWindow;

    AddDialog *addDialog;
    DeleteDialog *deleteDialog;

    LayoutsWidget(QWidget * parent = nullptr);
    //LayoutsWidget(QVector<QWidget*> frame,QWidget *parent = nullptr);//Eliminabile(?)

    //LayoutsWidget(QVector<Sensor*> s,QWidget *parent = nullptr);

    //LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent = nullptr);//Eliminabile(?)
    ~LayoutsWidget();

};

#endif // LAYOUTSWIDGET_H
