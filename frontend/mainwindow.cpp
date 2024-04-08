#include "mainwindow.h"
#include "frontend/sensorPanel.h"
//#include "backend/sensors.h"
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
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar)
{

    setMenuBar(menuBar);

    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);
    connect(menuBar, &MenuBar::newTrigger, this, [&]()
            {
                nuovoSensore("cacca","Dust");
            });
    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
                salvaSensori(s);
            });

    connect(menuBar, &MenuBar::deleteTrigger, this, [&]()
            {
                eliminaSensore("Sensore1");
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
    Sensor* nuovoSensore = Sensor::costruttore(nome,tipo);
    QVector<Sensor*> vecSensore;
    vecSensore.append(nuovoSensore);
    MainWindow::salvaSensori(vecSensore);
}

void MainWindow::salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName) {

    // Leggi il contenuto del file JSON esistente, se presente
    QFile file(fileName);
    QJsonArray sensoriArray=MainWindow::leggiJson(fileName);
    // Recupera i nomi dei sensori già presenti nel JSON
    QVector<QString> nomiSensoriPresenti;
    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        nomiSensoriPresenti.push_back(sensoreObject["nome"].toString());
    }

    // Aggiungi i nuovi sensori solo se non sono già presenti
    for (const auto& sensore : nuoviSensori) {
        if (std::find(nomiSensoriPresenti.begin(), nomiSensoriPresenti.end(), QString::fromStdString(sensore->getName())) == nomiSensoriPresenti.end()) {
            QJsonObject sensoreObject;
            sensoreObject["nome"] = QString::fromStdString(sensore->getName());
            sensoreObject["tipo"] = QString::fromStdString(sensore->getType());
            std::vector<double> values = sensore->getValue();
            for (size_t i = 0; i < values.size(); ++i) {
                sensoreObject[QString::fromStdString("valore_" + std::to_string(i))] = values[i];
            }
            sensoriArray.append(sensoreObject);
        }else{
            qDebug() << "Il sensore" << sensore->getName() << "esiste già nel file";
        }
    }

    // Creare un documento JSON e scrivere il contenuto su disco
    QJsonDocument jsonDocument(sensoriArray);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.write(jsonDocument.toJson());
        file.close();
        qDebug() << "Sensori aggiunti con successo.";
    } else {
        qDebug() << "Errore nell'apertura del file.";
    }
}

void MainWindow::eliminaSensore(const QString& sensoreDaRimuovere="",const QString& fileName) {


    // Leggi il contenuto del file JSON esistente, se presente
    QFile file(fileName);
    QJsonArray sensoriArray=MainWindow::leggiJson(fileName);
    // Rimuovi il sensore specificato, se richiesto
    if (!sensoreDaRimuovere.isEmpty()) {
        for (int i = 0; i < sensoriArray.size(); ++i) {
            QJsonObject sensoreObject = sensoriArray[i].toObject();
            if (sensoreObject["nome"].toString() == sensoreDaRimuovere) {
                sensoriArray.removeAt(i);
                break;
            }
        }
    }

    // Recupera i nomi dei sensori già presenti nel JSON
    std::vector<std::string> nomiSensoriPresenti;
    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        nomiSensoriPresenti.push_back(sensoreObject["nome"].toString().toStdString());
    }


    // Creare un documento JSON e scrivere il contenuto su disco
    QJsonDocument jsonDocument(sensoriArray);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.write(jsonDocument.toJson());
        file.close();
        qDebug() << "Sensori salvati con successo.";
    } else {
        qDebug() << "Errore nell'apertura del file.";
    }
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





