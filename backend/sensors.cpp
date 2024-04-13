#include "backend/sensors.h"

Sensor::Sensor(const QString& n):name(n){type="Sensor";}

const QString& Sensor::getName() const{return name;}

void Sensor::modifyName(const QString& n){
    name=n;
}

Sensor::~Sensor(){}

int Sensor::getRandomNumber() const{return rand() % 10;}


//-------------------------------------------dust
Dust::Dust(const QString &n):Sensor(n),pm10(0),pm25(0){
    this->updateType("Dust");
}

Dust::Dust(const Dust& d):
    Sensor(d.getName()),
    pm10(d.pm10),
    pm25(d.pm25){this->updateType("Dust");}


void Dust::updateValue(){
    pm25 = rand() % 10;
    pm10 = rand() % 10;
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
    percentage = rand() % 10;
    humidity = rand() % 10;
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
    wind = rand() % 10;
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
    temperature = rand() % 10;
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
    Sensor(n), Dust(n), Humidity(n), Wind(n), Termometer(n)
    {this->updateType("AirQuality");}

AirQuality::AirQuality(const AirQuality& a):
    Sensor(a.getName()), Dust(a), Humidity(a), Wind(a), Termometer(a)
    {this->updateType("AirQuality");}

QVector<double> AirQuality::getValue() const{
    QVector<double> out ={(Dust::getValue())[0],(Dust::getValue())[1],(Humidity::getValue())[0],(Humidity::getValue())[1], (Wind::getValue())[0], (Termometer::getValue())[0]};
    return out;}


double AirQuality::getQuality(){
    return quality;
}

void AirQuality::updateValue(){
    Dust::updateValue();
    Humidity::updateValue();
    Wind::updateValue();
    Termometer::updateValue();
    quality = rand() % 10;//calcolo qualita sulla base di tutti i sensori
    }

QVector<QString> AirQuality::getNameValues() const{
    QVector<QString> v = {"pm10","pm25","humidity","percentage","wind","temperature","quality"};
    return v;
}
