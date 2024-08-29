#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H
#include "backend/sensors.h"
#include "backend/measurement.h"
class Humidity:virtual public Sensor{
private:
    Measurement Mhumidity;
    Measurement Mpercentage;
public:
    Humidity(const QString&, double minHum = 0, double maxHum = 23, double minPer = 0, double maxPer = 10);
    Humidity(const Humidity&);
    Measurement getMhumidity() const;
    Measurement getMpercentage() const;
    void updateValue()  override;
    QVector<QString> getNameValues() const override;
    void accept(Visitor &) override;
};

#endif
