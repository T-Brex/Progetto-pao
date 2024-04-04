#include "menubar.h"
#include "qstackedwidget.h"
#include "mainwindow.h"

MenuBar::MenuBar():
    fileMenu(new QMenu(this)),
    simulazioneAct(new QAction(tr("&Simulazione"))),sensoriAct(new QAction(tr("&Sensori"))),newAct(new QAction(tr("&Nuovo Sensore"))),importAct(new QAction(tr("&Importa Sensore"))),saveAct(new QAction(tr("&Salva")))
{
    this->addAction(simulazioneAct);
    fileMenu = this->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(importAct);
    fileMenu->addAction(saveAct);
    //QStackedWidget* layouts=MainWindow::layoutsWidget;
    QObject::connect(simulazioneAct, &QAction::triggered, [&](){
        this->insertAction(simulazioneAct,sensoriAct);
        this->removeAction(simulazioneAct);
        //MainWindow::layoutsWidget->setCurrentIndex(1);
    });

    QObject::connect(sensoriAct, &QAction::triggered, [&](){
        this->insertAction(sensoriAct,simulazioneAct);
        this->removeAction(sensoriAct);
        //MainWindow::layoutsWidget->setCurrentIndex(0);
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

