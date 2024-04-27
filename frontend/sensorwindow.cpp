#include "sensorwindow.h"
#include "backend/json.h"
#include <QScrollBar>

sensorWindow::sensorWindow(QWidget *parent)
    : QWidget(parent),

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
    auto *vScrollBar=sensScrollArea->verticalScrollBar();
    vScrollBar->setStyleSheet("QScrollBar:vertical { background-color: yellow; }");

    sensScrollArea->setWidget(sensWidget);

    sensorsTypeWidget.push_back(dustWidget);
    sensorsTypeWidget.push_back(humidityWidget);
    sensorsTypeWidget.push_back(windWidget);
    sensorsTypeWidget.push_back(termometerWidget);
    sensorsTypeWidget.push_back(airQualityWidget);

    sensorsTypeLayout.push_back(dustLayout);
    sensorsTypeLayout.push_back(humidityLayout);
    sensorsTypeLayout.push_back(windLayout);
    sensorsTypeLayout.push_back(termometerLayout);
    sensorsTypeLayout.push_back(airQualityLayout);

    for(auto it=sensorsTypeLayout.begin();it!=sensorsTypeLayout.end();++it){
        (*it)->setAlignment(Qt::AlignLeft);
        //(*it)->totalMinimumHeightForWidth()
    }
    //FARE GLI ALTRI



    for(auto it=sensorsTypeWidget.begin();it!=sensorsTypeWidget.end();++it){
        QScrollArea *sensorScrollArea=new QScrollArea(nullptr);
        sensorScrollArea->setWidget(*it);
        sensorScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sensorScrollArea->setWidgetResizable(true);
        sensorScrollArea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

        //auto *hScrollBar=sensorScrollArea->verticalScrollBar();
        //hScrollBar->setStyleSheet("QScrollBar:horizontal  { background-color: yellow; }");

        sensLayout->addWidget(sensorScrollArea);
    }

    QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=sensors.begin();it!=sensors.end();++it){
        addSensor(*it);
    }


    //searchMenu->set
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

