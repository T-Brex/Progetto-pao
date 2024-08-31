#include "sensorgetter.h"

SensorGetter::SensorGetter(QObject *parent)
    : Visitor(parent), measurementVec(*(new QVector<Measurement*>())) {}

SensorGetter::SensorGetter(QVector<Measurement*>& mv, QObject *parent):Visitor(parent),measurementVec(mv){}
void SensorGetter::visit(Dust& d){
    measurementVec.push_back(new Measurement (d.getMpm10()));
    measurementVec.push_back(new Measurement (d.getMpm25()));
}
void SensorGetter::visit(Wind& w){
    measurementVec.push_back(new Measurement (w.getMwind()));

}
void SensorGetter::visit(Termometer& t){
    measurementVec.push_back(new Measurement (t.getMtemperature()));
}
void SensorGetter::visit(Humidity& h){
    measurementVec.push_back(new Measurement (h.getMhumidity()));
    measurementVec.push_back(new Measurement (h.getMpercentage()));
}
void SensorGetter::visit(AirQuality& aq){
    measurementVec.push_back(new Measurement (aq.getMquality()));
}
