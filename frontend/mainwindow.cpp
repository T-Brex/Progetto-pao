#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{

    setCentralWidget(window);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QVector<Sensor*> s, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{
    //trasformazione da Sensor a SensorPanel
    QVector<SensorPanel*> sp;
    for(auto i=0;i<s.size();i++){
        sp.push_front(new SensorPanel(*s[i]));
    }

    sensLayout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);

}
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{
    sensLayout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);
}



MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window)),
    menuBar(new QMenuBar(this)),fileMenu(new QMenu(menuBar))/*,
    simulazioneAct(new QAction(fileMenu)),sensoriAct(new QAction(fileMenu)),newAct(new QAction(fileMenu)),importAct(new QAction(fileMenu)),saveAct(new QAction(fileMenu))*/
{
    setMenuBar(menuBar);
    simulazioneAct = menuBar->addAction("&Simulazione");
    sensoriAct = fileMenu->addAction(tr("&Sensori"));

    fileMenu = menuBar->addMenu(tr("&File"));

    newAct = fileMenu->addAction(tr("&Nuovo Drone"));
    importAct = fileMenu->addAction(tr("&Importa Drone"));
    saveAct = fileMenu->addAction(tr("&Salva"));

    QObject::connect(simulazioneAct, &QAction::triggered, [&](){
        menuBar->insertAction(simulazioneAct,sensoriAct);
        menuBar->removeAction(simulazioneAct);
    });

    QObject::connect(sensoriAct, &QAction::triggered, [&](){
        menuBar->insertAction(sensoriAct,simulazioneAct);
        menuBar->removeAction(sensoriAct);
    });

    QObject::connect(newAct, &QAction::triggered, [&](){
        // Gestire l'azione di Nuovo qui
    });

    QObject::connect(importAct, &QAction::triggered, [&](){
        // Gestire l'azione di Apri qui
    });
    QObject::connect(saveAct, &QAction::triggered, [&](){
        // Gestire l'azione di Apri qui
    });

    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }

    setCentralWidget(window);
}





