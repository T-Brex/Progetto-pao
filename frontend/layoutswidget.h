#ifndef LAYOUTSWIDGET_H
#define LAYOUTSWIDGET_H

#include "frontend/adddialog.h"
#include "frontend/deletedialog.h"
//#include "frontend/searchMenu.h"
#include "frontend/searchMenu.h"
#include "frontend/sensorPanel.h"
#include "qscrollarea.h"
#include <QStackedWidget>

class LayoutsWidget : public QStackedWidget
{
    Q_OBJECT
public:
    QWidget* sensWindow=new QWidget;
    QHBoxLayout* sensWindowLayout=new QHBoxLayout(sensWindow);

    QVector<SensorPanel*> sensorsPanels;
    QScrollArea *sensScrollArea;
    QWidget *sensWidget;
    QVBoxLayout *sensLayout;

    QWidget *dustWidget;
    QHBoxLayout *dustLayout;
    QWidget *humidityWidget;
    QHBoxLayout *humidityLayout;
    QWidget *windWidget;
    QHBoxLayout *windLayout;
    QWidget *termometerWidget;
    QHBoxLayout *termometerLayout;
    QWidget *airQualityWidget;
    QHBoxLayout *airQualityLayout;

    SearchMenu *searchMenu;

    QWidget *simuWidget;
    QHBoxLayout *simuLayout;



    AddDialog *addDialog;
    DeleteDialog *deleteDialog;

    LayoutsWidget(QWidget * parent = nullptr);
    LayoutsWidget(QVector<QWidget*> frame,QWidget *parent = nullptr);//Eliminabile(?)

    LayoutsWidget(QVector<Sensor*> s,QWidget *parent = nullptr);

    LayoutsWidget(QVector<SensorPanel*> sp,QWidget *parent = nullptr);//Eliminabile(?)
    ~LayoutsWidget();

public slots:
    void addSensor(Sensor *s);
    void deleteSensor(QString s);

};

#endif // LAYOUTSWIDGET_H
