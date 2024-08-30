#include "deepsensorgetter.h"

DeepSensorGetter::DeepSensorGetter(QObject *parent)
    : Visitor(parent), measurementVec(*(new QVector<Measurement*>())) {}

DeepSensorGetter::DeepSensorGetter(QVector<Measurement*>& mv):measurementVec(mv){}
//DeepSensorGetter::DeepSensorGetter(Measurement* m){measurementVec.push_back(m);}
void DeepSensorGetter::visit(Dust& d){
    measurementVec.push_back(&d.getMpm10Address());
    measurementVec.push_back(&d.getMpm25Address());
}
void DeepSensorGetter::visit(Wind& w){
    measurementVec.push_back(&w.getMwindAddress());

}
void DeepSensorGetter::visit(Termometer& t){
    measurementVec.push_back(&t.getMtemperatureAddress());
}
void DeepSensorGetter::visit(Humidity& h){
    measurementVec.push_back(&h.getMhumidityAddress());
    measurementVec.push_back(&h.getMpercentageAddress());
}
void DeepSensorGetter::visit(AirQuality& aq){
    measurementVec.push_back(&aq.getMqualityAddress());
}
