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
    for(auto i=0;i<s.size();i++){

        sensLayout->addWidget(new SensorPanel(*s[i]));
    }
    setCentralWidget(window);

}
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent): QMainWindow(parent),window(new QWidget(this)), sensLayout(new QGridLayout(window))
{
    sensLayout->addWidget(SensorPanel::getSensorsWidget(sp));
    setCentralWidget(window);
}



MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),window(new QWidget(this)),mainLayout(new QHBoxLayout(window)),
    layoutsWidget(new QStackedWidget(this)),sensWidget(new QWidget),sensLayout(new QGridLayout(sensWidget)),simuWidget(new QWidget),simuLayout(new QHBoxLayout(simuWidget)),
    menuBar(new QMenuBar(this)),fileMenu(new QMenu(menuBar)),
    simulazioneAct(new QAction(tr("&Simulazione"))),sensoriAct(new QAction(tr("&Sensori"))),newAct(new QAction(tr("&Nuovo Sensore"))),importAct(new QAction(tr("&Importa Sensore"))),saveAct(new QAction(tr("&Salva")))
{
    /*
     *
     * MENUBAR*/

    setMenuBar(menuBar);

    menuBar->addAction(simulazioneAct);
    fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(importAct);
    fileMenu->addAction(saveAct);

    QObject::connect(simulazioneAct, &QAction::triggered, [&](){
        menuBar->insertAction(simulazioneAct,sensoriAct);
        menuBar->removeAction(simulazioneAct);
        layoutsWidget->setCurrentIndex(1);
    });

    QObject::connect(sensoriAct, &QAction::triggered, [&](){
        menuBar->insertAction(sensoriAct,simulazioneAct);
        menuBar->removeAction(sensoriAct);
        layoutsWidget->setCurrentIndex(0);
    });

    QObject::connect(newAct, &QAction::triggered, [&](){
        // Gestire l'azione di Nuovo qui
    });

    QObject::connect(importAct, &QAction::triggered, [&](){
        // Gestire l'azione di Apri qui
    });
    QObject::connect(saveAct, &QAction::triggered, [&](){
        // Gestire l'azione di Salva qui
    });

    /*
     *
     * LAYOUTS*/

    //costruzione layout sensori
    for(auto i=0;i<frame.size();i++){
        sensLayout->addWidget(frame[i]);
    }
    layoutsWidget->addWidget(sensWidget);

    //costruzione layout simulazione
    simuLayout->addWidget(new QPushButton("SUCA"));
    layoutsWidget->addWidget(simuWidget);

    mainLayout->addWidget(layoutsWidget);

    setCentralWidget(window);
}





