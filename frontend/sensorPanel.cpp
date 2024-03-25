#include "frontend/sensorPanel.h"
#include <QLabel>

SensorPanel::SensorPanel(QWidget* parent): QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QPushButton *edit = new QPushButton("edit");
    layout->addWidget(edit);
    QPushButton *del = new QPushButton("delete");
    layout->addWidget(del);
    layout->addStretch();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    name= new QLabel("name");
    layout->addWidget(name);
    value = new QLabel("value");
    layout->addWidget(value);
    layout->setContentsMargins(5,5,5,5);
    this->setMaximumSize(100,100);
    this->setAutoFillBackground(true);
    QPalette pal = Qt::green;
    this->setPalette(pal);
}
SensorPanel::SensorPanel(const SensorPanel& s, QWidget* parent){

}

//void SensorPanel::update(){aggiornare valori}
