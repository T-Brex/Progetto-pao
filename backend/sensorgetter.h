#ifndef SENSORGETTER_H
#define SENSORGETTER_H

#include "visitor.h"
#include "sensors.h"

class SensorGetter : public Visitor
{
    Q_OBJECT
private:
    QVector<Measurement*> *measurementVec;
public:
    explicit SensorGetter(QObject *parent = nullptr);
    SensorGetter(QVector<Measurement*> &);
    SensorGetter(Measurement);
    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);
};

#endif // SENSORGETTER_H
