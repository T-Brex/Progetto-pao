#include "menubar.h"

MenuBar::MenuBar(QWidget* parent):
    QMenuBar(parent),
    fileMenu(new QMenu(this)),
    changeLayoutAct(new QAction(tr("&Simulazione"))),newAct(new QAction(tr("&Nuovo Sensore"))),importAct(new QAction(tr("&Importa Sensore"))),saveAct(new QAction(tr("&Salva")))
{
    this->addAction(changeLayoutAct);
    fileMenu = this->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(importAct);
    fileMenu->addAction(saveAct);
    connect(changeLayoutAct, &QAction::triggered, this, &MenuBar::changeLayoutTrigger);
}

MenuBar::~MenuBar() {};


