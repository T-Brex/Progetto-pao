#include "frontend/sensorPanel.h"

SensorPanel::SensorPanel(const Sensor& s,const std::string& iconPath = "resources/defaultIcon.boh")
    : info(s.getValue()){/*assegnare icona*/}

SensorPanel::update(){/*aggiornare valori}


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
