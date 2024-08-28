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
    void removeSensor(int n);
    void wheelEvent(QWheelEvent *event) ;
    ~CartesianPlane();
public slots:
    void addDust(const Dust& s, int i, int n);
    void addWind(const Wind& s, int i, int n);
    void addTermometer(const Termometer& s, int i, int n);
    void addHumidity(const Humidity& s, int i, int n);
    void addAirQuality(const AirQuality& s, int i, int n);


};


#endif
