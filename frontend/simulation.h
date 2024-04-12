#ifndef SIMULATION_H
#define SIMULATION_H
#include "frontend/simulationBar.h"


class Simulation :public QWidget{
private:
    SimBar *simBar;
    //Graph *graph;
public:
    Simulation(QVector<Sensor*> s,QWidget* parent=nullptr);

};
#endif
