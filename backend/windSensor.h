#ifndef WINDSENSOR_H
#define WINDSENSOR_H
#include "backend/sensors.h"
#include "backend/measurement.h"
class Wind:virtual public Sensor{
private:
    Measurement Mwind;
public:
    Wind(const QString&, double minWind = 0, double maxWind = 10);
    Wind(const Wind&);
    Measurement& getMwindAddress();
    Measurement getMwind() const;
    void updateValue()  override;
    QVector<QString> getNameValues() const override;
    void accept(Visitor &) override;
};

#endif
