#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H
#include "backend/dustSensor.h"
#include "backend/humiditySensor.h"
#include "backend/termometerSensor.h"
#include "backend/windSensor.h"

class AirQuality:public Dust, public Humidity, public Wind, public Termometer{
private:
    Measurement Mquality;
public:
    AirQuality(const QString&, double minQu = -10, double maxQu = 10);
    AirQuality(const AirQuality&);

    Measurement getMquality() const;
    Measurement& getMqualityAddress();
    void updateValue() override;
    void accept(Visitor &) override;

};

#endif
