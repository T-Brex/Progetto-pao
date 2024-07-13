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

    QVector<QPolygonF*> sensors;
    int dimFun;
    double zoom;
public:
    CartesianPlane(QWidget *parent = nullptr);
    CartesianPlane(const QVector<QPolygonF*> s,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void drawPlane(QPainter& painter) const;
    void drawSensors(QPainter& painter,QVector<QPolygonF*> s) const;
    void addSensor(Sensor * s, int i, int n);
    void removeSensor(int n);
    void wheelEvent(QWheelEvent *event) ;
    ~CartesianPlane();


};


#endif
