#include <QApplication>
#include <QRadioButton>
#include "frontend/mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
<<<<<<< HEAD
=======



>>>>>>> bcc5aa2c06d10949ca3c34fcd4ade0d9746772cc
//#include <QMenuBar>
//#include <QMenu>
//#include <QAction>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //prova con Sensor
    QVector<Sensor*> s;
    Humidity *hum=new Humidity("hum");
    Termometer *term=new Termometer("term");
    s.push_front(hum);
    s.push_front(term);

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
<<<<<<< HEAD
    frame.push_front(airQ);



    SearchMenu *sm=new SearchMenu();
      MainWindow w(sm);




/*
    MainWindow w(frame);
    w.setWindowTitle("Sensori");
*/

    w.resize(960, 480);
=======
    //frame.push_front(airQ);


    MainWindow w(frame);



    //SearchMenu *sm=new SearchMenu();
    //MainWindow w(sm);
    w.setWindowTitle("Sensori");

    w.resize(1280, 1024);
>>>>>>> bcc5aa2c06d10949ca3c34fcd4ade0d9746772cc
    w.show();
    return a.exec();
}
