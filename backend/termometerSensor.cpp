#include "backend/termometerSensor.h"
#include <random>

Termometer::Termometer(const QString &n, double minTem, double maxTem):Sensor(n),Mtemperature("temperature",0,minTem,maxTem){
    this->updateType("Termometer");Termometer::updateValue();
}

Termometer::Termometer(const Termometer& t):Sensor(t.getName()), Mtemperature(t.Mtemperature){
    this->updateType("Termometer");
}

void Termometer::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(Mtemperature.getRangeMin(),Mtemperature.getRangeMax());


    Mtemperature.setValue(distribution(generator));

}
Measurement& Termometer::getMtemperatureAddress(){return Mtemperature;}

Measurement Termometer::getMtemperature() const{
    return Mtemperature;
}




QVector<QString> Termometer::getNameValues() const{
    QVector<QString> v = {"temperature"};
    return v;
}
void Termometer::accept(Visitor &visitor){
    visitor.visit(*this);
}
