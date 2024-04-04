#include "menubar.h"
//#include "mainwindow.h"

MenuBar::MenuBar(QWidget* parent):
    QMenuBar(parent),menuBar(new QMenuBar(this)),fileMenu(new QMenu(menuBar)),
    simulazioneAct(new QAction(tr("&Simulazione"))),sensoriAct(new QAction(tr("&Sensori"))),newAct(new QAction(tr("&Nuovo Sensore"))),importAct(new QAction(tr("&Importa Sensore"))),saveAct(new QAction(tr("&Salva")))
{
    menuBar->addAction(simulazioneAct);
    fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(importAct);
    fileMenu->addAction(saveAct);

    QObject::connect(simulazioneAct, &QAction::triggered, [&](){
        menuBar->insertAction(simulazioneAct,sensoriAct);
        menuBar->removeAction(simulazioneAct);
        //layoutsWidget->setCurrentIndex(1);
    });

    QObject::connect(sensoriAct, &QAction::triggered, [&](){
        menuBar->insertAction(sensoriAct,simulazioneAct);
        menuBar->removeAction(sensoriAct);
        //layoutsWidget->setCurrentIndex(0);
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
}

