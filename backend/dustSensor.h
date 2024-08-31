#ifndef DUSTSENSOR_H
#define DUSTSENSOR_H
#include "backend/sensors.h"
#include "backend/measurement.h"

class Dust:virtual public Sensor{
private:
    Measurement Mpm10;
    Measurement Mpm25;
public:
    Dust(const QString&, double minPm10 = 0, double maxPm10 = 50, double minPm25 = 0, double maxPm25 = 35);
    Dust(const Dust&);
    void updateValue()  override;
    Measurement& getMpm10Address();
    Measurement& getMpm25Address();


    Measurement getMpm10() const;
    Measurement getMpm25() const;

    void accept(Visitor &) override;


};
#endif
