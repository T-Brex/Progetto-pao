#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include <QApplication>
#include <QRadioButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(window);

    QWidget *p = new QWidget;
    QLayout* layout2 = new QHBoxLayout(p);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    layout2->addWidget(button1);
    layout2->addWidget(button2);


    layout->addWidget(p);

    setCentralWidget(window);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QVector<Sensor*> s,QWidget *parent): QMainWindow(parent)
{
    QWidget *window = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(window);


    QVector<SensorPanel*> sp;
    for(auto i=0;i<s.size();i++){
        sp.push_front(new SensorPanel(*s[i]));
        //sarebbe da modificare il costruttore di sensorPanel in modo tale che prenda un vector d
    }
    QWidget *sensorsPanel = setSensorsPanel(sp);
    layout->addWidget(sensorsPanel);
    setCentralWidget(window);

}
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent): QMainWindow(parent){
    QWidget *window = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(window);

    /*
    QWidget *p = new QWidget;
    QLayout* layout2 = new QHBoxLayout(p);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    layout2->addWidget(button1);
    layout2->addWidget(button2);
    layout->addWidget(p);
    */
    QWidget *sensorsPanel=setSensorsPanel(sp);

    layout->addWidget(sensorsPanel);
    setCentralWidget(window);
}

QWidget* MainWindow::setSensorsPanel(QVector<SensorPanel*> sp){

    QWidget *panels = new QWidget;
    QHBoxLayout* panelsLayout = new QHBoxLayout(panels);

    for(auto i=0;i<sp.size();i++){
        panelsLayout->addWidget(sp[i]);
    }
    return panels;
}

