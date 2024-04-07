#include <QApplication>
#include <QRadioButton>
#include "frontend/mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>




#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>



//#include <QMenuBar>
//#include <QMenu>
//#include <QAction>


void salvaIntero(int value, const QString &fileName) {
    QJsonObject obj;
    obj["intero"] = value;

    QJsonDocument doc;
    doc.setObject((obj));
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
        qDebug() << doc.toJson();
        qDebug() << "Intero salvato con successo." << file.errorString();
    } else {
        qDebug() << "Errore nel salvataggio dell'intero.";
    }
}

int caricaIntero(const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();
        int value = obj["intero"].toInt();
        file.close();
        qDebug() << "Intero caricato con successo.";
        return value;
    } else {
        qDebug() << "Errore nel caricamento dell'intero." << file.errorString();
        return -1; // Valore di default in caso di errore
    }
}



void salvaSensori(const std::vector<Sensor*>& nuoviSensori, const QString& fileName) {
    QJsonArray sensoriArray;

    // Leggi il contenuto del file JSON esistente, se presente
    QFile file(fileName);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray existingData = file.readAll();
        QJsonDocument existingDocument = QJsonDocument::fromJson(existingData);
        if (existingDocument.isArray()) {
            sensoriArray = existingDocument.array();
        }
        file.close();
    }
    // Recupera i nomi dei sensori già presenti nel JSON
    std::vector<std::string> nomiSensoriPresenti;
    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        nomiSensoriPresenti.push_back(sensoreObject["nome"].toString().toStdString());
    }

    // Aggiungi i nuovi sensori solo se non sono già presenti

    for (const auto& sensore : nuoviSensori) {
        if (std::find(nomiSensoriPresenti.begin(), nomiSensoriPresenti.end(), sensore->getName()) == nomiSensoriPresenti.end()) {
            QJsonObject sensoreObject;
            sensoreObject["nome"] = QString::fromStdString(sensore->getName());
            sensoreObject["tipo"] = QString::fromStdString(sensore->getType());
            std::vector<double> values = sensore->getValue();
            for (size_t i = 0; i < values.size(); ++i) {
                sensoreObject[QString::fromStdString("valore_" + std::to_string(i))] = values[i];
            }
            sensoriArray.append(sensoreObject);
        }else{
            qDebug() << "Impossibile avere due sensori con lo stesso nome:"<<sensore->getName()<<"esiste già";
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

void eliminaSensore(const QString& fileName, const std::string& sensoreDaRimuovere = "") {
    QJsonArray sensoriArray;

    // Leggi il contenuto del file JSON esistente, se presente
    QFile file(fileName);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray existingData = file.readAll();
        QJsonDocument existingDocument = QJsonDocument::fromJson(existingData);
        if (existingDocument.isArray()) {
            sensoriArray = existingDocument.array();
        }
        file.close();
    }

    // Rimuovi il sensore specificato, se richiesto
    if (!sensoreDaRimuovere.empty()) {
        for (int i = 0; i < sensoriArray.size(); ++i) {
            QJsonObject sensoreObject = sensoriArray[i].toObject();
            if (sensoreObject["nome"].toString().toStdString() == sensoreDaRimuovere) {
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


//////// C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::vector<Sensor*> sensori;

    sensori.push_back(new AirQuality("Sensore1"));

    sensori.push_back(new Dust("Sensore2"));
    sensori.push_back(new Humidity("Sensore3"));
    sensori.push_back(new AirQuality("Sensore0"));
    sensori.push_back(new Wind("Sensore4"));
    sensori.push_back(new Termometer("Sensore5"));

    salvaSensori(sensori, "C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    eliminaSensore("C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json","Sensore3");

    // Deallocazione della memoria
    for (auto& sensore : sensori) {
        delete sensore;
    }

    //prova con Sensor
    QVector<Sensor*> s;
    Humidity *hum=new Humidity("hum");
    Termometer *term=new Termometer("term");
    s.push_front(hum);
    s.push_front(term);

    //prova con un solo sensore
    SensorPanel *airQ = new SensorPanel(AirQuality("airQ"));

    /*  Prova con sensorPanel*/
    QVector<SensorPanel*> sp;
    SensorPanel *ventoPanel= new SensorPanel(Wind("ven"));
    SensorPanel *polvPanel = new SensorPanel(Dust("polv"));
    sp.push_front(ventoPanel);
    sp.push_front(polvPanel);
    sp.push_front(airQ);


     /*Prova con bottoni*/
    QWidget *b = new QWidget;
    QLayout* blayout = new QHBoxLayout(b);
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    blayout->addWidget(button1);
    blayout->addWidget(button2);

    //Prova con sezioni
    QVector<QWidget *> frame;
    frame.push_front(SensorPanel::getSensorsWidget(sp));
    //frame.push_front(airQ);


    MainWindow w(frame);



    //SearchMenu *sm=new SearchMenu();
    //MainWindow w(sm);
    w.setWindowTitle("Sensori");

    w.resize(1280, 1024);
    w.show();
    return a.exec();
}
