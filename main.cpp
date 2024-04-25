#include <QApplication>
#include "frontend/mainwindow.h"
#include "frontend/simulation.h"
#include <QDebug>






//////// C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<Sensor*> s;

    s.push_back(new AirQuality("Sensore1"));

    s.push_back(new Dust("Sensore2"));
    s.push_back(new Humidity("Sensore3"));
    s.push_back(new AirQuality("Sensore0"));
    s.push_back(new Wind("Sensore4"));
    s.push_back(new Termometer("Sensore5"));

    //prova con Sensor


    //prova con un solo sensore
    SensorPanel *airQ = new SensorPanel(AirQuality("airQ"));

    /*  Prova con sensorPanel*/
    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));
    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);
    sp.push_front(airQ);



     /*Prova con bottoni*/
    QWidget *b = new QWidget;
    QLayout* blayout = new QHBoxLayout(b);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    blayout->addWidget(button1);
    blayout->addWidget(button2);





    //Prova con sezioni
    QVector<QWidget *> frame;
    frame.push_front(SensorPanel::getSensorsWidget(sp));
    frame.push_front(airQ);


    MainWindow w;

    //emptyName.setDefaultButton(new QPushButton);
    //emptyName.setText("Inserire un nome");
    //emptyName.open();

    w.show();
    w.setWindowTitle("Sensori");
    w.showMaximized();



    Simulation window(s);
    window.setWindowTitle("simulation bar");
    window.resize(900,900);
    //window.show();



    return a.exec();


}

