
#include "backend/humiditySensor.h"
#include <random>




Humidity::Humidity(const QString& n, double minHum, double maxHum, double minPer, double maxPer )
    :Sensor(n),Mhumidity("humidity",0,minHum,maxHum),Mpercentage("percentage",0,minPer,maxPer){
    this->updateType("Humidity");Humidity::updateValue();
}

Humidity::Humidity(const Humidity& h):
    Sensor(h.getName()),
    Mhumidity(h.Mhumidity),
    Mpercentage(h.Mpercentage)
{this->updateType("Humidity");}


void Humidity::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distributionHum(Mhumidity.getRangeMin(),Mhumidity.getRangeMax());
    std::uniform_real_distribution<double> distributionPer(Mpercentage.getRangeMin(),Mpercentage.getRangeMax());   //0 = 0% , 10 = 100%


    Mhumidity.setValue(distributionHum(generator));
    Mpercentage.setValue(distributionPer(generator));

}
Measurement& Humidity::getMhumidityAddress(){return Mhumidity;}
Measurement& Humidity::getMpercentageAddress(){return Mpercentage;}
Measurement Humidity::getMhumidity() const{
    return Mhumidity;
}
Measurement Humidity::getMpercentage() const{
    return Mpercentage;
}


QVector<QString> Humidity::getNameValues() const{
    QVector<QString> v = {"humidity","percentage"};
    return v;
}
void Humidity::accept(Visitor &visitor){
    visitor.visit(*this);
}
