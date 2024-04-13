#include "mainwindow.h"
#include "frontend/sensorPanel.h"
#include "qtmetamacros.h"
#include "frontend/dialog.h"
#include "qjsonarray.h"
#include <QApplication>
#include <QRadioButton>
#include <QMenuBar>
#include <QMenuBar>



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
    setCentralWidget(layoutsWidget);
}

MainWindow::~MainWindow() {}

MainWindow::MainWindow(const QVector<Sensor*>& s, QWidget *parent):
    QMainWindow(parent),layoutsWidget(new LayoutsWidget(s)),menuBar(new MenuBar),addDialog(new Dialog(this)),deleteDialog(new QDialog(this))
{
    QJsonArray sensoriArray = MainWindow::leggiJson();

    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        QString nome = sensoreObject["nome"].toString();
        sceltaNome->addItem(nome);
    }
    layout->addWidget(sceltaNome);
    layout->addWidget(deleteButton);

    setMenuBar(menuBar);

    connect(menuBar, &MenuBar::changeLayoutTrigger, this, &MainWindow::changeLayout);


    connect(menuBar, &MenuBar::showAddDialog, this, [&]()
            {
        addDialog->open();
        addDialog->lineEdit->setFocus();
        connect(addDialog, &Dialog::newTrigger, this, [&]()
                {
                    nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());
            addDialog->lineEdit->clear();
                    addDialog->close();

                });
        });


    connect(layoutsWidget->searchMenu,&SearchMenu::showAddDialog, this, [&]()
                {
        addDialog->show();
        connect(addDialog, &Dialog::newTrigger, this, [&]()
                {
                    nuovoSensore(addDialog->lineEdit->text(), addDialog->sceltaTipo->currentText());

                    addDialog->hide();
                });
    });

    connect(menuBar, &MenuBar::saveTrigger, this,  [&]()
            {
                salvaSensori(s);
            });

    connect(menuBar, &MenuBar::deleteTrigger, this, [&](){
        deleteDialog->open();
        connect(deleteButton,&QPushButton::clicked,this,[&](){
            eliminaSensore(sceltaNome->currentText());
            deleteDialog->close();
                });
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
    // Se nome != ""
    if(!nome.isEmpty()){
    QFile file(fileName);
    QJsonArray sensoriArray = MainWindow::leggiJson(fileName);
    Sensor* sensore = Dialog::costruttore(nome,tipo);
    // Verifica se il sensore è già presente nel JSON
    bool sensorePresente = false;
    for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
        QJsonObject sensoreObject = it->toObject();
        if (sensoreObject["nome"] == nome) {
            sensorePresente = true;
            qDebug() << "Il sensore" << nome << "esiste già nel file";
            break;
        }
    }
    // Se il sensore non è presente, aggiungilo al JSON
    if (!sensorePresente) {
        QJsonObject sensoreObject;
        sensoreObject["nome"] = nome;
        sensoreObject["tipo"] = sensore->getType();
        QVector<double> values = sensore->getValue();
        QVector<QString> valuesName = sensore->getNameValues();

        for (auto i = 0; i < values.size(); ++i) {
            sensoreObject[valuesName[i]] = values[i];
        }
        sensoriArray.append(sensoreObject);

        // Scrivi il JSON aggiornato sul file
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            QJsonDocument jsonDocument(sensoriArray);
            file.write(jsonDocument.toJson());
            file.close();
            sceltaNome->addItem(nome);
            qDebug() << "Sensore<<"<< nome <<"aggiunto con successo.";
        } else {
            qDebug() << "Errore nell'apertura del file.";
        }
        this->updateSensors();
    }
    }else{
        qDebug()<<"Inserire un nome";
    }

}

void MainWindow::salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName) {

    // Aggiungi i nuovi sensori solo se non sono già presenti
    for (const auto& sensore : nuoviSensori) {
        QString nomeSensore = sensore->getName();
        QString tipoSensore = sensore->getType();
        nuovoSensore(nomeSensore,tipoSensore);
    }
}

void MainWindow::eliminaSensore(const QString& sensoreDaRimuovere, const QString& fileName) {


    // Rimuovi il sensore specificato, se presente
    if (!sensoreDaRimuovere.isEmpty()) {
        QFile file(fileName);
        QJsonArray sensoriArray = MainWindow::leggiJson(fileName);
        int i=0;
        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            if (sensoreObject["nome"] == sensoreDaRimuovere) {
                it = sensoriArray.erase(it);
                // Scrivi il JSON aggiornato sul file
                if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
                    QJsonDocument jsonDocument(sensoriArray);
                    file.write(jsonDocument.toJson());
                    file.close();
                    sceltaNome->removeItem(i);
                    qDebug() << "Sensore" << sensoreDaRimuovere << "rimosso con successo.";
                    break;
                }
                qDebug() << "Impossibile rimuovere" << sensoreDaRimuovere;
                break;
            }
            ++i;
        }
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
        Sensor* nuovoSensore = Dialog::costruttore(nome,tipo);
        if (nuovoSensore) {
            sensori.append(nuovoSensore);
        } else {
            qDebug() << "Tipo di sensore non valido: " << tipo;
        }
    }
    return sensori;

}





