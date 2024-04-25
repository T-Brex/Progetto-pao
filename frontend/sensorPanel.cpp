#include "frontend/sensorPanel.h"
#include <QLabel>
#include <QString>

SensorPanel::SensorPanel( const Sensor& sensor, QWidget* parent): QWidget(parent)
{


    QFrame* frame = new QFrame(this);
    //frame->setLayout(layout());
    //frame->setAutoFillBackground(true);
    //frame->setPalette(Qt::blue);


    QVBoxLayout* layout = new QVBoxLayout(frame);

    QWidget* infoWidget=new QWidget;
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);

    QWidget* valuesWidget=new QWidget;
    QVBoxLayout* valuesLayout = new QVBoxLayout(valuesWidget);





    layout->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)

    this->setMinimumHeight(210);        // (w,h)
    this->setAutoFillBackground(true);
    this->setPalette(Qt::lightGray);

    name = new QLabel (sensor.getName());
    name->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(name);

    QString path(":resources/"+ sensor.getType() +".ico");
    QPixmap icon(path);
    ico = new QLabel();
    ico->setPixmap(icon.scaledToHeight(50));
    ico->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(ico);

    QLabel* sensorType = new QLabel(sensor.getType());
    sensorType->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(sensorType);
    //layout->addStretch();

    layout->addWidget(infoWidget);
    auto valuesList = sensor.getValue();
    auto namesList = sensor.getNameValues();

    for(unsigned int i = 0; i < valuesList.size(); i++){
        valuesName = new QLabel(namesList[i]);
        values = new QLabel( QString::number(valuesList[i]) );
        valuesName->setAlignment(Qt::AlignCenter);
        values->setAlignment(Qt::AlignCenter);
        QWidget* valueWidget=new QWidget;
        QHBoxLayout* valueLayout = new QHBoxLayout(valueWidget);
        valueLayout->addWidget(valuesName);
        valueLayout->addWidget(values);
        valuesLayout->addWidget(valueWidget);
    }
        layout->addWidget(valuesWidget);

}
QString SensorPanel::getName(){
    return name->text();
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
