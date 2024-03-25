#ifndef INFOPANEL_H
#define INFOPANEL_H
#include "backend/sensors.h"
#include <QLabel>
class InfoPanel: public QWidget {
    Q_OBJECT
private:



public:
    InfoPanel(Sensor* s, QWidget* parent = 0);
    void show();
};


#endif // INFOPANEL_H
