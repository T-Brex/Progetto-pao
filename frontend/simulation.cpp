#include "frontend/simulation.h"
#include "qscrollarea.h"

Simulation::Simulation(QVector<Sensor*> s, QWidget* parent):QWidget(parent){

    QHBoxLayout *layout = new QHBoxLayout(this);

    QWidget *leftBar = new QWidget(this);
    QVBoxLayout *layoutLeftBar = new QVBoxLayout(leftBar);
    legend= new Legend(leftBar);
    layoutLeftBar->addWidget(legend);
    simBar = new SimBar(s, leftBar);
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(simBar);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);


    layoutLeftBar->addWidget(scrollArea);
    layout->addWidget(leftBar);






    plane = new CartesianPlane(this);
    plane->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    plane->setMinimumSize(160, 90);
    plane->setStyleSheet("background-color: black; border: 1px solid gray;");
    layout->addWidget(plane);

    connect(simBar, &SimBar::addD, plane, &CartesianPlane::addDust);
    connect(simBar, &SimBar::addW, plane, &CartesianPlane::addWind);
    connect(simBar, &SimBar::addT, plane, &CartesianPlane::addTermometer);
    connect(simBar, &SimBar::addH, plane, &CartesianPlane::addHumidity);
    connect(simBar, &SimBar::addA, plane, &CartesianPlane::addAirQuality);
    connect(simBar, &SimBar::rem, this, &Simulation::removeSensor);
    connect(simBar, &SimBar::updateD, this, &Simulation::updateDust);
    connect(simBar, &SimBar::updateW, this, &Simulation::updateWind);
    connect(simBar, &SimBar::updateT, this, &Simulation::updateTermometer);
    connect(simBar, &SimBar::updateH, this, &Simulation::updateHumidity);
    connect(simBar, &SimBar::updateA, this, &Simulation::updateAirQuality);

}


void Simulation::removeSensor(int n){
    plane->removeSensor(n);
}

void Simulation::updateDust(const Dust &s, int i, int n) {
    plane->addDust(s, i, n);
}

void Simulation::updateWind(const Wind &s, int i, int n) {
    plane->addWind(s, i, n);
}

void Simulation::updateTermometer(const Termometer &s, int i, int n) {
    plane->addTermometer(s, i, n);
}

void Simulation::updateHumidity(const Humidity &s, int i, int n) {
    plane->addHumidity(s, i, n);
}

void Simulation::updateAirQuality(const AirQuality &s, int i, int n) {
    plane->addAirQuality(s, i, n);
}

