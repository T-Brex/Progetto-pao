#include <QApplication>
#include <QRadioButton>
#include "frontend/mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>



//#include <QMenuBar>
//#include <QMenu>
//#include <QAction>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /*  Prova con sensorPanel*/
    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));
    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);


    //prova con un solo sensore
    SensorPanel *airQ = new SensorPanel(AirQuality("airQ"));


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


    //MainWindow w(frame);



    SearchMenu *sm=new SearchMenu();
      MainWindow w(sm);
      w.setWindowTitle("Sensori");


    w.resize(960, 480);
    w.show();
    return a.exec();
}
