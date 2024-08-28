#include "backend/sensors.h"

Sensor::Sensor(const QString& n):name(n),type("Sensor"),creationDate(QDateTime::currentDateTime()){}


const QString& Sensor::getName() const{return name;}
QDateTime Sensor::getCreationDate() const {
    return creationDate;
}
void Sensor::modifyName(const QString& n){
    name=n;
}

Sensor::~Sensor(){}


