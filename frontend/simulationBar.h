#ifndef SIMULATIONBAR_H
#define SIMULATIONBAR_H
#include "backend/sensors.h"
#include <QPushButton>
#include <QWidget>

class SimBar:public QWidget{
private:
    QPushButton *menu;
    QWidget layout;
public:
    SimBar(QVector<Sensor*> s,QWidget* parent = nullptr);
};

#endif

//widget->setWindowOpacity(0);
