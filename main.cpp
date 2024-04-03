#include <QApplication>
#include <QRadioButton>
#include <iostream>
#include "frontend/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AirQuality ss ("nome");

    std::cout<<ss.getType();








    /*  Prova con sensorPanel*/
    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));
    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);


    /*
    QWidget *sensorsPanel = new QWidget;
    QHBoxLayout* panelsLayout = new QHBoxLayout(sensorsPanel);
                                                                        ========        SensorPanel::getSensorsWidget(sp)
    for(auto i=0;i<sp.size();i++){
        panelsLayout->addWidget(sp[i]);
    }
    */

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


    QVector<QWidget *> frame;
    frame.push_front(button1);
    frame.push_front(airQ);
    frame.push_front(b);
    frame.push_front(SensorPanel::getSensorsWidget(sp));










    //prova con Sensor
    QVector<Sensor*> s={new Humidity("hum"), new Termometer("term")};




    MainWindow w(s);
    w.resize(960, 480);
    w.show();
    return a.exec();
}
