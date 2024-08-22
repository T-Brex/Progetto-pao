#ifndef SENSORLAYOUTCHOOSER_H
#define SENSORLAYOUTCHOOSER_H

#include "backend/visitor.h"
#include "sensorwindow.h"

class SensorLayoutChooser : public Visitor
{
    Q_OBJECT
private:
    sensorWindow *sw;
public:
    explicit SensorLayoutChooser(QObject *parent = nullptr);
    SensorLayoutChooser(sensorWindow&);
    void visit(Dust&);
    void visit(Wind&);
    void visit(Termometer&);
    void visit(Humidity&);
    void visit(AirQuality&);
};
#endif // SENSORLAYOUTCHOOSER_H
