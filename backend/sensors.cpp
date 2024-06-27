#include "backend/sensors.h"
#include <random>

Sensor::Sensor(const QString& n):name(n),type("Sensor"),creationDate(QDateTime::currentDateTime()){}


const QString& Sensor::getName() const{return name;}
QDateTime Sensor::getCreationDate() const {
    return creationDate;
}
void Sensor::modifyName(const QString& n){
    name=n;
}

Sensor::~Sensor(){}





//-------------------------------------------dust
Dust::Dust(const QString &n):Sensor(n),pm10(0),pm25(0){
    this->updateType("Dust");
    Dust::updateValue();
}

Dust::Dust(const Dust& d):
    Sensor(d.getName()),
    pm10(d.pm10),
    pm25(d.pm25){this->updateType("Dust");Dust::updateValue();}


void Dust::updateValue(){
    static std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> distributionPm10(0.0, 50.0);
    std::uniform_real_distribution<double> distributionPm25(0.0, 35.0);


    pm25 = distributionPm25(generator);
    pm10 = distributionPm10(generator);
}


QVector<double> Dust::getValue() const{
    QVector<double> out = {pm10,pm25};
    return out;}//-----------------------------------spazzatura

QVector<QString> Dust::getNameValues() const{
    QVector<QString> v = {"pm10","pm25"};
    return v;
}
//-------------------------------------------humidity
Humidity::Humidity(const QString &n):Sensor(n),humidity(0),percentage(0){
    this->updateType("Humidity");
}

Humidity::Humidity(const Humidity& h):
    Sensor(h.getName()),
    humidity(h.humidity),
    percentage(h.percentage){this->updateType("Humidity");}


void Humidity::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distributionHum(0.0, -23.0);
    std::uniform_real_distribution<double> distributionPer(0.0, -10.0);   //0 = 0% , 10 = 100%

    humidity = distributionHum(generator);
    percentage = distributionPer(generator);

}


QVector<double> Humidity::getValue() const{
    QVector<double> out = {humidity,percentage};
    return out;}

QVector<QString> Humidity::getNameValues() const{
    QVector<QString> v = {"humidity","percentage"};
    return v;
}

//-------------------------------------------wind

Wind::Wind(const QString &n):Sensor(n),wind(0){
    this->updateType("Wind");
}

Wind::Wind(const Wind& w):
    Sensor(w.getName()),
    wind(w.wind){this->updateType("Wind");}

void Wind::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(0.0, -10.0);   //0 = 0 km/h , 10 = 100 km/h


    wind = distribution(generator);

}

QVector<double> Wind::getValue() const{
    QVector<double> v= {wind};
    return v;}

QVector<QString> Wind::getNameValues() const{
    QVector<QString> v = {"wind"};
    return v;
}

//-------------------------------------------termometer

Termometer::Termometer(const QString &n):Sensor(n),temperature(0){
    this->updateType("Termometer");
}

Termometer::Termometer(const Termometer& t):
    Sensor(t.getName()),
    temperature(t.temperature){this->updateType("Termometer");}

void Termometer::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(20.0, -30.0);


    temperature = distribution(generator);

   }

QVector<double> Termometer::getValue() const{
    QVector<double> v = {temperature};
    return v;
    }

QVector<QString> Termometer::getNameValues() const{
    QVector<QString> v = {"temperature"};
    return v;
}

//-------------------------------------------air quality




AirQuality::AirQuality(const QString& n):
    Sensor(n), Dust(n), Humidity(n), Wind(n), Termometer(n), quality(0)
    {this->updateType("AirQuality");}

AirQuality::AirQuality(const AirQuality& a):
    Sensor(a.getName()), Dust(a), Humidity(a), Wind(a), Termometer(a)
    {this->updateType("AirQuality");}


QVector<double> AirQuality::getValue() const{
    QVector<double> v = {quality};
    return v;

}


QVector<double> AirQuality::getAll(){
QVector<double> out ={(Dust::getValue())[0],(Dust::getValue())[1],(Humidity::getValue())[0],(Humidity::getValue())[1], (Wind::getValue())[0], (Termometer::getValue())[0]};
return out;}

void AirQuality::updateValue(){
    Dust::updateValue();
    Humidity::updateValue();
    Wind::updateValue();
    Termometer::updateValue();

    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(-10.0, 10.0);


    quality = distribution(generator);

    }

QVector<QString> AirQuality::getNameValues() const{
    QVector<QString> v = {"quality"};
    return v;
}
