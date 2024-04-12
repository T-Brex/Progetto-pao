#include "frontend/cartesianPlane.h"
CartesianPlane::CartesianPlane( QWidget *parent) : QWidget(parent) ,dim(20){}
CartesianPlane::CartesianPlane(const QVector<QPolygonF*> s, QWidget *parent) : QWidget(parent) ,sensors(s) ,dim(20){}


void CartesianPlane::paintEvent(QPaintEvent *event){
        Q_UNUSED(event);
        QPainter painter(this);
        // Definisci il centro del piano cartesiano
        QPoint center = rect().center();

        // Disegna gli assi x e y
        painter.drawLine(0, center.y(), width(), center.y()); // Asse x
        painter.drawLine(center.x(), 0, center.x(), height()); // Asse y

        // Disegna le frecce sugli assi
        int arrowSize = 5;
        painter.drawLine(width() - arrowSize, center.y() - arrowSize, width(), center.y());
        painter.drawLine(width() - arrowSize, center.y() + arrowSize, width(), center.y());
        painter.drawLine(center.x() - arrowSize, arrowSize, center.x(), 0);
        painter.drawLine(center.x() + arrowSize, arrowSize, center.x(), 0);

        // Disegna i numeri sugli assi
        painter.drawText(center.x() + 5, 15, "Y");
        painter.drawText(width() - 20, center.y() - 5, "X");

        // Disegna le linee di divisione sull'asse x
        int divisionSpacing = 25;
        for (int x = center.x() + divisionSpacing; x < width(); x += divisionSpacing) {
            painter.drawLine(x, center.y() - 2, x, center.y() + 2);
            painter.drawText(x - 10, center.y() + 20, QString::number((x - center.x()) / divisionSpacing));
        }
        for (int x = center.x() - divisionSpacing; x > 0; x -= divisionSpacing) {
            painter.drawLine(x, center.y() - 2, x, center.y() + 2);
            painter.drawText(x - 10, center.y() + 20, QString::number((x - center.x()) / divisionSpacing));
        }

        // Disegna le linee di divisione sull'asse y
        for (int y = center.y() + divisionSpacing; y < height(); y += divisionSpacing) {
            painter.drawLine(center.x() - 2, y, center.x() + 2, y);
            painter.drawText(center.x() + 10, y + 5, QString::number((center.y() - y) / divisionSpacing));
        }
        for (int y = center.y() - divisionSpacing; y > 0; y -= divisionSpacing) {
            painter.drawLine(center.x() - 2, y, center.x() + 2, y);
            painter.drawText(center.x() + 10, y + 5, QString::number((center.y() - y) / divisionSpacing));
        }
        if(sensors.size()>0)
            drawSensors(painter);
        /*//disegnare punti
        painter.setPen(Qt::red);
        for (int i=0;i<sensors.size();i++){
            sensors.drawSensors(painter);
            //painter.drawPoint(center.x() +i,center.y() - i);
        }*/
    }


    void CartesianPlane::drawSensors(QPainter& painter) {
        //points.push_front(point);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::red);
        for(int i=0; i<sensors.size();i++){
                painter.drawPolyline(*sensors[i]);
        }
        //painter.drawPoint(rect() ,);
        //update(); // Richiama paintEvent per ridisegnare il piano con il nuovo punto
    }

    void CartesianPlane::addSensor(const Sensor * s){
        QPolygonF *fun = new QPolygonF();
        int Y[dim];

        for(int i=0; i<dim;i++){
            Y[i]=s->getRandomNumber();
            *fun << QPointF(i*20,Y[i]*20);
        }
        sensors.push_front(fun);
    }

    void CartesianPlane::removeSensor(int i){


    }


