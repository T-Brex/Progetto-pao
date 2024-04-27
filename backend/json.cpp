#include "json.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <QJsonArray>
#include <QFile>
#include <QDateTime> // Aggiunto per gestire la data e l'ora

Json::Json() {}

QJsonArray Json::leggiJson(const QString& fileName) {
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

QString Json::nuovoSensore(const QString& nome, const QString& tipo, const QString& fileName) {
    if (!nome.isEmpty()) {

        QJsonArray sensoriArray = Json::leggiJson(fileName);
        QFile file(fileName);

        // Verifica se il sensore è già presente nel JSON
        bool sensorePresente = false;
        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            if (sensoreObject["nome"] == nome) {
                sensorePresente = true;
                return "existing";
            }
        }
        // Se il sensore non è presente, aggiungilo al JSON
        if (!sensorePresente) {
            Sensor* sensore = Json::costruttore(nome, tipo);
            QJsonObject sensoreObject;
            sensoreObject["nome"] = nome;
            sensoreObject["tipo"] = sensore->getType();
            sensoreObject["creationDate"] = sensore->getCreationDate().toString(Qt::ISODate); // Aggiungi data e ora al JSON
            QVector<double> values = sensore->getValue();
            QVector<QString> valuesName = sensore->getNameValues();

            for (auto i = 0; i < values.size(); ++i) {
                sensoreObject[valuesName[i]] = values[i];
            }
            sensoriArray.append(sensoreObject);
            // Scrivi il JSON aggiornato sul file
            if (file.open(QIODevice::WriteOnly)) {
                QJsonDocument jsonDocument(sensoriArray);
                file.write(jsonDocument.toJson());
                file.close();
                return "ok";
            } else {
                return "openError";
            }
            //return "ok";
        }
    } else {
        return "empty";
    }
return "0";
}


void Json::saveAs(const QVector<Sensor*>& sensori, const QString& newFileName) {
    QFile file(newFileName);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonArray sensoriArray;

        for (const auto& sensore : sensori) {
            QJsonObject sensoreObject;
            sensoreObject["nome"] = sensore->getName();
            sensoreObject["tipo"] = sensore->getType();
            sensoreObject["creationDate"] = sensore->getCreationDate().toString(Qt::ISODate);

            QVector<double> values = sensore->getValue();
            QVector<QString> valuesName = sensore->getNameValues();

            for (auto i = 0; i < values.size(); ++i) {
                sensoreObject[valuesName[i]] = values[i];
            }

            sensoriArray.append(sensoreObject);
        }

        QJsonDocument jsonDocument(sensoriArray);
        file.write(jsonDocument.toJson());
        file.close();
    }
}

void Json::nuoviSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName) {
    for (const auto& sensore : nuoviSensori) {
        QString nomeSensore = sensore->getName();
        QString tipoSensore = sensore->getType();
        nuovoSensore(nomeSensore, tipoSensore, fileName);
    }
}

void Json::eliminaSensore(const QString& sensoreDaRimuovere, const QString& fileName) {
    QFile file(fileName);
    QJsonArray sensoriArray = Json::leggiJson();

    for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
        QJsonObject sensoreObject = it->toObject();
        if (sensoreObject["nome"] == sensoreDaRimuovere) {
            it = sensoriArray.erase(it);

            // Scrivi il JSON aggiornato sul file
            if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
                QJsonDocument jsonDocument(sensoriArray);
                file.write(jsonDocument.toJson());
                file.close();
            }
            break;
        }
    }
}

void Json::eliminaSensori(const QString& fileName) {
    QFile file(fileName);
    if (file.exists()) {
        // Apri il file in modalità di scrittura senza eliminare i dati esistenti
        if (file.open(QIODevice::ReadWrite)) {
            // Sovrascrivi i dati del file con un JSON vuoto
            file.resize(0);
            file.close();
        }
    }
}

QVector<Sensor*> Json::caricaSensori(const QString& fileName) {
    QVector<Sensor*> sensori;
    QJsonArray sensoriArray = leggiJson(fileName);

    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        QString nome = sensoreObject["nome"].toString();
        QString tipo = sensoreObject["tipo"].toString();
        //QDateTime timestamp = QDateTime::fromString(sensoreObject["creationDate"].toString(), Qt::ISODate); // Ottieni la data e l'ora dal JSON

        Sensor* nuovoSensore = Json::costruttore(nome, tipo);
        if (nuovoSensore) {
            sensori.append(nuovoSensore);
        } else {
            qDebug() << "Tipo di sensore non valido: " << tipo;
        }
    }

    return sensori;
}

Sensor* Json::costruttore(const QString& nome, const QString& tipo) {
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
