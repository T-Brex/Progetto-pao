#ifndef TERMOMETERSENSOR_H
#define TERMOMETERSENSOR_H
#include "backend/sensors.h"
#include "backend/measurement.h"

class Termometer:virtual public Sensor{
private:
    Measurement Mtemperature;
public:
    Termometer(const QString&, double minTem = -20, double maxTem = 30);
    Termometer(const Termometer&);
    Measurement& getMtemperatureAddress();
    Measurement getMtemperature() const;
    void updateValue()  override;
    QVector<QString> getNameValues() const override;
    void accept(Visitor &) override;
};

#endif
