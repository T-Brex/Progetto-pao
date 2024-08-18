#include <QApplication>
#include "frontend/mainwindow.h"
#include "frontend/simulation.h"
#include <QDebug>
#include "frontend/sensorlayoutchooser.h"






//////// C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;

   /* Wind w("luigi");
    Dust d("chiara");
    Sensor *s=&w;
    SensorLayoutChooser slc;
    s->accept(slc);
    s=&d;
    s->accept(slc);*/

    mw.show();
    mw.setWindowTitle("Sensori");
    return a.exec();


}

