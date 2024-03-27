#include "frontend/sensorPanel.h"
#include <QLabel>
#include <QString>
SensorPanel::SensorPanel( const Sensor& s, QWidget* parent): QWidget(parent)
{

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    this->setMaximumSize(100,150);        // (w,h)
    this->setAutoFillBackground(true);
    QPalette pal = Qt::green;
    this->setPalette(pal);

    name = new QLabel ( QString::fromStdString(s.getName()));
    layout->addWidget(name);
    QPixmap icon(":resources/wind.ico");
    ico = new QLabel();
    ico->setPixmap(icon.scaledToHeight(50));
    layout->addWidget(ico);

    layout->addStretch();

    for(unsigned int i = 0; i<(s.getValue()).size(); i++){
        values = new QLabel( QString::number((s.getValue()[i])) );
        layout->addWidget(values);
    }




}

SensorPanel::SensorPanel(const SensorPanel& s, QWidget* parent): QWidget(parent), name(s.name), values(s.values), ico(s.ico){

}




//void SensorPanel::update(){aggiornare valori}
