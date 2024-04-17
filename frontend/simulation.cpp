#include "frontend/simulation.h"

Simulation::Simulation(QVector<Sensor*> s, QWidget* parent):QWidget(parent){
    QHBoxLayout *layout = new QHBoxLayout(this);

    // Crea e aggiungi SimBar al layout
    simBar = new SimBar(s, this);
    layout->addWidget(simBar);

    // Aggiungi uno spaziatore elastico per spingere plane a destra
    //layout->addStretch();

    // Crea e aggiungi CartesianPlane al layout
    plane = new CartesianPlane(this);
    plane->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    plane->setMinimumSize(160, 90);
    plane->setStyleSheet("background-color: black; border: 1px solid gray;"); // Imposta lo stile di CartesianPlane
    layout->addWidget(plane);
    connect(simBar, &SimBar::add, this, &Simulation::addSensor);
    connect(simBar, &SimBar::remove, this, &Simulation::removeSensor);
    connect(simBar, &SimBar::updatePlane, this, &Simulation::updatePlane);

}
void Simulation::addSensor(Sensor* s, int i, int n){
   plane->addSensor(s,i,n);
}
void Simulation::removeSensor(int n){
    plane->removeSensor(n);
}
void Simulation::updatePlane(Sensor* s, int i, int n){
    plane->addSensor(s,i,n);//dovrebbe aggiornare con i valori più recenti ma essendo generati a caso la funzione sarebbe identica a addSensors
}

