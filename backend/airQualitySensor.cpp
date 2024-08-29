#include "backend/airQualitySensor.h"
#include <random>

AirQuality::AirQuality(const QString& n, double minQu, double maxQu):
    Sensor(n), Dust(n), Humidity(n), Wind(n), Termometer(n),  Mquality("quality",0,minQu,maxQu)
{this->updateType("AirQuality");AirQuality::updateValue();}

AirQuality::AirQuality(const AirQuality& a):
    Sensor(a.getName()), Dust(a), Humidity(a), Wind(a), Termometer(a), Mquality(a.Mquality)
{this->updateType("AirQuality");}

Measurement AirQuality::getMquality() const{
    return Mquality;
}




void AirQuality::updateValue(){
    Dust::updateValue();
    Humidity::updateValue();
    Wind::updateValue();
    Termometer::updateValue();

    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(Mquality.getRangeMin(),Mquality.getRangeMax());



    Mquality.setValue(distribution(generator));

}

QVector<QString> AirQuality::getNameValues() const{
    QVector<QString> v = {"quality"};
    return v;
}
void AirQuality::accept(Visitor &visitor){
    visitor.visit(*this);
}
