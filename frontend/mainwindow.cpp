#include "mainwindow.h"
#include "backend/json.h"
#include "frontend/adddialog.h"
#include "frontend/sensorPanel.h"
#include "frontend/adddialog.h"
#include "backend/json.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>
#include <QFileDialog>




MainWindow::MainWindow(SearchMenu *menu, QWidget *parent)
    : QMainWindow(parent)
{

    setCentralWidget(menu);
}




MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),layoutsWidget(new LayoutsWidget()),menuBar(new MenuBar)
{

    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    connect(menuBar, &MenuBar::showAddDialog, layoutsWidget->addDialog, [&](){
        layoutsWidget->addDialog->open();
        layoutsWidget->addDialog->lineEdit->setFocus();
    });

    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->deleteDialog, &DeleteDialog::open);


    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->deleteDialog, &DeleteDialog::open);
    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
                QString fileName = QFileDialog::getSaveFileName(this, "Salva file JSON", "", "JSON Files (*.json)");

                if (!fileName.isEmpty()) {
                    //Json::salvaSensori(layoutsWidget->sensWindow->getSensors(), fileName);
                }
            });

    connect(menuBar, &MenuBar::loadTrigger, this, [&]()
            {
                QString fileName = QFileDialog::getOpenFileName(nullptr, "Seleziona un file", "", "JSON Files (*.json)");

                // Verifica se l'utente ha selezionato un file
                if (!fileName.isEmpty()) {
                    qDebug() << "Hai selezionato il file:" << fileName;
                    QVector<Sensor*>nuoviSensori=Json::caricaSensori(fileName);
                    for(auto i=nuoviSensori.begin();i!=nuoviSensori.end();++i){
                        if(Json::nuovoSensore((*i)->getName(),(*i)->getType())=="ok"){
                            layoutsWidget->sensWindow->addSensor(*i);
                            layoutsWidget->deleteDialog->sceltaNome->addItem((*i)->getName());
                        }
                    }
                } else {
                    qDebug() << "Nessun file selezionato.";
                }
            });
    setCentralWidget(layoutsWidget);
}


//Eliminabile(?)
MainWindow::MainWindow(const QVector<Sensor*>& s, QWidget *parent):
    QMainWindow(parent),
    //layoutsWidget(new LayoutsWidget(s)),
    menuBar(new MenuBar)
{


    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    connect(menuBar, &MenuBar::showAddDialog, layoutsWidget->addDialog, [&](){
        layoutsWidget->addDialog->open();
        layoutsWidget->addDialog->lineEdit->setFocus();
    });
    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->deleteDialog, &DeleteDialog::open);

    /*connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
        Json::salvaSensori(s);
            });*/


    connect(menuBar, &MenuBar::loadTrigger, this, [&]()
    {
        QString fileName = QFileDialog::getOpenFileName(nullptr, "Seleziona un file", "", "JSON Files (*.json)");

        // Verifica se l'utente ha selezionato un file
        if (!fileName.isEmpty()) {
            qDebug() << "Hai selezionato il file:" << fileName;
            QVector<Sensor*>nuoviSensori=Json::caricaSensori(fileName);
            for(auto i=nuoviSensori.begin();i!=nuoviSensori.end();++i){
                if(Json::nuovoSensore((*i)->getName(),(*i)->getType())=="ok"){
                    layoutsWidget->sensWindow->addSensor(*i);
                    layoutsWidget->deleteDialog->sceltaNome->addItem((*i)->getName());
                }
            }
        } else {
            qDebug() << "Nessun file selezionato.";
        }
    });
    setCentralWidget(layoutsWidget);
}

void MainWindow::changeLayout(){

    if(layoutsWidget->currentIndex()==0){
        layoutsWidget->setCurrentIndex(1);
        menuBar->changeLayoutAct->setText(tr("Sensori"));
    }else{
        layoutsWidget->setCurrentIndex(0);
        menuBar->changeLayoutAct->setText(tr("Simulazione"));
    }
};


//Eliminabile(?)
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent):
    QMainWindow(parent),
    //layoutsWidget(new LayoutsWidget(sp)),
    menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}


//Eliminabile(?)
MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),
    //layoutsWidget(new LayoutsWidget(frame)),
    menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}




MainWindow::~MainWindow() {}




