#ifndef SENSORVISIBILITY_H
#define SENSORVISIBILITY_H

#include <backend/visitor.h>
#include "backend/sensors.h"

class SensorVisibility : public Visitor
{
    Q_OBJECT
private:
    int *index;
public:
    explicit SensorVisibility(QObject *parent = nullptr);
    SensorVisibility(int&);
    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);
};

#endif // SENSORVISIBILITY_H
