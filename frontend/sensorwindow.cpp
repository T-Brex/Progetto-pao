#include "sensorwindow.h"
#include "backend/json.h"

sensorWindow::sensorWindow(QWidget *parent)
    : QWidget(parent),
    //sensWindow(new QWidget),
    layout(new QHBoxLayout(this)),
    sensScrollArea(new QScrollArea()),sensWidget(new QWidget()),sensLayout(new QVBoxLayout(sensWidget)),
    dustWidget(new QWidget), dustLayout(new QHBoxLayout(dustWidget)),
    humidityWidget(new QWidget), humidityLayout(new QHBoxLayout(humidityWidget)),
    windWidget(new QWidget), windLayout(new QHBoxLayout(windWidget)),
    termometerWidget(new QWidget), termometerLayout(new QHBoxLayout(termometerWidget)),
    airQualityWidget(new QWidget), airQualityLayout(new QHBoxLayout(airQualityWidget)),
    searchMenu(new SearchMenu(nullptr))
{
    sensScrollArea->setWidgetResizable(true);
    sensScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sensScrollArea->setWidget(sensWidget);

    sensLayout->addWidget(dustWidget);
    sensLayout->addWidget(humidityWidget);
    sensLayout->addWidget(windWidget);
    sensLayout->addWidget(termometerWidget);
    sensLayout->addWidget(airQualityWidget);

    QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=sensors.begin();it!=sensors.end();++it){
        addSensor(*it);
    }

    layout->addWidget(searchMenu);
    layout->addWidget(sensScrollArea);
}



void sensorWindow::addSensor(Sensor *s) {
    sensorsPanels.push_back(new SensorPanel(*s));

    if(s->getType()=="Dust")
        dustLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="Humidity")
        humidityLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="Wind")
        windLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="Termometer")
        termometerLayout->addWidget(sensorsPanels.last());
    if(s->getType()=="AirQuality")
        airQualityLayout->addWidget(sensorsPanels.last());
}
void sensorWindow::deleteSensor(QString s) {
    for(auto it = sensorsPanels.begin(); it != sensorsPanels.end(); ++it) {
        if((*it)->getName() == s) {
            // Rimuovi il widget dalla disposizione
            sensLayout->removeWidget(*it);
            sensLayout->update();
            // Dealloca il widget
            delete *it;
            // Rimuovi il puntatore dal vettore
            it = sensorsPanels.erase(it);


            // Assicurati di non superare la fine del vettore
            if (it == sensorsPanels.end())
                break;

        }
    }

}

