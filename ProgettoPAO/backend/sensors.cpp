#include "backend/sensors.h"

Sensor::Sensor(const std::string& n):name(n){}

const std::string& Sensor::getName() const{return name;}
void Sensor::modifyName(const std::string& n){
    name=n;
}
Sensor::~Sensor(){}

//-------------------------------------------dust
Dust::Dust(const std::string &n):Sensor(n){
    pm10=0; pm25=0;
}

Dust::Dust(const Dust& d):
    Sensor(d.getName()),
    pm10(d.pm10),
    pm25(d.pm25){}


double* Dust::updateValue(){
    double r = rand() % 10;
    pm25=r;
    double r2 = rand() % 10;
    pm10=r2;
    return new double[2]{pm25,pm10};}//-----------------------------------spazzatura


double* Dust::getValue() const{
    double *out = new double[2]{pm10,pm25};
    return out;}//-----------------------------------spazzatura


//-------------------------------------------humidity
Humidity::Humidity(const std::string &n):Sensor(n){
    humidity=0; percentage=0;
}

Humidity::Humidity(const Humidity& h):
    Sensor(h.getName()),
    humidity(h.humidity),
    percentage(h.percentage){}


double* Humidity::updateValue(){
    double r = rand() % 10;
    percentage=r;
    double r2 = rand() % 10;
    humidity=r2;
    return new double[2]{percentage,humidity};}//-----------------------------------spazzatura


double* Humidity::getValue() const{
    double *out = new double[2]{humidity,percentage};
    return out;}//-----------------------------------spazzatura


//-------------------------------------------wind

Wind::Wind(const std::string &n):Sensor(n){
    wind=0;
}

Wind::Wind(const Wind& w):
    Sensor(w.getName()),
    wind(w.wind){}

double* Wind::updateValue(){
    double r = rand() % 10;
    wind=r;
    return new double(wind);}//-----------------------------------spazzatura

double* Wind::getValue() const{
    return new double(wind);}//-----------------------------------spazzatura



//-------------------------------------------termometer

Termometer::Termometer(const std::string &n):Sensor(n){
    temperature=0;
}

Termometer::Termometer(const Termometer& t):
    Sensor(t.getName()),
    temperature(t.temperature){}

double* Termometer::updateValue(){
    double r = rand() % 10;
    temperature=r;
    return new double(temperature);}//-----------------------------------spazzatura

double* Termometer::getValue() const{
    return new double(temperature);}//-----------------------------------spazzatura


//-------------------------------------------air quality




AirQuality::AirQuality(const std::string& n):Sensor(n), Dust(n), Humidity(n), Wind(n), Termometer(n){}

AirQuality::AirQuality(const AirQuality& a):Sensor(a.getName()), Dust(a), Humidity(a), Wind(a), Termometer(a){}

double* AirQuality::getValue() const{
    double *out = new double[6]{(Dust::getValue())[0],(Dust::getValue())[1],(Humidity::getValue())[0],(Humidity::getValue())[1], *(Wind::getValue()), *(Termometer::getValue())};
    return out;}//-----------------------------------spazzatura


double AirQuality::getQuality(){
    /*getPm10(),getPm25(),getHumidity(),getPercentage(),getWind(),getTemperature()*/
    double quality = 1;
    return quality;
}

double* AirQuality::updateValue(){
    delete[](Dust::updateValue());
    delete[](Humidity::updateValue());
    delete(Wind::updateValue());
    delete(Termometer::updateValue());
    double quality = rand() % 10;
    return new double(quality);}//-----------------------------------spazzatura


