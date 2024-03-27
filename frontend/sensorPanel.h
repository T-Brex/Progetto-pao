#ifndef SENSOR_PANEL_H
#define SENSOR_PANEL_H
#include<QString>
#include "backend\sensors.h"
#include <QIcon>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class SensorPanel: public QWidget {
    Q_OBJECT
private:
    QLabel* name;
    QLabel* values;
    QLabel* ico;
public:
    //SensorPanel(const Sensor&);
    //virtual void update();
    SensorPanel(const Sensor& s,QWidget* parent = 0);
    SensorPanel(const SensorPanel& s ,QWidget* parent = 0);
};
/*
class DustPanel: public SensorPanel{
private:
public:
    DustPanel(const QString& n = "");
    DustPanel(const SensorPanel& s);

};

class HumidityPanel: public SensorPanel{
private:
public:
    HumidityPanel(const QString& n = "");
    HumidityPanel(const SensorPanel& s);
};

class WindPanel: public SensorPanel{
private:
public:
    WindPanel(const QString& n = "");
    WindPanel(const SensorPanel& s);
};

class TermometerPanel: public SensorPanel{
private:
    TermometerPanel(const QString& n = "");
    TermometerPanel(const SensorPanel& s);
};

class AirQualityPanel: public SensorPanel{
private:
public:
    AirQualityPanel(const QString& n = "");
    AirQualityPanel(const SensorPanel& s);
};

*/
#endif






