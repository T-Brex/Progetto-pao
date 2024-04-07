#include "menubar.h"

MenuBar::MenuBar(QWidget* parent):
    QMenuBar(parent),
    fileMenu(new QMenu(this)),
    changeLayoutAct(new QAction(tr("&Simulazione"))),newAct(new QAction(tr("&Nuovo Sensore"))),loadAct(new QAction(tr("&Importa Sensore"))),saveAct(new QAction(tr("&Salva")))

{
    this->addAction(changeLayoutAct);
    fileMenu = this->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(saveAct);
    lineEdit_nome = new QLineEdit(fileMenu);
    connect(changeLayoutAct, &QAction::triggered, this, &MenuBar::changeLayoutTrigger);

    connect(saveAct, &QAction::triggered, this, &MenuBar::saveTrigger);
    connect(loadAct, &QAction::triggered, this, &MenuBar::loadTrigger);

    //this->addWidget(lineEdit_nome);
}

MenuBar::~MenuBar() {};


