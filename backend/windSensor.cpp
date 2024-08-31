#include "backend/windSensor.h"
#include <random>


Wind::Wind(const QString &n, double minWind, double maxWind):Sensor(n),Mwind("wind",0,minWind,maxWind){
    this->updateType("Wind");Wind::updateValue();
}

Wind::Wind(const Wind& w):Sensor(w.getName()),Mwind(w.Mwind){
    this->updateType("Wind");
}

void Wind::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(Mwind.getRangeMin(),Mwind.getRangeMax());   //0 = 0 km/h , 10 = 100 km/h


    Mwind.setValue(distribution(generator));

}
Measurement& Wind::getMwindAddress(){return Mwind;}
Measurement Wind::getMwind() const{
    return Mwind;
}

void Wind::accept(Visitor &visitor){
    visitor.visit(*this);
}
