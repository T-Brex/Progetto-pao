#include "sensorlayoutchooser.h"

SensorLayoutChooser::SensorLayoutChooser(QObject *parent)
    : Visitor{parent}
{}
SensorLayoutChooser::SensorLayoutChooser(sensorWindow& SW):sw(&SW){}
void SensorLayoutChooser::visit(Dust&){
    sw->getDustLayout()->addWidget(sw->getSensorsPanels().last());
}
void SensorLayoutChooser::visit(Wind&){
    sw->getWindLayout()->addWidget(sw->getSensorsPanels().last());
}
void SensorLayoutChooser::visit(Termometer&){
    sw->getTermometerLayout()->addWidget(sw->getSensorsPanels().last());
}
void SensorLayoutChooser::visit(Humidity&){
    sw->getHumidityLayout()->addWidget(sw->getSensorsPanels().last());
}
void SensorLayoutChooser::visit(AirQuality&){
    sw->getAirQualityLayout()->addWidget(sw->getSensorsPanels().last());
}
