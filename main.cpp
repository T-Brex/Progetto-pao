#include <QApplication>
#include <QRadioButton>
#include <iostream>
#include "frontend/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AirQuality ss ("nome");

    std::cout<<ss.getType();



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

    QWidget *sensorsPanel = new QWidget;
    QHBoxLayout* panelsLayout = new QHBoxLayout(sensorsPanel);

    for(auto i=0;i<sp.size();i++){
        panelsLayout->addWidget(sp[i]);
    }

     /*Prova con sezioni*/
    QVector<QWidget *> frame;
    QWidget *b = new QWidget;
    QLayout* blayout = new QHBoxLayout(b);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    blayout->addWidget(button1);
    blayout->addWidget(button2);


    frame.push_front(b);
    frame.push_front(sensorsPanel);


    MainWindow w(sp);

    w.resize(960, 480);
    w.show();
    return a.exec();
}
//
