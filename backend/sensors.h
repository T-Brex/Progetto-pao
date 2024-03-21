#ifndef SENSORS_H
#define SENSORS_H

#endif // SENSORS_H
#include <string>

class Sensor{
private:
    std::string name;
public:
    Sensor(const std::string&);
    const std::string& getName() const;
    void modifyName(const std::string&);
    virtual double* getValue() const = 0 ;
    virtual double* updateValue() = 0 ;
    virtual ~Sensor();
};


class Dust:virtual public Sensor{
private:
    double pm10;            // microgrammi al metro cubo µg/m3
    double pm25;            // microgrammi al metro cubo µg/m3
public:
    Dust(const std::string&);
    Dust(const Dust&);
    double* updateValue() ;
    double* getValue() const;


};


class Humidity:virtual public Sensor{
private:
    double humidity;        // g/m³
    double percentage;      // percentuale
public:
    Humidity(const std::string&);
    Humidity(const Humidity&);
    double* updateValue() ;
    double* getValue() const;
};


class Wind:virtual public Sensor{
private:
    double wind;           // km/h
public:
    Wind(const std::string&);
    Wind(const Wind&);
    double* updateValue() ;
    double* getValue() const;
};


class Termometer:virtual public Sensor{
private:
    double temperature;  // celsius
public:
    Termometer(const std::string&);
    Termometer(const Termometer&);
    double* updateValue() ;
    double* getValue() const;
};


class AirQuality:public Dust, public Humidity, public Wind, public Termometer{
private:
public:
    AirQuality(const std::string&);
    AirQuality(const AirQuality&);
    double* updateValue() ;
    double* getValue() const;         //restituisce tutti gli attributi   (Attenzione all'immondizia)
    double getQuality() ;             //restituisce la qualità dell'aria
};
