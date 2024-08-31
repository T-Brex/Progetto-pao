#ifndef DEEPSENSORGETTER_H
#define DEEPSENSORGETTER_H

#include "backend/measurement.h"
#include "visitor.h"

#include "backend/visitor.h"
#include "backend/dustSensor.h"
#include "backend/humiditySensor.h"
#include "backend/termometerSensor.h"
#include "backend/windSensor.h"
#include "backend/airQualitySensor.h"

class DeepSensorGetter : public Visitor
{
    Q_OBJECT
private:
    QVector<Measurement*> &measurementVec;
public:
    explicit DeepSensorGetter(QObject *parent = nullptr);
    DeepSensorGetter(QVector<Measurement*> &);
    //DeepSensorGetter(Measurement);
    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);

};

#endif
