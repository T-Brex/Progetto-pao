#include "measurement.h"
/*Measurement::Measurement(QObject *parent)
    : QObject{parent}
{}*/


Measurement::Measurement(const QString& name, double v, double min, double max) : name(name), value(v), rangeMin(min), rangeMax(max) {}
Measurement::Measurement(const Measurement& m):QObject(m.parent()){
    name=m.getName();
    value=m.getValue();
    rangeMax = m.getRangeMax();
    rangeMin = m.getRangeMin();
    ////////////////////////fare getrange M-m
}

<<<<<<< HEAD
Measurement::Measurement(const QString& name, double value, QObject *parent) :QObject(parent), name(name), value(value) {}
//Measurement::Measurement(const Measurement& m):QObject(m.parent()),name(m.getName()), value(m.getValue()) {}
=======

Measurement::Measurement(const QString& name, double value, QObject *parent) :QObject(parent), name(name), value(value) {}
//Measurement::Measurement(const Measurement& m):QObject(m.parent()),name(m.getName()), value(m.getValue()) {}

QString Measurement::getName() const { return name; }
>>>>>>> 221da924192030d167b70c6140358250f921580a

QString Measurement::getName() const { return name; }

double Measurement::getValue() const { return value; }

void Measurement::setValue(double newValue){ value = newValue; }


double Measurement::getRangeMin() const { return rangeMax; }

double Measurement::getRangeMax() const { return rangeMin; }

void Measurement::setRange(double min, double max) { rangeMin = min; rangeMax = max; }
