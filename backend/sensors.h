#ifndef SENSORS_H
#define SENSORS_H

#include <string>
#include <QString>
#include<vector>
#include<QVector>

class Sensor{
private:
    QString name;
    QString type;
public:
    Sensor(const QString&);
    const QString& getName() const;
    virtual QVector<QString> getNameValues() const = 0;
    void modifyName(const QString&);
    //static Sensor* costruttore(const QString& nome, const QString& tipo);
    virtual QVector<double> getValue() const = 0 ;
    virtual void updateValue() = 0 ;
    virtual ~Sensor();
    virtual void updateType(const QString& s){type =s;}
    virtual QString getType() const {return type;}
    virtual int getRandomNumber() const ;
};


class Dust:virtual public Sensor{
private:
    double pm10;            // microgrammi al metro cubo µg/m3
    double pm25;            // microgrammi al metro cubo µg/m3
public:
    Dust(const QString&);
    Dust(const Dust&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;


};


class Humidity:virtual public Sensor{
private:
    double humidity;        // g/m³
    double percentage;      // percentuale
public:
    Humidity(const QString&);
    Humidity(const Humidity&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;
};


class Wind:virtual public Sensor{
private:
    double wind;           // km/h
public:
    Wind(const QString&);
    Wind(const Wind&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;
};


class Termometer:virtual public Sensor{
private:
    double temperature;  // celsius
public:
    Termometer(const QString&);
    Termometer(const Termometer&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;
};


class AirQuality:public Dust, public Humidity, public Wind, public Termometer{
private:
    double quality;
public:
    AirQuality(const QString&);
    AirQuality(const AirQuality&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;        //restituisce tutti gli attributi   (Attenzione all'immondizia)
    double getQuality() ;             //restituisce la qualità dell'aria
};

#endif // SENSORS_H

