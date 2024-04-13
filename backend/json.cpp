#include "json.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <QJsonArray>
#include <QFile>
//QJsonArray Json::sensoriArray = leggiJson();

Json::Json()//:file("C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json"),sensoriArray(leggiJson())
{
    //QFile file;
    //QJsonArray jsonArray;
    //QJsonDocument jsonDocument;
    //QJsonObject jsonObject;
}
QJsonArray Json::leggiJson(const QString& fileName){
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

void Json::nuovoSensore(const QString& nome, const QString& tipo, const QString& fileName){
    // Se nome != ""
    if(!nome.isEmpty()){
        QFile file(fileName);
        QJsonArray sensoriArray = Json::leggiJson(fileName);
        Sensor* sensore = Json::costruttore(nome,tipo);
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
                //sceltaNome->addItem(nome);
                qDebug() << "Sensore<<"<< nome <<"aggiunto con successo";
            } else {
                qDebug() << "Errore nell'apertura del file";
            }
            //this->updateSensors();
        }
    }else{
        qDebug()<<"Inserire un nome";
    }

}

void Json::salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName) {

    // Aggiungi i nuovi sensori solo se non sono già presenti
    for (const auto& sensore : nuoviSensori) {
        QString nomeSensore = sensore->getName();
        QString tipoSensore = sensore->getType();
        nuovoSensore(nomeSensore,tipoSensore);
    }
}

void Json::eliminaSensore(const QString& sensoreDaRimuovere, const QString& fileName) {


    // Rimuovi il sensore specificato, se presente
    qDebug()<<sensoreDaRimuovere;
    if (!sensoreDaRimuovere.isEmpty()) {
        QFile file(fileName);
        QJsonArray sensoriArray = Json::leggiJson(fileName);

        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            qDebug()<<sensoreObject["nome"] <<"=="<<sensoreDaRimuovere;
            if (sensoreObject["nome"] == sensoreDaRimuovere) {
                it = sensoriArray.erase(it);

                // Scrivi il JSON aggiornato sul file
                if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
                    QJsonDocument jsonDocument(sensoriArray);
                    file.write(jsonDocument.toJson());
                    file.close();
                    qDebug() << "Sensore" << sensoreDaRimuovere << "rimosso con successo.";
                    break;
                }
                qDebug() << "Impossibile rimuovere" << sensoreDaRimuovere;
                break;
            }
        }
    }
}

QVector<Sensor*> Json::caricaSensori(const QString& fileName){

    QVector<Sensor*> sensori;

    // Leggi il contenuto del file JSON
    QJsonArray sensoriArray=leggiJson(fileName);
    // Itera attraverso l'array JSON e crea i sensori corrispondenti
    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        QString nome = sensoreObject["nome"].toString();
        QString tipo = sensoreObject["tipo"].toString();

        // Crea il sensore in base al tipo
        Sensor* nuovoSensore = Json::costruttore(nome,tipo);
        if (nuovoSensore) {
            sensori.append(nuovoSensore);
        } else {
            qDebug() << "Tipo di sensore non valido: " << tipo;
        }
    }
    return sensori;

}
Sensor* Json::costruttore(const QString& nome, const QString& tipo){
    Sensor* nuovoSensore = nullptr;
    if (tipo == "Dust") {
        nuovoSensore = new Dust(nome);
    } else if (tipo == "Humidity") {
        nuovoSensore = new Humidity(nome);
    } else if (tipo == "Wind") {
        nuovoSensore = new Wind(nome);
    } else if (tipo == "Termometer") {
        nuovoSensore = new Termometer(nome);
    } else if (tipo == "AirQuality") {
        nuovoSensore = new AirQuality(nome);
    }
    return nuovoSensore;
}
