#include "backend/sensors.h"

Sensor::Sensor(const QString& n):name(n),type("Sensor"),creationDate(QDateTime::currentDateTime()){}


const QString& Sensor::getName() const{return name;}
QDateTime Sensor::getCreationDate() const {
    return creationDate;
}
void Sensor::setName(const QString& n){
    name=n;
}


Sensor::~Sensor(){}

void Sensor::updateType(const QString& s){type =s;}
QString Sensor::getType() const {return type;}
<<<<<<< HEAD
=======


>>>>>>> 89224e0cdad36821b178c40e5e6c7d4f59df6551


