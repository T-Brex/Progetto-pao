#include "menubar.h"

MenuBar::MenuBar(QWidget* parent):
    QMenuBar(parent),
    fileMenu(new QMenu()),
    changeLayoutAct(new QAction(tr("&Simulazione"))),openAct(new QAction(tr("&Apri"))),loadAct(new QAction(tr("&Importa"))),saveAct(new QAction(tr("&Salva con nome")))



{
    this->addAction(changeLayoutAct);
    this->addMenu(fileMenu);
    fileMenu = this->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(saveAct);


    connect(changeLayoutAct, &QAction::triggered, this, &MenuBar::changeLayoutTrigger);
    connect(openAct, &QAction::triggered, this, &MenuBar::showOpenDialog);
    connect(loadAct, &QAction::triggered, this, &MenuBar::loadTrigger);
    connect(saveAct, &QAction::triggered, this, &MenuBar::saveTrigger);

}

MenuBar::~MenuBar() {};


