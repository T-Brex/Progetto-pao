#include "backend/sensors.h"

Sensor::Sensor(const std::string& n):name(n){type="Sensor";}

const std::string& Sensor::getName() const{return name;}
void Sensor::modifyName(const std::string& n){
    name=n;
}
Sensor* Sensor::costruttore(const QString& nome, const QString& tipo){
    Sensor* nuovoSensore = nullptr;
    if (tipo == "Dust") {
        nuovoSensore = new Dust(nome.toStdString());
    } else if (tipo == "Humidity") {
        nuovoSensore = new Humidity(nome.toStdString());
    } else if (tipo == "Wind") {
        nuovoSensore = new Wind(nome.toStdString());
    } else if (tipo == "Termometer") {
        nuovoSensore = new Termometer(nome.toStdString());
    } else if (tipo == "AirQuality") {
        nuovoSensore = new AirQuality(nome.toStdString());
    }
    return nuovoSensore;
}
Sensor::~Sensor(){}

//-------------------------------------------dust
Dust::Dust(const std::string &n):Sensor(n),pm10(0),pm25(0){
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


std::vector<double> Dust::getValue() const{
    std::vector<double> out = {pm10,pm25};
    return out;}//-----------------------------------spazzatura


//-------------------------------------------humidity
Humidity::Humidity(const std::string &n):Sensor(n),humidity(0),percentage(0){
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


std::vector<double> Humidity::getValue() const{
    std::vector<double> out = {humidity,percentage};
    return out;}



//-------------------------------------------wind

Wind::Wind(const std::string &n):Sensor(n),wind(0){
    this->updateType("Wind");
}

Wind::Wind(const Wind& w):
    Sensor(w.getName()),
    wind(w.wind){this->updateType("Wind");}

void Wind::updateValue(){
    wind = rand() % 10;
}

std::vector<double> Wind::getValue() const{
    std::vector<double> v= {wind};
    return v;}



//-------------------------------------------termometer

Termometer::Termometer(const std::string &n):Sensor(n),temperature(0){
    this->updateType("Termometer");
}

Termometer::Termometer(const Termometer& t):
    Sensor(t.getName()),
    temperature(t.temperature){this->updateType("Termometer");}

void Termometer::updateValue(){
    temperature = rand() % 10;
   }

std::vector<double> Termometer::getValue() const{
    std::vector<double> v = {temperature};
    return v;
    }


//-------------------------------------------air quality




AirQuality::AirQuality(const std::string& n):
    Sensor(n), Dust(n), Humidity(n), Wind(n), Termometer(n)
    {this->updateType("AirQuality");}

AirQuality::AirQuality(const AirQuality& a):
    Sensor(a.getName()), Dust(a), Humidity(a), Wind(a), Termometer(a)
    {this->updateType("AirQuality");}

std::vector<double> AirQuality::getValue() const{
    std::vector<double> out ={(Dust::getValue())[0],(Dust::getValue())[1],(Humidity::getValue())[0],(Humidity::getValue())[1], (Wind::getValue())[0], (Termometer::getValue())[0]};
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


