#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include "frontend/searchMenu.h"
#include "frontend/sensorPanel.h"
#include "qscrollarea.h"
#include <QWidget>

class sensorWindow : public QWidget
{
    Q_OBJECT
public:
    QHBoxLayout* layout;

    QVector<SensorPanel*> sensorsPanels;
    QScrollArea *sensScrollArea;
    QWidget *sensWidget;
    QVBoxLayout *sensLayout;


    QVector<QWidget *> sensorsTypeWidget;
    QVector<QHBoxLayout *> sensorsTypeLayout;
    QWidget *dustWidget;
    QHBoxLayout *dustLayout;
    QWidget *humidityWidget;
    QHBoxLayout *humidityLayout;
    QWidget *windWidget;
    QHBoxLayout *windLayout;
    QWidget *termometerWidget;
    QHBoxLayout *termometerLayout;
    QWidget *airQualityWidget;
    QHBoxLayout *airQualityLayout;

    SearchMenu *searchMenu;
    explicit sensorWindow(QWidget *parent = nullptr);

public slots:
    void addSensor(Sensor *s);
    void modifySensor(const QString& oldName, const QString& newName, const QString& newType);
    void deleteSensor(QString s);
    void deleteAllSensors();
    void filterSensors(const QString& searchText);
signals:
};

#endif //SENSORWINDOW_H
