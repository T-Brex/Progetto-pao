#ifndef CARTESIANPLANE_H
#define CARTESIANPLANE_H
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPolygonF>
#include "backend/sensors.h"
#include <QWheelEvent>
class CartesianPlane : public QWidget {
    Q_OBJECT
private:
    //QPainter painter;
    QVector<QPolygonF*> sensors;
    int dimFun;
    double zoom;
public:
    CartesianPlane(QWidget *parent = nullptr);
    CartesianPlane(const QVector<QPolygonF*> s,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void drawPlane(QPainter& painter) const;
    void drawSensors(QPainter& painter,QVector<QPolygonF*> s) const;              //PER PAINTEVENT(): DISEGNA CARTESIANPLANE.SENSORS
    void addSensor(Sensor * s, int i, int n);                //AGGIUNGERA' AL GRAFICO UN ALTRO SENSORE, COSTRUIRA' DA UN SENSORE UN ARRAY DI DIM QPOINT CON SENSOR::GETVALUE()
    void removeSensor(int n);             //RIMUOVERA' IL SENSORE SELEZIONATO
    void wheelEvent(QWheelEvent *event) ;
    ~CartesianPlane();


};


#endif // CARTESIANPLANE_H
