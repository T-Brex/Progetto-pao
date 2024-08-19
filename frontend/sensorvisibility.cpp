#include "sensorvisibility.h"

SensorVisibility::SensorVisibility(QObject *parent)
    : Visitor{parent}
{}
SensorVisibility::SensorVisibility(int & pIndex):index(&pIndex){}
void SensorVisibility::visit(Dust&){
    *index=0;
}
void SensorVisibility::visit(Wind&){
    *index=1;
}
void SensorVisibility::visit(Termometer&){
    *index=2;
}
void SensorVisibility::visit(Humidity&){
    *index=3;
}
void SensorVisibility::visit(AirQuality&){
    *index=4;
}
