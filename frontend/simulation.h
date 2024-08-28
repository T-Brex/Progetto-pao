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
    void removeSensor(int n);
    void updateDust(const Dust& s, int i, int n);
    void updateWind(const Wind& s, int i, int n);
    void updateTermometer(const Termometer& s, int i, int n);
    void updateHumidity(const Humidity& s, int i, int n);
    void updateAirQuality(const AirQuality& s, int i, int n);

};
#endif
