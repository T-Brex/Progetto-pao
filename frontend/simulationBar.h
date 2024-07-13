#ifndef SIMULATIONBAR_H
#define SIMULATIONBAR_H
#include "backend/sensors.h"
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>



class SimBar:public QWidget{
    Q_OBJECT
private:
    static int nButtons;

public:
    SimBar(const QVector<Sensor*>& s,QWidget* parent = nullptr);

signals:
    void add(Sensor *sensor, int i, int n);
    void remove(int n);
    void updatePlane(Sensor* s, int i, int n);
};

#endif

