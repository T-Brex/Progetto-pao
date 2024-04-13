#include "frontend/sensorPanel.h"
#include <QLabel>
#include <QString>

SensorPanel::SensorPanel( const Sensor& sensor, QWidget* parent): QWidget(parent)
{

    QHBoxLayout* layout = new QHBoxLayout(this);


    layout->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
/*
    QFrame* frame = new QFrame(this);
    frame->setLayout(layout);
    frame->setAutoFillBackground(true);
    frame->setPalette(Qt::blue);
*/
    this->setMaximumSize(300,75);        // (w,h)
    this->setAutoFillBackground(true);
    this->setPalette(Qt::lightGray);

    name = new QLabel (sensor.getName());
    name->setAlignment(Qt::AlignCenter);
    layout->addWidget(name);

    QString path(":resources/"+ sensor.getType() +".ico");
    QPixmap icon(path);
    ico = new QLabel();
    ico->setPixmap(icon.scaledToHeight(50));
    ico->setAlignment(Qt::AlignCenter);
    layout->addWidget(ico);

    QLabel* sensorType = new QLabel(sensor.getType());
    sensorType->setAlignment(Qt::AlignCenter);
    layout->addWidget(sensorType);
    //layout->addStretch();

    values = new QLabel( QString::number((sensor.getValue()[0])) );
    values->setAlignment(Qt::AlignCenter);
    layout->addWidget(values);

    for(unsigned int i = 1; i<(sensor.getValue()).size(); i++){
        values = new QLabel( QString::number((sensor.getValue()[i])) );
        values->setAlignment(Qt::AlignCenter);
        layout->addWidget(values);
    }
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


//void SensorPanel::update(){aggiornare valori}
