#ifndef SENSORVISIBILITY_H
#define SENSORVISIBILITY_H

#include <backend/visitor.h>
#include "backend/sensors.h"

class SensorVisibility : public Visitor
{
    Q_OBJECT
public:
    explicit SensorVisibility(QObject *parent = nullptr);
    int visit(Dust&);
    int visit(Wind&);
    int visit(Termometer&);
    int visit(Humidity&);
    int visit(AirQuality&);
};

#endif // SENSORVISIBILITY_H
