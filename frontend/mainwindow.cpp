#include "mainwindow.h"
#include "backend/json.h"
#include "frontend/sensorPanel.h"
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


    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->getDeleteDialog(), &DeleteDialog::show);


    connect(menuBar, &MenuBar::showDeleteDialog, layoutsWidget->getDeleteDialog(), &DeleteDialog::show);
    connect(menuBar, &MenuBar::saveTrigger, this, [&]()
            {
                QString fileName = QFileDialog::getSaveFileName(this, "Salva file JSON", "", "JSON Files (*.json)");

                if (!fileName.isEmpty()) {
                    // Effettua qui il salvataggio dei dati nel file JSON utilizzando il nome del file 'fileName'
                    bool success = Json::saveAs(Json::caricaSensori(), fileName);

                    if (success) {
                        qDebug() << "Sensori salvati in:" << fileName;
                        // Eventuali altre azioni da eseguire dopo il salvataggio
                    } else {
                        qDebug() << "Errore durante il salvataggio dei sensori.";
                        // Gestione dell'errore, ad esempio mostrare un messaggio all'utente
                    }
                } else {
                    qDebug() << "Operazione di salvataggio annullata dall'utente.";
                    // L'utente ha annullato la selezione del file
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
                            layoutsWidget->getSensWindow()->addSensor(*i);
                            layoutsWidget->getDeleteDialog()->getSceltaNome()->addItem((*i)->getName());
                            layoutsWidget->getSensWindow()->getSearchMenu()->updateSensori();
                        }
                    }
                } else {
                    qDebug() << "Nessun file selezionato.";
                }
            });

    connect(menuBar, &MenuBar::showOpenDialog, this, [&]()
            {
                QString fileName = QFileDialog::getOpenFileName(nullptr, "Seleziona un file", "", "JSON Files (*.json)");
        //qDebug()<<Json::path<<fileName;
        if(Json::path!=fileName){
                    Json::path=fileName;
        }
                // Verifica se l'utente ha selezionato un file
                if (!fileName.isEmpty()) {
                    layoutsWidget->getSensWindow()->deleteAllSensors();
                    layoutsWidget->getDeleteDialog()->getSceltaNome()->clear();
                    qDebug() << "Hai selezionato il file:" << fileName;
                    //Json::eliminaSensori();

                    QVector<Sensor*>nuoviSensori=Json::caricaSensori(fileName);
                    for(auto i=nuoviSensori.begin();i!=nuoviSensori.end();++i){
                            layoutsWidget->getSensWindow()->addSensor(*i);
                            layoutsWidget->getDeleteDialog()->getSceltaNome()->addItem((*i)->getName());
                            layoutsWidget->getSensWindow()->getSearchMenu()->updateSensori();
                    }
                } else {
                    qDebug() << "Nessun file selezionato.";
                }
            });
    setCentralWidget(layoutsWidget);
}

void MainWindow::changeLayout(){

    if(layoutsWidget->currentIndex()==0){
        delete layoutsWidget->widget(1);

        // Crea una nuova istanza della simulazione e aggiungila al LayoutsWidget
        layoutsWidget->insertWidget(1, new Simulation(Json::caricaSensori()));
        layoutsWidget->setCurrentIndex(1);
        menuBar->getChangeLayoutAct()->setText(tr("Sensori"));
    }else{
        layoutsWidget->setCurrentIndex(0);
        menuBar->getChangeLayoutAct()->setText(tr("Simulazione"));
    }
};

MainWindow::~MainWindow() {}




