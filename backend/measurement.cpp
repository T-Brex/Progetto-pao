#include "measurement.h"
#include <random>
/*Measurement::Measurement(QObject *parent)
    : QObject{parent}
{}*/


Measurement::Measurement(const QString& name, double value) : name(name), value(value) {}
Measurement::Measurement(const Measurement& m){
    name=m.getName();
    value=m.getValue();
}

QString Measurement::getName() const { return name; }

double Measurement::getValue() const { return value; }

void Measurement::setValue(double newValue){
    value=newValue;
}

