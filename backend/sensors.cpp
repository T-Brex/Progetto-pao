#include "backend/sensors.h"

Sensor::Sensor(const QString& n):name(n),type("Sensor"),creationDate(QDateTime::currentDateTime()){}


const QString& Sensor::getName() const{return name;}
QDateTime Sensor::getCreationDate() const {
    return creationDate;
}
void Sensor::modifyName(const QString& n){
    name=n;
}
<<<<<<< HEAD

Sensor::~Sensor(){}
=======
void Sensor::updateType(const QString& s){type =s;}
QString Sensor::getType() const {return type;}
//Sensor::~Sensor(){}
>>>>>>> 2cd819f69459d430b2163cad621507adaf986d08


