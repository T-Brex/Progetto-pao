#ifndef SENSOR_PANEL_H
#define SENSOR_PANEL_H

#include <QString>
#include <QIcon>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "backend\sensors.h"

class SensorPanel: public QWidget {
    Q_OBJECT
private:
    QLabel* name;
    QLabel* type;
    QLabel* values;
    QLabel* valuesName;
    QLabel* ico;
    QPushButton* buttonModify;
    QPushButton* buttonDelete;

public:

    SensorPanel(const Sensor& s,QWidget* parent = 0);
    SensorPanel(const SensorPanel& s ,QWidget* parent = 0);
    QString getName();
    QString getType();
    QPushButton* getButtonModify() const { return buttonModify; }
    QPushButton* getButtonDelete() const { return buttonDelete; }
    static QWidget* getSensorsWidget(const QVector<SensorPanel*>& sp);

};
#endif






