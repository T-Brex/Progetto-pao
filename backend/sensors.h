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
    virtual QVector<QString> getNameValues() const = 0;
    void modifyName(const QString&);
    QDateTime getCreationDate() const;
    virtual void updateValue() = 0 ;
<<<<<<< HEAD
    virtual ~Sensor();
    void updateType(const QString& s){type =s;}
    virtual QString getType() const {return type;}

=======
    //virtual ~Sensor();
    void updateType(const QString&);
    virtual QString getType() const;
>>>>>>> 2cd819f69459d430b2163cad621507adaf986d08
    virtual void accept(Visitor&) = 0;


};












#endif // SENSORS_H

