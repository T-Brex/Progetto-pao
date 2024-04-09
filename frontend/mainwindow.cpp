#include "mainwindow.h"
#include "frontend/sensorPanel.h"
//#include "backend/sensors.h"
#include "frontend/dialog.h"
#include "qjsonarray.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),layoutsWidget(new LayoutsWidget()),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(const QVector<Sensor*>& s, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar),dialog(new Dialog(this))
{

    setMenuBar(menuBar);

    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    connect(menuBar, &MenuBar::newTrigger, this, [&]()
            {
                nuovoSensore("cacca","Dust");
            });

    connect(dialog, &Dialog::newTrigger, this, [&]()
            {
        nuovoSensore(dialog->lineEdit->text(),dialog->sceltaTipo->currentText());
                dialog->close();
            });
    connect(layoutsWidget->searchMenu,&SearchMenu::showDialog, this, [&]()
            {
        dialog->open();

            });

    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
                salvaSensori(s);
            });

    connect(menuBar, &MenuBar::deleteTrigger, this, [&]()
            {
                eliminaSensore("cacca");
            });
    connect(menuBar, &MenuBar::loadTrigger, this, [&]()
            {
                caricaSensori();
            });
    setCentralWidget(layoutsWidget);
}

//Eliminabile(?)
MainWindow::MainWindow(QVector<SensorPanel*> sp, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(sp)),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}


//Eliminabile(?)
MainWindow::MainWindow(QVector<QWidget*> frame, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(frame)),menuBar(new MenuBar)
{
    setMenuBar(menuBar);
    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    setCentralWidget(layoutsWidget);
}

void MainWindow::updateSensors() {

    layoutsWidget = new LayoutsWidget(MainWindow::caricaSensori());
    setCentralWidget(layoutsWidget);
}


void MainWindow::showDialog(){
    dialog->open();
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

QJsonArray MainWindow::leggiJson(const QString& fileName){
    // Leggi il contenuto del file JSON esistente, se presente
    QFile file(fileName);
    QJsonArray sensoriArray;
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray existingData = file.readAll();
        QJsonDocument existingDocument = QJsonDocument::fromJson(existingData);
        if (existingDocument.isArray()) {
            sensoriArray = existingDocument.array();
        }
        file.close();
    }
    return sensoriArray;
}

void MainWindow::nuovoSensore(const QString& nome, const QString& tipo, const QString& fileName){
    QFile file(fileName);
    QJsonArray sensoriArray = MainWindow::leggiJson(fileName);
    Sensor* sensore = Sensor::costruttore(nome,tipo);
    // Verifica se il sensore è già presente nel JSON
    bool sensorePresente = false;
    for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
        QJsonObject sensoreObject = it->toObject();
        if (sensoreObject["nome"].toString() == nome) {
            sensorePresente = true;
            qDebug() << "Il sensore" << nome << "esiste già nel file";
            break;
        }
    }
    // Se il sensore non è presente, aggiungilo al JSON
    if (!sensorePresente) {
        QJsonObject sensoreObject;
        sensoreObject["nome"] = nome;
        sensoreObject["tipo"] = QString::fromStdString(sensore->getType());
        std::vector<double> values = sensore->getValue();
        for (size_t i = 0; i < values.size(); ++i) {
            sensoreObject[QString::fromStdString("valore_" + std::to_string(i))] = values[i];
        }
        sensoriArray.append(sensoreObject);
    }
    // Scrivi il JSON aggiornato sul file
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QJsonDocument jsonDocument(sensoriArray);
        file.write(jsonDocument.toJson());
        file.close();
        qDebug() << "Sensori aggiunti con successo.";
    } else {
        qDebug() << "Errore nell'apertura del file.";
    }


    this->updateSensors();
}

void MainWindow::salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName) {

    // Aggiungi i nuovi sensori solo se non sono già presenti
    for (const auto& sensore : nuoviSensori) {
        QString nomeSensore = QString::fromStdString(sensore->getName());
        QString tipoSensore = QString::fromStdString(sensore->getType());
        nuovoSensore(nomeSensore,tipoSensore);
    }
}

void MainWindow::eliminaSensore(const QString& sensoreDaRimuovere, const QString& fileName) {
    QFile file(fileName);
    QJsonArray sensoriArray = MainWindow::leggiJson(fileName);

    // Rimuovi il sensore specificato, se presente
    if (!sensoreDaRimuovere.isEmpty()) {
        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            if (sensoreObject["nome"].toString() == sensoreDaRimuovere) {
                it = sensoriArray.erase(it);
                qDebug() << "Sensore" << sensoreDaRimuovere << "rimosso con successo.";
                break;
            }
        }
    }

    // Scrivi il JSON aggiornato sul file
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QJsonDocument jsonDocument(sensoriArray);
        file.write(jsonDocument.toJson());
        file.close();
        qDebug() << "Sensori salvati con successo.";
    } else {
        qDebug() << "Errore nell'apertura del file.";
    }
    this->updateSensors();
}

QVector<Sensor*> MainWindow::caricaSensori(const QString& fileName){

    QVector<Sensor*> sensori;

    // Leggi il contenuto del file JSON
    QJsonArray sensoriArray=MainWindow::leggiJson(fileName);
    // Itera attraverso l'array JSON e crea i sensori corrispondenti
    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        QString nome = sensoreObject["nome"].toString();
        QString tipo = sensoreObject["tipo"].toString();

        // Crea il sensore in base al tipo
        Sensor* nuovoSensore = Sensor::costruttore(nome,tipo);
        if (nuovoSensore) {
            // Aggiungi il sensore al QVector
            sensori.append(nuovoSensore);
        } else {
            qDebug() << "Tipo di sensore non valido: " << tipo;
        }
    }
    return sensori;

}





