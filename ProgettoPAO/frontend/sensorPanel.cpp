#include "frontend/sensorPanel.h"
#include <QLabel>

SensorPanel::SensorPanel(QWidget* parent): QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QPushButton *button1 = new QPushButton("One");
    layout->addWidget(button1);
    layout->addStretch();
    QPushButton *button2 = new QPushButton("Two");
    layout->addWidget(button2);
}
//SensorPanel::SensorPanel(const Sensor& s,const std::string& iconPath i){}
/*
void SensorPanel::update(){aggiornare valori}


class SensorPanel: public QWidget {
    Q_OBJECT
private:
    double* info;//inizializzzare con getValue
    QVBoxLayout* mainLayout;
    QIcon* icon;
    QPushButton* refresh;
public:
    SensorPanel(const Sensor&,const std::string& iconPath = "resources/defaultIcon.boh");
    void update();
};*/
