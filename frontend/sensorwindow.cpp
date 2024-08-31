#include "sensorwindow.h"
#include "backend/deepsensorgetter.h"
#include "backend/json.h"
#include <QScrollBar>
#include "SensorLayoutChooser.h"
#include "backend/measurement.h"
#include "backend/sensorgetter.h"

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
    connect(sensorsPanels.last()->getButtonModify(),&QPushButton::clicked,this,[s, this]() {
        emit showModifyDialog(s);
    });
    connect(sensorsPanels.last()->getButtonDelete(),&QPushButton::clicked,this,[s, this]() {
        emit showDeleteWarning(s);
    });

    SensorLayoutChooser slc(*this);
    s->accept(slc);
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


void sensorWindow::modifySensor(const QString& oldName, const QString& newName) {

    Sensor* newSensor=Json::trovaSensorePerNome(newName);
    deleteSensor(oldName);
    addSensor(newSensor);
    this->update();

}

void sensorWindow::filterSensors(const QString& searchText) {

    // Mostra solo i sensori che corrispondono alla sottostringa
    for (auto panel : sensorsPanels) {
        if (!panel->getName().contains(searchText, Qt::CaseInsensitive)) {
            panel->setVisible(false);
        }
        else{
            panel->setVisible(true);
        }
    }

}
QHBoxLayout* sensorWindow::getLayout() const { return layout; }
QVector<SensorPanel*>& sensorWindow::getSensorsPanels() { return sensorsPanels; }
SearchMenu* sensorWindow::getSearchMenu() const { return searchMenu; }
QScrollArea* sensorWindow::getScrollArea() const { return sensScrollArea; }
QWidget* sensorWindow::getSensorWidget() const { return sensWidget; }
QVBoxLayout* sensorWindow::getSensorLayout() const { return sensLayout; }
QVector<QWidget *>& sensorWindow::getSensorsTypeWidgets() { return sensorsTypeWidget; }
QVector<QHBoxLayout *>& sensorWindow::getSensorsTypeLayouts() { return sensorsTypeLayout; }
QWidget* sensorWindow::getDustWidget() const { return dustWidget; }
QHBoxLayout* sensorWindow::getDustLayout() const { return dustLayout; }
QWidget* sensorWindow::getHumidityWidget() const { return humidityWidget; }
QHBoxLayout* sensorWindow::getHumidityLayout() const { return humidityLayout; }
QWidget* sensorWindow::getWindWidget() const { return windWidget; }
QHBoxLayout* sensorWindow::getWindLayout() const { return windLayout; }
QWidget* sensorWindow::getTermometerWidget() const { return termometerWidget; }
QHBoxLayout* sensorWindow::getTermometerLayout() const { return termometerLayout; }
QWidget* sensorWindow::getAirQualityWidget() const { return airQualityWidget; }
QHBoxLayout* sensorWindow::getAirQualityLayout() const { return airQualityLayout; }
