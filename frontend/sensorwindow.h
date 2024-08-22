#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include "frontend/searchMenu.h"
#include "frontend/sensorPanel.h"
#include "qscrollarea.h"
#include <QWidget>

class sensorWindow : public QWidget
{
    Q_OBJECT
private:
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
public:

    explicit sensorWindow(QWidget *parent = nullptr);

    QHBoxLayout* getLayout() const;
    QVector<SensorPanel*>& getSensorsPanels();
    SearchMenu* getSearchMenu() const;
    QScrollArea* getScrollArea() const;
    QWidget* getSensorWidget() const;
    QVBoxLayout* getSensorLayout() const;
    QVector<QWidget *>& getSensorsTypeWidgets();
    QVector<QHBoxLayout *>& getSensorsTypeLayouts();
    QWidget* getDustWidget() const;
    QHBoxLayout* getDustLayout() const;
    QWidget* getHumidityWidget() const;
    QHBoxLayout* getHumidityLayout() const;
    QWidget* getWindWidget() const;
    QHBoxLayout* getWindLayout() const;
    QWidget* getTermometerWidget() const;
    QHBoxLayout* getTermometerLayout() const;
    QWidget* getAirQualityWidget() const;
    QHBoxLayout* getAirQualityLayout() const;


public slots:
    void addSensor(Sensor *s);
    void modifySensor(const QString& oldName, const QString& newName, const QString& newType);
    void deleteSensor(QString s);
    void deleteAllSensors();
    void filterSensors(const QString& searchText);
signals:
    void showModifyDialog(Sensor* s);
    void showDeleteWarning(Sensor* s);

};

#endif
