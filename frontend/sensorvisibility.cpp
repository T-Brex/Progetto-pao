#include "sensorvisibility.h"

SensorVisibility::SensorVisibility(QObject *parent)
    : Visitor{parent}
{}
int SensorVisibility::visit(Dust&){
    return 0;
}
int SensorVisibility::visit(Wind&){
    return 1;
}
int SensorVisibility::visit(Termometer&){
    return 2;
}
int SensorVisibility::visit(Humidity&){
    return 3;
}
int SensorVisibility::visit(AirQuality&){
    return 4;
}
