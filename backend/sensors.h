#ifndef SENSORS_H
#define SENSORS_H
#include <QDateTime>
#include <QString>
#include <QVector>
#include "backend/visitor.h"

class Visitor;
class Sensor{
private:
    QString name;
    QString type;
    QDateTime creationDate;
public:
    Sensor(const QString&);
    const QString& getName() const;
    void setName(const QString&);
    QDateTime getCreationDate() const;
    virtual void updateValue() = 0 ;
<<<<<<< HEAD
    virtual ~Sensor();
    void updateType(const QString& s);
=======

    virtual ~Sensor();
    void updateType(const QString&);
>>>>>>> 89224e0cdad36821b178c40e5e6c7d4f59df6551
    virtual QString getType() const;
    virtual void accept(Visitor&) = 0;


};












#endif // SENSORS_H

