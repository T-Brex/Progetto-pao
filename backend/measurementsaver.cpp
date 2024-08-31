#include "measurementsaver.h"
#include "backend/dustSensor.h"


MeasurementSaver::MeasurementSaver(QJsonObject& so,Visitor *parent):Visitor(parent),sensoreObject(so){}
void MeasurementSaver::visit(Dust& d){
    sensoreObject[d.getMpm10().getName()]=d.getMpm10().getValue();
    sensoreObject["min"+d.getMpm10().getName()]=d.getMpm10().getRangeMin();
    sensoreObject["max"+d.getMpm10().getName()]=d.getMpm10().getRangeMax();

    sensoreObject[d.getMpm25().getName()]=d.getMpm25().getValue();
    sensoreObject["min"+d.getMpm25().getName()]=d.getMpm25().getRangeMin();
    sensoreObject["max"+d.getMpm25().getName()]=d.getMpm25().getRangeMax();

    }
void MeasurementSaver::visit(Wind& w){


    sensoreObject[w.getMwind().getName()]=w.getMwind().getValue();
    sensoreObject["max"+w.getMwind().getName()]=w.getMwind().getRangeMax();
    sensoreObject["min"+w.getMwind().getName()]=w.getMwind().getRangeMin();

}
void MeasurementSaver::visit(Termometer& t){
    sensoreObject[t.getMtemperature().getName()]=t.getMtemperature().getValue();
    sensoreObject["max"+t.getMtemperature().getName()]=t.getMtemperature().getRangeMax();
    sensoreObject["min"+t.getMtemperature().getName()]=t.getMtemperature().getRangeMin();

}
void MeasurementSaver::visit(Humidity& h){
    sensoreObject[h.getMhumidity().getName()]=h.getMhumidity().getValue();
    sensoreObject["max"+h.getMhumidity().getName()]=h.getMhumidity().getRangeMax();
    sensoreObject["min"+h.getMhumidity().getName()]=h.getMhumidity().getRangeMin();

    sensoreObject[h.getMpercentage().getName()]=h.getMpercentage().getValue();
    sensoreObject["max"+h.getMpercentage().getName()]=h.getMpercentage().getRangeMax();
    sensoreObject["min"+h.getMpercentage().getName()]=h.getMpercentage().getRangeMin();


}
void MeasurementSaver::visit(AirQuality& aq){
    sensoreObject[aq.getMquality().getName()]=aq.getMquality().getValue();
    sensoreObject["max"+aq.getMquality().getName()]=aq.getMquality().getRangeMax();
    sensoreObject["min"+aq.getMquality().getName()]=aq.getMquality().getRangeMin();

}
