#ifndef SIMULATION_H
#define SIMULATION_H
#include "frontend/simulationBar.h"
#include "frontend/cartesianPlane.h"
#include "frontend/legend.h"


class Simulation :public QWidget{
    Q_OBJECT
private:
    SimBar *simBar;
    CartesianPlane *plane;
    Legend *legend;

public:
    Simulation(QVector<Sensor*> s, QWidget* parent=nullptr);

public slots:
    void addSensor(Sensor* s, int i, int n);
    void removeSensor(int n);
    void updatePlane(Sensor* s, int i, int n);

};
#endif
