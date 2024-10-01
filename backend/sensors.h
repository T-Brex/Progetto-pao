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


    virtual ~Sensor();
    void updateType(const QString&);

    virtual QString getType() const;
    virtual void accept(Visitor&) = 0;


};












#endif // SENSORS_H

