#include "frontend/sensorPanel.h"
#include "backend/sensorgetter.h"
#include <QLabel>
#include <QString>

SensorPanel::SensorPanel(Sensor& sensor, QWidget* parent): QWidget(parent),buttonModify(new QPushButton("Modifica")),buttonDelete(new QPushButton("Elimina"))
{
    QVBoxLayout* layout = new QVBoxLayout(this); // Imposta il layout principale su questo widget

    QFrame* frame = new QFrame(this);

    frame->setAutoFillBackground(true);
    frame->setPalette(Qt::lightGray);

    QVBoxLayout* frameLayout = new QVBoxLayout(frame);
    frameLayout->setAlignment(Qt::AlignCenter);

    QWidget* infoWidget = new QWidget(frame);
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);

    QWidget* valuesWidget = new QWidget(frame);
    QVBoxLayout* valuesLayout = new QVBoxLayout(valuesWidget);


    // Aggiungi il frame al layout principale
    layout->addWidget(frame);

    // Aggiungi i widget necessari ai rispettivi layout
    name = new QLabel(sensor.getName());
    name->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(name);

    QString path(":resources/"+ sensor.getType() +".ico");
    QPixmap icon(path);
    ico = new QLabel();
    ico->setPixmap(icon.scaledToHeight(50));
    ico->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(ico);

    type = new QLabel(sensor.getType());
    type->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(type);

    QVector<Measurement*> measurements;
    SensorGetter sg(measurements);
    Sensor *ps(&sensor);
    ps->accept(sg);

    for(unsigned int i = 0; i < measurements.size(); i++){
        valuesName = new QLabel(measurements[i]->getName());
        values = new QLabel( QString::number(measurements[i]->getValue(),'f',1) );
        valuesName->setAlignment(Qt::AlignCenter);
        values->setAlignment(Qt::AlignCenter);

        QWidget* valueWidget = new QWidget;
        QHBoxLayout* valueLayout = new QHBoxLayout(valueWidget);
        valueLayout->addWidget(valuesName);
        valueLayout->addWidget(values);
        valuesLayout->addWidget(valueWidget);

    }


    // Aggiungi infoWidget e valuesWidget al frameLayout
    frameLayout->addWidget(infoWidget);
    frameLayout->addWidget(valuesWidget);
    valuesLayout->addWidget(buttonModify);
    valuesLayout->addWidget(buttonDelete);

}
QString SensorPanel::getName(){
    return name->text();
}
QString SensorPanel::getType(){
    return type->text();
}
SensorPanel::SensorPanel(const SensorPanel& s, QWidget* parent): QWidget(parent), name(s.name), values(s.values), ico(s.ico){

}


QWidget* SensorPanel::getSensorsWidget(const QVector<SensorPanel*>& sp){

    QWidget *panels = new QWidget;
    QVBoxLayout* panelsLayout = new QVBoxLayout(panels);

    for(auto i=0;i<sp.size();i++){
        panelsLayout->addWidget(sp[i]);
    }
    return panels;
}
