#ifndef MEASUREMENTSETTER_H
#define MEASUREMENTSETTER_H


#include "qjsonobject.h"
#include "visitor.h"
#include "backend/visitor.h"
#include "backend/dustSensor.h"
#include "backend/humiditySensor.h"
#include "backend/termometerSensor.h"
#include "backend/windSensor.h"
#include "backend/airQualitySensor.h"

class MeasurementSetter : public Visitor
{
    Q_OBJECT
private:
    QJsonObject &sensoreObject;
public:
    MeasurementSetter(QJsonObject&,Visitor *parent=nullptr);

    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);
};

#endif // MEASUREMENTSETTER_H
