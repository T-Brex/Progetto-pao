#ifndef VISITOR_H
#define VISITOR_H

#include <QObject>
class Dust;
class Wind;
class Termometer;
class Humidity;
class AirQuality;

class Visitor : public QObject
{
    Q_OBJECT
public:
    explicit Visitor(QObject *parent = nullptr);
    virtual void visit(Dust&) = 0;
    virtual void visit(Wind&) = 0;
    virtual void visit(Termometer&) = 0;
    virtual void visit(Humidity&) = 0;
    virtual void visit(AirQuality&) = 0;
    virtual ~Visitor(){}

signals:
};

#endif
