#include <QApplication>
#include <QRadioButton>
#include <iostream>
#include "frontend/mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AirQuality ss ("nome");

    std::cout<<ss.getType();

    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));

    QVector<Sensor*> s;
    Wind *ven=new Wind("ven");
    Dust *polv=new Dust("polv");

    s.push_front(ven);
    s.push_front(polv);

    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);

    MainWindow w(s);

    w.resize(960, 480);
    w.show();
    return a.exec();
}
//
