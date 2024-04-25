#include "frontend/cartesianPlane.h"

CartesianPlane::CartesianPlane( QWidget *parent) : QWidget(parent) ,sensors (*new QVector<QPolygonF*>(10,nullptr)), dimFun(500),zoom(1){
    //setMinimumSize(400, 400);
    //this->setStyleSheet("background-color: lightblue;");
    //this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);



}
CartesianPlane::CartesianPlane(const QVector<QPolygonF*> s, QWidget *parent) : QWidget(parent) ,sensors(s) ,dimFun(500){}


void CartesianPlane::paintEvent(QPaintEvent *event){
        Q_UNUSED(event);

        QPainter painter(this);
        drawPlane(painter);
        //painter.setRenderHint(QPainter::Antialiasing);

        //painter.translate(width() / 2, height() / 2); // Centra il piano cartesiano

        //for(int i=0; i<sensors.size();i++){
            //painter.drawPolyline(*sensors[i]);
        //}
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
        }

    }
void CartesianPlane::drawPlane(QPainter& painter){
    QPoint center = rect().center();
    painter.setPen(Qt::black);
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
    double divisionSpacing = 25 * zoom;
    for (int x = center.x() + divisionSpacing; x < width(); x += divisionSpacing) {
        painter.drawLine(x, center.y() - 2, x, center.y() + 2);
        painter.drawText(x - 10, center.y() + 20, QString::number(round((x - center.x()) / divisionSpacing)));
    }
    for (int x = center.x() - divisionSpacing; x > 0; x -= divisionSpacing) {
        painter.drawLine(x, center.y() - 2, x, center.y() + 2);
        painter.drawText(x - 10, center.y() + 20, QString::number(round((x - center.x()) / divisionSpacing)));
    }

    // Disegna le linee di divisione sull'asse y
    for (int y = center.y() + divisionSpacing; y < height(); y += divisionSpacing) {
        painter.drawLine(center.x() - 2, y, center.x() + 2, y);
        painter.drawText(center.x() + 10, y + 5, QString::number(round((center.y() - y) / divisionSpacing)));
    }
    for (int y = center.y() - divisionSpacing; y > 0; y -= divisionSpacing) {
        painter.drawLine(center.x() - 2, y, center.x() + 2, y);
        painter.drawText(center.x() + 10, y + 5, QString::number(round((center.y() - y) / divisionSpacing)));
    }

}


    void CartesianPlane::drawSensors(QPainter& painter, QVector<QPolygonF*> s) {

        int hue=0;
        //for(int i=0; i<sensors.size();i++){
           // painter.drawPolyline(*sensors[i]);
        //}
        painter.translate(width() / 2, height() / 2);
        for (int i=0; i<s.size(); i++) {
            hue = (i * 360 / 15) % 360; // Variazione dell'indice di tonalità

            painter.setPen(QColor::fromHsv(hue, 255, 255));
            if(s[i])
                painter.drawPolyline(*s[i]);

            //painter.drawPolygon(*polygon);
        }

    }
    
    void CartesianPlane::addSensor(Sensor *s, int i, int n){
        double Y;
            QPolygonF *fun = new QPolygonF();

            for (int X = 0; X < dimFun; X+=25) {
                Y = s->getValue()[i];
                s->updateValue();
                *fun << QPointF((X - dimFun / 2),( Y * 20));
            }

            if (n >= sensors.size()) {
                sensors.resize(n * 2, nullptr);
            }

            if (sensors[n]) {
                delete sensors[n];
            }
            // Inserisci il nuovo elemento nella posizione n
            sensors[n]= fun;

        update();

        }

    void CartesianPlane::removeSensor(int n){

        if (n >= 0 && n < sensors.size()) {

            sensors[n]=nullptr;
            update();
        }
    }


    void CartesianPlane::wheelEvent(QWheelEvent *event) {

        int delta = event->angleDelta().y(); // Ottieni la variazione dell'angolo dalla rotella del mouse

            if (delta > 0) {
                // Zoom in
                zoom += 0.05; // Aumenta la dimensione della funzione
            } else {
                // Zoom out
                zoom -= 0.05; // Diminuisci la dimensione della funzione
            }
            if(zoom<0.60){
                zoom=0.60;
        }
        update(); // Aggiorna il widget per visualizzare il cambiamento
        //event->accept(); // Accetta l'evento per impedire il passaggio ad altri widget
    }

