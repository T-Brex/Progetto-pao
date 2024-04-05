#include <QApplication>
#include <QRadioButton>
#include <iostream>
#include "frontend/mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //prova con Sensor
    QVector<Sensor*> s;
    Humidity *hum=new Humidity("hum");
    Termometer *term=new Termometer("term");
    s.push_front(hum);
    s.push_front(term);



    /*  Prova con sensorPanel*/
    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));
    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);


    //prova con un solo sensore
    SensorPanel *airQ = new SensorPanel(AirQuality("airQ"));

     /*Prova con sezioni*/
    QWidget *b = new QWidget;
    QLayout* blayout = new QHBoxLayout(b);
    //QPushButton deriva da QWidget, quindi frame potrebbe ricevere direttamente i button
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    blayout->addWidget(button1);
    blayout->addWidget(button2);

    //sp.push_front(airQ);
    QVector<QWidget *> frame;

    frame.push_front(SensorPanel::getSensorsWidget(sp));
    frame.push_front(airQ);

    MainWindow w;
    w.setWindowTitle("Sensori");


    w.resize(960, 480);
    w.show();
    return a.exec();
}
