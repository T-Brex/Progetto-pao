#ifndef SENSORS_H
#define SENSORS_H

#include <QString>
#include <string>
#include <vector>
class Sensor{
private:
    std::string name;
    std::string type;
public:
    Sensor(const std::string&);
    const std::string& getName() const;
    void modifyName(const std::string&);
    static Sensor* costruttore(const QString& nome, const QString& tipo);
    virtual std::vector<double> getValue() const = 0 ;
    virtual void updateValue() = 0 ;
    virtual ~Sensor();
    virtual void updateType(const std::string& s){type =s;}
    virtual std::string getType() const {return type;}
};


class Dust:virtual public Sensor{
private:
    double pm10;            // microgrammi al metro cubo µg/m3
    double pm25;            // microgrammi al metro cubo µg/m3
public:
    Dust(const std::string&);
    Dust(const Dust&);
    void updateValue() ;
    std::vector<double> getValue() const;


};


class Humidity:virtual public Sensor{
private:
    double humidity;        // g/m³
    double percentage;      // percentuale
public:
    Humidity(const std::string&);
    Humidity(const Humidity&);
    void updateValue() ;
    std::vector<double> getValue() const;
};


class Wind:virtual public Sensor{
private:
    double wind;           // km/h
public:
    Wind(const std::string&);
    Wind(const Wind&);
    void updateValue() ;
    std::vector<double> getValue() const;
};


class Termometer:virtual public Sensor{
private:
    double temperature;  // celsius
public:
    Termometer(const std::string&);
    Termometer(const Termometer&);
    void updateValue() ;
    std::vector<double> getValue() const;
};


class AirQuality:public Dust, public Humidity, public Wind, public Termometer{
private:
    double quality;
public:
    AirQuality(const std::string&);
    AirQuality(const AirQuality&);
    void updateValue() ;
    std::vector<double> getValue() const;         //restituisce tutti gli attributi   (Attenzione all'immondizia)
    double getQuality() ;             //restituisce la qualità dell'aria
};
#endif
