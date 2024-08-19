#include "sensorconstructor.h"

sensorConstructor::sensorConstructor(QObject *parent)
    : Visitor{parent}
{}
sensorConstructor::sensorConstructor(QString n, Sensor* s):name(n),sensor(&s){}
void sensorConstructor::visit(Dust&){
    *sensor = new Dust(name);
}
void sensorConstructor::visit(Wind&){
    *sensor = new Wind(name);
}
void sensorConstructor::visit(Termometer&){
    *sensor = new Termometer(name);
}
void sensorConstructor::visit(Humidity&){
    *sensor = new Humidity(name);
}
void sensorConstructor::visit(AirQuality&){
    *sensor = new AirQuality(name);
}
