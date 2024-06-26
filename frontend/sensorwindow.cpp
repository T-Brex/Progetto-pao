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
    sensScrollArea->setWidget(sensWidget);

    sensorsTypeWidget ={dustWidget,humidityWidget,windWidget,termometerWidget,airQualityWidget};
    sensorsTypeLayout ={dustLayout,humidityLayout,windLayout,termometerLayout,airQualityLayout};

    for(auto it=sensorsTypeLayout.begin();it!=sensorsTypeLayout.end();++it){
        (*it)->setAlignment(Qt::AlignLeft);
    }

    for(auto it=sensorsTypeWidget.begin();it!=sensorsTypeWidget.end();++it){
        QScrollArea *sensorScrollArea=new QScrollArea(nullptr);
        sensorScrollArea->setWidget(*it);
        sensorScrollArea->setWidgetResizable(true);
        sensorScrollArea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        sensorScrollArea->setMinimumHeight(350);
        (*it)->setPalette(Qt::white);
        (*it)->setAutoFillBackground(true);


        sensLayout->addWidget(sensorScrollArea);
    }

    QVector<Sensor*> sensors=Json::caricaSensori();
    for(auto it=sensors.begin();it!=sensors.end();++it){
        addSensor(*it);
    }


    layout->addWidget(searchMenu);
    layout->addWidget(sensScrollArea);
    this->setPalette(Qt::gray);



}



void sensorWindow::addSensor(Sensor *s) {
    sensorsPanels.push_back(new SensorPanel(*s));
    connect(sensorsPanels.last()->buttonModify,&QPushButton::clicked,this,[s, this]() {
        emit showModifyDialog(s);
    });
    connect(sensorsPanels.last()->buttonDelete,&QPushButton::clicked,this,[s, this]() {
        emit showDeleteWarning(s);
    });
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
void sensorWindow::deleteAllSensors() {
    for(auto it = sensorsPanels.begin(); it != sensorsPanels.end(); ) {
        // Rimuovi il widget dalla disposizione
        sensLayout->removeWidget(*it);
        sensLayout->update();

        // Dealloca il widget
        delete *it;

        // Rimuovi il puntatore dal vettore
        it = sensorsPanels.erase(it);
    }
}


void sensorWindow::modifySensor(const QString& oldName, const QString& newName, const QString& newType) {
    addSensor(Json::costruttore(newName, newType));
    deleteSensor(oldName);
    this->update();

}

void sensorWindow::filterSensors(const QString& searchText) {
    // Nascondi tutti i sensori
    for (auto layout : sensorsTypeLayout) {
        for (int i = 0; i < layout->count(); ++i) {
            layout->itemAt(i)->widget()->setVisible(false);
        }
    }

    // Mostra solo i sensori che corrispondono alla sottostringa
    for (auto panel : sensorsPanels) {
        if (panel->getName().contains(searchText, Qt::CaseInsensitive)) {
            // Trova l'indice del layout corrispondente al tipo di sensore
            int layoutIndex = -1;
            if (panel->getType() == "Dust") {
                layoutIndex = 0;
            } else if (panel->getType() == "Humidity") {
                layoutIndex = 1;
            } else if (panel->getType() == "Wind") {
                layoutIndex = 2;
            } else if (panel->getType() == "Termometer") {
                layoutIndex = 3;
            } else if (panel->getType() == "AirQuality") {
                layoutIndex = 4;
            }

            // Se è stato trovato un layout corrispondente, mostra il pannello
            if (layoutIndex != -1) {
                sensorsTypeLayout[layoutIndex]->addWidget(panel);
                panel->setVisible(true);
            }
        }
    }
}
