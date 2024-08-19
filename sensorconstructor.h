#ifndef SENSORCONSTRUCTOR_H
#define SENSORCONSTRUCTOR_H

#include <backend/visitor.h>

class sensorConstructor : public Visitor
{
    Q_OBJECT
private:
    QString name;
    Sensor **sensor;
public:
    explicit sensorConstructor(QObject *parent = nullptr);
    sensorConstructor(QString, Sensor *);
    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);
};

#endif // SENSORCONSTRUCTOR_H
