#ifndef SIMULATIONBAR_H
#define SIMULATIONBAR_H
#include "backend/sensors.h"
#include "frontend/simBarVisitor.h"
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>



class SimBar:public QWidget{
    Q_OBJECT
private:
    std::vector<SimBarVisitor*> visitors;

public:
    SimBar(QVector<Sensor*>& s,QWidget* parent = nullptr);
    ~SimBar();
signals:
    void addD(const Dust& s, int i, int n);
    void addW(const Wind& s, int i, int n);
    void addT(const Termometer& s, int i, int n);
    void addH(const Humidity& s, int i, int n);
    void addA(const AirQuality& s, int i, int n);
    void rem(int n);
    void updateD(const Dust &s, int i, int n);
    void updateW(const Wind &s, int i, int n);
    void updateT(const Termometer &s, int i, int n);
    void updateH(const Humidity &s, int i, int n);
    void updateA(const AirQuality &s, int i, int n);
public slots:
    void addDust(const Dust& s, int i, int n);
    void addWind(const Wind& s, int i, int n);
    void addTermometer(const Termometer& s, int i, int n);
    void addHumidity(const Humidity& s, int i, int n);
    void addAirQuality(const AirQuality& s, int i, int n);
    void remove(int n);
    void updateDust(const Dust &s, int i, int n);
    void updateWind(const Wind &s, int i, int n);
    void updateTermometer(const Termometer &s, int i, int n);
    void updateHumidity(const Humidity &s, int i, int n);
    void updateAirQuality(const AirQuality &s, int i, int n);
};

#endif

