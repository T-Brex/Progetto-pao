#include "backend/sensors.h"
//#include <cstdlib>
#include <ctime>
#include <random>
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

int Sensor::getRandomNumber() const{return rand() % 21 -10;}


//-------------------------------------------dust
Dust::Dust(const std::string &n):Sensor(n),pm10(0),pm25(0){
    this->updateType("Dust");
}

Dust::Dust(const Dust& d):
    Sensor(d.getName()),
    pm10(d.pm10),
    pm25(d.pm25){this->updateType("Dust");}


void Dust::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(-10.0, 10.0);


    pm25 = distribution(generator);
    pm10 = distribution(generator);
}


std::vector<double> Dust::getValue() const{
    std::vector<double> out = {pm10,pm25};
    return out;}//-----------------------------------spazzatura

QVector<QString> Dust::getNameValues() const{
    QVector<QString> v = {"pm10","pm25"};
    return v;
}
//-------------------------------------------humidity
Humidity::Humidity(const std::string &n):Sensor(n),humidity(0),percentage(0){
    this->updateType("Humidity");
}

Humidity::Humidity(const Humidity& h):
    Sensor(h.getName()),
    humidity(h.humidity),
    percentage(h.percentage){this->updateType("Humidity");}


void Humidity::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(-10.0, 10.0);


    humidity = distribution(generator);
    percentage = distribution(generator);

}


std::vector<double> Humidity::getValue() const{
    std::vector<double> out = {humidity,percentage};
    return out;}

QVector<QString> Humidity::getNameValues() const{
    QVector<QString> v = {"humidity","percentage"};
    return v;
}

//-------------------------------------------wind

Wind::Wind(const std::string &n):Sensor(n),wind(0){
    this->updateType("Wind");
}

Wind::Wind(const Wind& w):
    Sensor(w.getName()),
    wind(w.wind){this->updateType("Wind");}

void Wind::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(-10.0, 10.0);


    wind = distribution(generator);

}

std::vector<double> Wind::getValue() const{
    std::vector<double> v= {wind};
    return v;}

QVector<QString> Wind::getNameValues() const{
    QVector<QString> v = {"wind"};
    return v;
}

//-------------------------------------------termometer

Termometer::Termometer(const std::string &n):Sensor(n),temperature(0){
    this->updateType("Termometer");
}

Termometer::Termometer(const Termometer& t):
    Sensor(t.getName()),
    temperature(t.temperature){this->updateType("Termometer");}

void Termometer::updateValue(){
    static std::mt19937 generator(std::random_device{}());

    std::uniform_real_distribution<double> distribution(-10.0, 10.0);


    temperature = distribution(generator);

   }

std::vector<double> Termometer::getValue() const{
    std::vector<double> v = {temperature};
    return v;
    }

QVector<QString> Termometer::getNameValues() const{
    QVector<QString> v = {"temperature"};
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
    std::vector<double> v = {quality};
    return v;
}


std::vector<double> AirQuality::getAll(){
std::vector<double> out ={(Dust::getValue())[0],(Dust::getValue())[1],(Humidity::getValue())[0],(Humidity::getValue())[1], (Wind::getValue())[0], (Termometer::getValue())[0]};
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
