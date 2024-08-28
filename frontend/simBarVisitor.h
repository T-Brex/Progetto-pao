#ifndef SIMBARVISITOR_H
#define SIMBARVISITOR_H

#include "backend/visitor.h"
#include "qboxlayout.h"
#include "qwidget.h"
#include "backend/sensors.h"

class SimBarVisitor : public Visitor {
    Q_OBJECT
private:
    int &nButtons;
    int &colorCounter;
    QHBoxLayout &mainLayout;


public:
    SimBarVisitor(QHBoxLayout &mainLayout, int &nButtons, int &colorCounter);


    QWidget* getCreatedSlot() const;

    void visit(Dust &sensor) override;

    void visit(Wind &sensor) override;

    void visit(Termometer &sensor) override;

    void visit(Humidity &sensor) override;

    void visit(AirQuality &sensor) override;


signals:
    void addDust(const Dust& sensor, int i, int n);
    void addWind(const Wind& sensor, int i, int n);
    void addTermometer(const Termometer& sensor, int i, int n);
    void addHumidity(const Humidity& sensor, int i, int n);
    void addAirQuality(const AirQuality& sensor, int i, int n);
    void remove(int n);
    void updateDust(const Dust &s, int i, int n);
    void updateWind(const Wind &s, int i, int n);
    void updateTermometer(const Termometer &s, int i, int n);
    void updateHumidity(const Humidity &s, int i, int n);
    void updateAirQuality(const AirQuality &s, int i, int n);
};



#endif // SIMBARVISITOR_H
