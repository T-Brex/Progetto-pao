#include "measurementsetter.h"
#include "backend/dustSensor.h"


MeasurementSetter::MeasurementSetter(QJsonObject& so,QObject *parent):sensoreObject(so){}
void MeasurementSetter::visit(Dust& d){
    d.getMpm10Address().setRange(sensoreObject["min"+d.getMpm10().getName()].toDouble(),sensoreObject["max"+d.getMpm10().getName()].toDouble());
    d.getMpm25Address().setRange(sensoreObject["min"+d.getMpm25().getName()].toDouble(),sensoreObject["max"+d.getMpm25().getName()].toDouble());
}
void MeasurementSetter::visit(Wind& w){
    w.getMwindAddress().setRange(sensoreObject["min"+w.getMwind().getName()].toDouble(),sensoreObject["max"+w.getMwind().getName()].toDouble());
}
void MeasurementSetter::visit(Termometer& t){
    t.getMtemperatureAddress().setRange(sensoreObject["min"+t.getMtemperature().getName()].toDouble(),sensoreObject["max"+t.getMtemperature().getName()].toDouble());
}
void MeasurementSetter::visit(Humidity& h){
    h.getMhumidityAddress().setRange(sensoreObject["min"+h.getMhumidity().getName()].toDouble(),sensoreObject["max"+h.getMhumidity().getName()].toDouble());
    h.getMpercentageAddress().setRange(sensoreObject["min"+h.getMpercentage().getName()].toDouble(),sensoreObject["max"+h.getMpercentage().getName()].toDouble());
}
void MeasurementSetter::visit(AirQuality& aq){
    aq.getMqualityAddress().setRange(sensoreObject["min"+aq.getMtemperature().getName()].toDouble(),sensoreObject["max"+aq.getMquality().getName()].toDouble());
}

