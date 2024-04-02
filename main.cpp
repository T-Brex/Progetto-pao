#include <QApplication>
#include <QRadioButton>
#include <iostream>
#include "frontend/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AirQuality ss ("nome");

    std::cout<<ss.getType();


    /*  Prova con sensor*/

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


    /*Prova con sezioni*/
    QWidget *b = new QWidget;
    QLayout* blayout = new QHBoxLayout(b);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    blayout->addWidget(button1);
    blayout->addWidget(button2);

    QWidget *sensorsPanel=SensorPanel::getSensorsLayout(sp);
    QVector<QWidget *> frame;
    //frame.push_front()
    frame.push_front(b);
    frame.push_front(sensorsPanel);

    MainWindow w(frame);
    w.resize(1240, 768);
    w.show();
    return a.exec();
}
