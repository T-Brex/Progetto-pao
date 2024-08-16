#include "measurement.h"

/*Measurement::Measurement(QObject *parent)
    : QObject{parent}
{}*/


Measurement::Measurement(const QString& name, double value) : name(name), value(value) {}
Measurement::Measurement(const Measurement& m){
    Measurement(m.getName(),m.getValue());
}
QString Measurement::getName() const { return name; }
double Measurement::getValue() const { return value; }
void Measurement::setValue(double newValue){
    value=newValue;
}

