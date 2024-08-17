#ifndef VISITOR_H
#define VISITOR_H

#include <QObject>
#include "sensors.h"

class Visitor : public QObject
{
    Q_OBJECT
public:
    virtual void visit(Dust&) = 0;
    virtual void visit(Wind&) = 0;
    virtual void visit(Termometer&) = 0;
    virtual void visit(Humidity&) = 0;
    virtual void visit(AirQuality&) = 0;
    explicit Visitor(QObject *parent = nullptr);

signals:
};

#endif // VISITOR_H
