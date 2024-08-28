#include "measurement.h"
/*Measurement::Measurement(QObject *parent)
    : QObject{parent}
{}*/


Measurement::Measurement(const QString& name, double v, double min, double max) : name(name), value(v), rangeMin(min), rangeMax(max) {}
Measurement::Measurement(const Measurement& m){
    name=m.getName();
    value=m.getValue();
    rangeMax = m.getRangeMax();
    rangeMin = m.getRangeMin();
    ////////////////////////fare getrange M-m
}

QString Measurement::getName() const { return name; }

double Measurement::getValue() const { return value; }

void Measurement::setValue(double newValue){ value = newValue; }


double Measurement::getRangeMin() const { return rangeMax; }

double Measurement::getRangeMax() const { return rangeMin; }

void Measurement::setRange(double min, double max) { rangeMin = min; rangeMax = max; }
