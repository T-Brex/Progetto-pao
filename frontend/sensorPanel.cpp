#include "frontend/sensorPanel.h"
#include <QLabel>
#include <QString>

SensorPanel::SensorPanel( const Sensor& sensor, QWidget* parent): QWidget(parent)
{

    QVBoxLayout* layout = new QVBoxLayout(this);


    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    this->setMaximumSize(300,300);        // (w,h)
    this->setAutoFillBackground(true);
    QPalette pal = Qt::green;
    this->setPalette(pal);
    name = new QLabel ( QString::fromStdString(sensor.getName()));
    layout->addWidget(name);
    QString path(":resources/"+ QString::fromStdString(sensor.getType()) +".ico");
    QPixmap icon(path);
    ico = new QLabel();
    ico->setPixmap(icon.scaledToHeight(50));
    layout->addWidget(ico);


    layout->addWidget(new QLabel(QString::fromStdString(sensor.getType())));
    layout->addStretch();

    values = new QLabel( QString::number((sensor.getValue()[0])) );
    layout->addWidget(values);
    for(unsigned int i = 1; i<(sensor.getValue()).size(); i++){
        values = new QLabel( QString::number((sensor.getValue()[i])) );
        layout->addWidget(values);
    }




}

SensorPanel::SensorPanel(const SensorPanel& s, QWidget* parent): QWidget(parent), name(s.name), values(s.values), ico(s.ico){

}


QWidget* SensorPanel::getSensorsWidget(QVector<SensorPanel*> sp){

    QWidget *panels = new QWidget;
    QHBoxLayout* panelsLayout = new QHBoxLayout(panels);

    for(auto i=0;i<sp.size();i++){
        panelsLayout->addWidget(sp[i]);
    }
    return panels;
}


//void SensorPanel::update(){aggiornare valori}
