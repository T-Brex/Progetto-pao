#include <QApplication>
#include <QRadioButton>
#include "frontend/mainwindow.h"
#include <QMenuBar>
#include <QMenu>

#include <QAction>




#include <QAction>
#include <QString>

#include "frontend/cartesianPlane.h"



#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
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

    //salvaSensori(sensori, "C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    //eliminaSensore("C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json","Sensore3");



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


    MainWindow w(MainWindow::caricaSensori("C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json"));
    w.show();
    w.setWindowTitle("Sensori");
    //w.resize(1280, 1024);




    CartesianPlane window;
    window.setWindowTitle("Piano Cartesiano");
    window.resize(400, 300);
    Sensor * d = new Dust("gigi");
    window.addSensor(d);
    window.addSensor(d);
    //window.show();


    return a.exec();


}

