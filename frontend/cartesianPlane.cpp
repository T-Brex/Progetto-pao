#include "frontend/cartesianPlane.h"

CartesianPlane::CartesianPlane( QWidget *parent) : QWidget(parent) ,sensors (*new QVector<QPolygonF*>(10,nullptr)), dimFun(8000),zoom(1){

}

CartesianPlane::~CartesianPlane() {
    for (int i = 0; i < sensors.size(); ++i) {
        if (sensors[i]) {
            delete sensors[i];
            sensors[i] = nullptr;
        }
    }
}





void CartesianPlane::paintEvent(QPaintEvent *event){
        Q_UNUSED(event);

        QPainter painter(this);
        drawPlane(painter);

        QVector<QPolygonF*> zoomSensors;
        for (int i = 0; i < sensors.size(); i++) {
            if (sensors[i]) {
                QPolygonF *zoomedPoly = new QPolygonF(*sensors[i]); // Copia il poligono
                for (int j = 0; j < zoomedPoly->size(); j++) {
                    (*zoomedPoly)[j] *= zoom; // Moltiplica le coordinate per lo zoom
                }
                zoomSensors.append(zoomedPoly);
            } else {
                zoomSensors.append(nullptr);
            }
        }
        drawSensors(painter,zoomSensors);

        for (int i = 0; i < zoomSensors.size(); i++) {
            delete zoomSensors[i];
            zoomSensors[i] = nullptr;
        }

    }
void CartesianPlane::drawPlane(QPainter& painter) const{

    QPoint center = rect().center();
    painter.setPen(Qt::black);

    painter.drawLine(0, center.y(), width(), center.y()); // Asse x
    painter.drawText(width() - 20, center.y() - 5, "X");
    painter.drawLine(center.x(), 0, center.x(), height()); // Asse y
    painter.drawText(center.x() + 5, 15, "Y");


    int arrowSize = 5;    //frecce sugli assi
    painter.drawLine(width() - arrowSize, center.y() - arrowSize, width(), center.y());
    painter.drawLine(width() - arrowSize, center.y() + arrowSize, width(), center.y());
    painter.drawLine(center.x() - arrowSize, arrowSize, center.x(), 0);
    painter.drawLine(center.x() + arrowSize, arrowSize, center.x(), 0);




    double divisionSpacing = 25 * zoom;
    int lineCounter = 1;

    //linee di divisione sull'asse x
    for (int x = center.x() + divisionSpacing; x < width(); x += divisionSpacing) {
        if(zoom > 0.75){
            painter.drawLine(x, center.y() - 2, x, center.y() + 2);
            painter.drawText(x - 10, center.y() + 20, QString::number(lineCounter));
        } else {
            if (zoom > 0.45){
                if (lineCounter % 2 == 0) {
                    painter.drawLine(x, center.y() - 2, x, center.y() + 2);
                    painter.drawText(x - 10, center.y() + 20, QString::number(lineCounter));
                }
            } else {
                if (lineCounter % 3 == 0) {
                    painter.drawLine(x, center.y() - 2, x, center.y() + 2);
                    painter.drawText(x - 10, center.y() + 20, QString::number(lineCounter));
                }
            }
        }

        lineCounter++;
    }

    lineCounter = 1;//----------------------------------------------

    for (int x = center.x() - divisionSpacing; x > 0; x -= divisionSpacing) {
        if(zoom>0.75){
            painter.drawLine(x, center.y() - 2, x, center.y() + 2);
            painter.drawText(x - 10, center.y() + 20, QString::number(lineCounter));
        }else{
            if (zoom>0.45){
                if (lineCounter % 2 == 0) {
                    painter.drawLine(x, center.y() - 2, x, center.y() + 2);
                    painter.drawText(x - 10, center.y() + 20, QString::number(lineCounter));
                }
            }else{
                if (lineCounter % 3 == 0) {
                    painter.drawLine(x, center.y() - 2, x, center.y() + 2);
                    painter.drawText(x - 10, center.y() + 20, QString::number(lineCounter));
                }
            }

        }



        lineCounter++;
    }

    lineCounter = 1;//----------------------------------------------

    //linee di divisione sull'asse y
    for (int y = center.y() + divisionSpacing; y < height(); y += divisionSpacing) {
        if(zoom>0.75){
            painter.drawLine(center.x() - 2, y, center.x() + 2, y);
            painter.drawText(center.x() + 10, y + 5, QString::number(lineCounter));
        }else{
            if (zoom>0.45){
                if (lineCounter % 2 == 0) {
                    painter.drawLine(center.x() - 2, y, center.x() + 2, y);
                    painter.drawText(center.x() + 10, y + 5, QString::number(lineCounter));
                }
            }else{
                if (lineCounter % 3 == 0) {
                    painter.drawLine(center.x() - 2, y, center.x() + 2, y);
                    painter.drawText(center.x() + 10, y + 5, QString::number(lineCounter));
                }
            }

        }



        lineCounter++;
    }

    lineCounter = 1;//----------------------------------------------

    for (int y = center.y() - divisionSpacing; y > 0; y -= divisionSpacing) {
        if(zoom>0.75){
            painter.drawLine(center.x() - 2, y, center.x() + 2, y);
            painter.drawText(center.x() + 10, y + 5, QString::number(lineCounter));
        }else{
            if (zoom>0.45){
                if (lineCounter % 2 == 0) {
                    painter.drawLine(center.x() - 2, y, center.x() + 2, y);
                    painter.drawText(center.x() + 10, y + 5, QString::number(lineCounter));
                }
            }else{
                if (lineCounter % 3 == 0) {
                    painter.drawLine(center.x() - 2, y, center.x() + 2, y);
                    painter.drawText(center.x() + 10, y + 5, QString::number(lineCounter));
                }
            }

        }



        lineCounter++;
    }

}


void CartesianPlane::drawSensors(QPainter& painter, QVector<QPolygonF*> s) const {

        int hue=0;

        painter.translate(width() / 2, height() / 2);
        for (int i=0; i<s.size(); i++) {
            hue = (i * 360 / 15) % 360;

            QPen pen(QColor::fromHsv(hue, 255, 255));
            pen.setWidth(2);

            painter.setPen(pen);
            if(s[i])
                painter.drawPolyline(*s[i]);


        }

    }
    

    void CartesianPlane::addDust(const Dust &s, int i, int n) {
        double Y;

        QPolygonF *fun = new QPolygonF();
        Dust* d = new Dust(s);

        if(!i){
            for (int X = 0; X < dimFun; X+=50) {
                double sensorValue = d->getMpm10().getValue();

                Y = sensorValue * -1;
                d->updateValue();
                *fun << QPointF((X - dimFun / 2),( Y * 27));
            }

            if (n >= sensors.size()) {
                sensors.resize(n * 2, nullptr);
            }

            if (sensors[n]) {
                delete sensors[n];
            }

            sensors[n]= fun;
        }else{
            for (int X = 0; X < dimFun; X+=50) {
                double sensorValue = d->getMpm25().getValue();
                Y = sensorValue * -1;
                d->updateValue();
                *fun << QPointF((X - dimFun / 2),( Y * 27));
            }

            if (n >= sensors.size()) {
                sensors.resize(n * 2, nullptr);
            }

            if (sensors[n]) {
                delete sensors[n];
            }

            sensors[n]= fun;
        }
        delete(d);
        update();

    }

    void CartesianPlane::addWind(const Wind& s,int i, int n) {
        double Y;
        QPolygonF *fun = new QPolygonF();
        Wind* w = new Wind(s);
            for (int X = 0; X < dimFun; X+=50) {
                double sensorValue = w->getMwind().getValue();
                Y = sensorValue* -1;
                w->updateValue();
                *fun << QPointF((X - dimFun / 2),( Y * 27));
            }

            if (n >= sensors.size()) {
                sensors.resize(n * 2, nullptr);
            }

            if (sensors[n]) {
                delete sensors[n];
            }

            sensors[n]= fun;

        update();
        delete(w);
    }

    void CartesianPlane::addTermometer(const Termometer& s,int i, int n) {
        double Y;
        QPolygonF *fun = new QPolygonF();
        Termometer* t = new Termometer(s);
        for (int X = 0; X < dimFun; X+=50) {
            double sensorValue = t->getMtemperature().getValue();
            Y = sensorValue * -1;
            t->updateValue();
            *fun << QPointF((X - dimFun / 2),( Y * 27));
        }

        if (n >= sensors.size()) {
            sensors.resize(n * 2, nullptr);
        }

        if (sensors[n]) {
            delete sensors[n];
        }

        sensors[n]= fun;

        update();
        delete(t);
    }

    void CartesianPlane::addHumidity(const Humidity& s, int i, int n) {
        double Y;
        QPolygonF *fun = new QPolygonF();
        Humidity* h = new Humidity(s);
        if(!i){
            for (int X = 0; X < dimFun; X+=50) {
                double sensorValue = h->getMhumidity().getValue();
                Y = sensorValue * -1;
                h->updateValue();
                *fun << QPointF((X - dimFun / 2),( Y * 27));
            }

            if (n >= sensors.size()) {
                sensors.resize(n * 2, nullptr);
            }

            if (sensors[n]) {
                delete sensors[n];
            }

            sensors[n]= fun;
        }else{
            for (int X = 0; X < dimFun; X+=50) {
                double sensorValue = h->getMpercentage().getValue();
                Y = sensorValue * -1;
                h->updateValue();
                *fun << QPointF((X - dimFun / 2),( Y * 27));
            }

            if (n >= sensors.size()) {
                sensors.resize(n * 2, nullptr);
            }

            if (sensors[n]) {
                delete sensors[n];
            }

            sensors[n]= fun;
        }


        update();
        delete(h);
    }

    void CartesianPlane::addAirQuality(const AirQuality& s,int i, int n) {
        QPolygonF *fun = new QPolygonF();
        AirQuality* a = new AirQuality(s);
        for (int X = 0; X < dimFun; X+=50) {
            double Y = (a->getMquality().getValue())*-1;
            a->updateValue();
            *fun << QPointF((X - dimFun / 2),( Y * 27));
        }

        if (n >= sensors.size()) {
            sensors.resize(n * 2, nullptr);
        }

        if (sensors[n]) {
            delete sensors[n];
        }

        sensors[n]= fun;

        update();
        delete(a);
    }

    void CartesianPlane::removeSensor(int n){

        if (n >= 0 && n < sensors.size()) {
            delete sensors[n];
            sensors[n]=nullptr;
            update();
        }
    }


    void CartesianPlane::wheelEvent(QWheelEvent *event) {

        int delta = event->angleDelta().y();

            if (delta > 0) {
                // Zoom in
                zoom += 0.05;
            }else{
                // Zoom out
                zoom -= 0.05;
            }
            if(zoom<0.25){
                zoom=0.25;
        }
        update();
    }

