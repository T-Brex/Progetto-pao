#include "backend/json.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <QJsonArray>
#include <QFile>
#include <QDateTime> // Aggiunto per gestire la data e l'ora

Json::Json() {}
QString Json::path="dati.json";
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
void Json::nuoviSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName) {
    for (const auto& sensore : nuoviSensori) {
        QString nomeSensore = sensore->getName();
        QString tipoSensore = sensore->getType();
        nuovoSensore(nomeSensore, tipoSensore, fileName);
    }
}


QString Json::nuovoSensore(const QString& nome, const QString& tipo, const QString& fileName) {
    if (nome.isEmpty()) {
        return "empty";
    } else {
        QJsonArray sensoriArray = Json::leggiJson(fileName);
        QFile file(fileName);

        // Verifica se il sensore è già presente nel JSON
        bool sensorePresente = false;
        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            qDebug()<<sensoreObject["nome"]<<"=="<<nome;
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
        }
    }
return "0";
}

QString Json::modificaSensore(const QString& nomeSensore, const QString& nuovoNome, const QString& nuovoTipo, const QString& fileName) {
    if (nuovoNome.isEmpty()) {
        qDebug() << "Il nuovo nome del sensore non può essere vuoto.";
        return "empty";
    }

    QJsonArray sensoriArray = Json::leggiJson(fileName);

    bool nomeEsistente = false;
    for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
        QJsonObject sensoreObject = it->toObject();
        if (sensoreObject["nome"] == nomeSensore) {

            if (sensoreObject["nome"] != nuovoNome) {
                // Verifica se il nuovo nome del sensore esiste già
                for (auto it2 = sensoriArray.begin(); it2 != sensoriArray.end(); ++it2) {
                    QJsonObject sensoreObject2 = it2->toObject();
                    if (sensoreObject2["nome"] == nuovoNome) {
                        nomeEsistente = true;
                        break;
                    }
                }
            } else {
                // Il nuovo nome è lo stesso del nome attuale del sensore
                nomeEsistente = false;
            }
            break;
        }
    }

    if (!nomeEsistente) {
        // Modifica il nome e il tipo del sensore
        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            if (sensoreObject["nome"] == nomeSensore) {
                sensoreObject["nome"] = nuovoNome;
                sensoreObject["tipo"] = nuovoTipo;
                *it = sensoreObject; // Aggiorna l'oggetto nell'array
                break;
            }
        }

        // Scrivi il JSON aggiornato sul file
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QJsonDocument jsonDocument(sensoriArray);
            file.write(jsonDocument.toJson());
            file.close();
            return "ok";
        } else {
            qDebug() << "Impossibile aprire il file per la scrittura.";
            return "fileError";
        }
    } else {
        qDebug() << "Esiste già un sensore con il nome specificato.";
        return "existing";
    }
}
bool Json::saveAs(const QVector<Sensor*>& sensori, const QString& newFileName) {
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

            // Verifica che values e valuesName abbiano la stessa dimensione
            if (values.size() != valuesName.size()) {
                qWarning() << "Errore: dimensioni di values e valuesName non corrispondono.";
                continue; // Oppure gestisci l'errore in un altro modo
            }

            for (int i = 0; i < values.size(); ++i) {
                // Converte il valore numerico in QJsonValue
                QJsonValue value = QJsonValue::fromVariant(values[i]);
                sensoreObject[valuesName[i]] = value;
            }

            sensoriArray.append(sensoreObject);
        }

        QJsonDocument jsonDocument(sensoriArray);
        file.write(jsonDocument.toJson());
        file.close();
        return true;
    }

    return false;
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


        Sensor* nuovoSensore = Json::costruttore(nome, tipo);
        if (nuovoSensore) {
            sensori.append(nuovoSensore);
        } else {
            qDebug() << "Tipo di sensore non valido: " << tipo;
        }
    }

    return sensori;
}

QVector<Sensor*> Json::trovaSensoriPerNome(const QString& substrNome, const QString& fileName) {
    QVector<Sensor*> sensoriTrovati;
    QJsonArray sensoriArray = leggiJson(fileName);

    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        QString nome = sensoreObject["nome"].toString();

        // Controlla se il nome del sensore contiene la sottostringa specificata
        if (nome.contains(substrNome, Qt::CaseInsensitive)) {
            QString tipo = sensoreObject["tipo"].toString();
            Sensor* nuovoSensore = costruttore(nome, tipo);
            if (nuovoSensore) {
                sensoriTrovati.append(nuovoSensore);
            } else {
                qDebug() << "Tipo di sensore non valido: " << tipo;
            }
        }
    }

    return sensoriTrovati;
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
