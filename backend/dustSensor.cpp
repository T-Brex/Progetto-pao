#include "backend/dustSensor.h"
#include <random>



Dust::Dust(const QString &n, double minPm10, double maxPm10, double minPm25, double maxPm25):
    Sensor(n),Mpm10("pm10",0,minPm10,maxPm10),Mpm25("pm25",0,minPm25,maxPm25){
    this->updateType("Dust");
    Dust::updateValue();
}

Dust::Dust(const Dust& d):
    Sensor(d.getName()),Mpm10(d.Mpm10),Mpm25(d.Mpm25)
{this->updateType("Dust");}


void Dust::updateValue(){
    static std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> distributionPm10(Mpm10.getRangeMin(),Mpm10.getRangeMax());
    std::uniform_real_distribution<double> distributionPm25(Mpm25.getRangeMin(),Mpm25.getRangeMax());



    Mpm25.setValue(distributionPm25(generator));
    Mpm10.setValue(distributionPm10(generator));
}

Measurement Dust::getMpm10() const{
    return Mpm10;
}
Measurement Dust::getMpm25() const{
    return Mpm25;
}


QVector<QString> Dust::getNameValues() const{
    QVector<QString> v = {"pm10","pm25"};
    return v;
}
void Dust::accept(Visitor &visitor){
    visitor.visit(*this);
}
