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

