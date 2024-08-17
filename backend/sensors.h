#ifndef SENSORS_H
#define SENSORS_H
#include <QDateTime>
#include <QString>
#include<QVector>
#include "measurement.h"

class Sensor{
private:
    QString name;
    QString type;
    QDateTime creationDate;
public:
    Sensor(const QString&);
    const QString& getName() const;
    virtual QVector<QString> getNameValues() const = 0;
    void modifyName(const QString&);
    virtual QVector<double> getValue() const = 0 ;
    QDateTime getCreationDate() const;
    virtual void updateValue() = 0 ;
    //virtual ~Sensor();
    void updateType(const QString& s){type =s;}
    virtual QString getType() const {return type;}

};


class Dust:virtual public Sensor{
private:
    double pm10;            // microgrammi al metro cubo µg/m3     media annuale massima 20 μg/m³, limite giornaliero 50 μg/m³
    double pm25;            // microgrammi al metro cubo µg/m3     media annuale massima 10 μg/m³, limite giornaliero 35 μg/m³
    Measurement Mpm10;
    Measurement Mpm25;
public:
    Dust(const QString&);
    Dust(const Dust&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;


};


class Humidity:virtual public Sensor{
private:
    double humidity;        // g/m³           <1 g/m³ aria secca, 23 g/m³ aria satura
    double percentage;      // percentuale    0% aria secca, 100% aria satura
    Measurement Mhumidity;
    Measurement Mpercentage;
public:
    Humidity(const QString&);
    Humidity(const Humidity&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;
};


class Wind:virtual public Sensor{
private:
    double wind;           // km/h      da 0 a 100 (>100 = eventi metereologici particolari)
    Measurement Mwind;
public:
    Wind(const QString&);
    Wind(const Wind&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;
};


class Termometer:virtual public Sensor{
private:
    double temperature;  // celsius     da -20 a 30
    Measurement Mtemperature;
public:
    Termometer(const QString&);
    Termometer(const Termometer&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;
};


class AirQuality:public Dust, public Humidity, public Wind, public Termometer{
private:
    double quality;                             //sulla base dei valori precedenti, varia da 10 (alta qualità) a -10 (bassa qualità)
    Measurement Mquality;
public:
    AirQuality(const QString&);
    AirQuality(const AirQuality&);
    void updateValue() ;
    QVector<double> getValue() const;
    QVector<QString> getNameValues() const;        //restituisce tutti gli attributi

};

#endif // SENSORS_H

