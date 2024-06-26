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
    QHBoxLayout* getLayout() const { return layout; }
    QVector<SensorPanel*>& getSensorsPanels() { return sensorsPanels; }
    QScrollArea* getScrollArea() const { return sensScrollArea; }
    QWidget* getSensorWidget() const { return sensWidget; }
    QVBoxLayout* getSensorLayout() const { return sensLayout; }

    QVector<QWidget *>& getSensorsTypeWidgets() { return sensorsTypeWidget; }
    QVector<QHBoxLayout *>& getSensorsTypeLayouts() { return sensorsTypeLayout; }
    QWidget* getDustWidget() const { return dustWidget; }
    QHBoxLayout* getDustLayout() const { return dustLayout; }
    QWidget* getHumidityWidget() const { return humidityWidget; }
    QHBoxLayout* getHumidityLayout() const { return humidityLayout; }
    QWidget* getWindWidget() const { return windWidget; }
    QHBoxLayout* getWindLayout() const { return windLayout; }
    QWidget* getTermometerWidget() const { return termometerWidget; }
    QHBoxLayout* getTermometerLayout() const { return termometerLayout; }
    QWidget* getAirQualityWidget() const { return airQualityWidget; }
    QHBoxLayout* getAirQualityLayout() const { return airQualityLayout; }

    SearchMenu* getSearchMenu() const { return searchMenu; }

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

#endif //SENSORWINDOW_H
