#ifndef CARTESIANPLANE_H
#define CARTESIANPLANE_H
#include <QtWidgets>
#include <QPoint>
#include <QPainter>
#include <QPolygonF>
#include "backend/sensors.h"
class CartesianPlane : public QWidget {
private:
    //QPainter painter;
    QVector<QPolygonF*> sensors;
    int dim;
public:
    CartesianPlane(QWidget *parent = nullptr);
    CartesianPlane(const QVector<QPolygonF*> s,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void drawSensors(QPainter& painter);              //PER PAINTEVENT(): DISEGNA CARTESIANPLANE.SENSORS
    void addSensor(const Sensor * s);                //AGGIUNGERA' AL GRAFICO UN ALTRO SENSORE, COSTRUIRA' DA UN SENSORE UN ARRAY DI DIM QPOINT CON SENSOR::GETVALUE()
    void removeSensor(int i);             //RIMUOVERA' IL SENSORE SELEZIONATO
    void update();
};


#endif // CARTESIANPLANE_H
