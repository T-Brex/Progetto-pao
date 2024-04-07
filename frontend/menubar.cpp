#include "menubar.h"

MenuBar::MenuBar(QWidget* parent):
    QMenuBar(parent),
    fileMenu(new QMenu()),
    changeLayoutAct(new QAction(tr("&Simulazione"))),newAct(new QAction(tr("&Nuovo Sensore"))),loadAct(new QAction(tr("&Carica Sensore"))),saveAct(new QAction(tr("&Salva"))),
    deleteAct(new QAction(tr("&Elimina")))

{
    this->addAction(changeLayoutAct);
    this->addMenu(fileMenu);
    fileMenu = this->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(loadAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(deleteAct);

    QMenu* editMenu = new QMenu();
    this->addMenu(editMenu);
    editMenu = this->addMenu(tr("&Edit"));
    lineEdit_nome = new QLineEdit(editMenu);
    //connect(changeLayoutAct, &QAction::triggered, this, &MenuBar::changeLayoutTrigger);


    connect(changeLayoutAct, &QAction::triggered, this, &MenuBar::changeLayoutTrigger);

    //connect(newAct, &QAction::triggered, this, &MenuBar::newTrigger);
    connect(loadAct, &QAction::triggered, this, &MenuBar::loadTrigger);
    connect(saveAct, &QAction::triggered, this, &MenuBar::saveTrigger);
    connect(deleteAct, &QAction::triggered, this, &MenuBar::deleteTrigger);

    //this->addWidget(lineEdit_nome);
}

MenuBar::~MenuBar() {};


