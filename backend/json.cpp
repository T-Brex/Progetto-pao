#include "backend/json.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "sensorgetter.h"
#include <QJsonArray>
#include <QFile>
#include <QDateTime>
// Aggiunto per gestire la data e l'ora
#include "backend/dustSensor.h"
#include "backend/humiditySensor.h"
#include "backend/termometerSensor.h"
#include "backend/windSensor.h"
#include "backend/airQualitySensor.h"

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
            //qDebug()<<sensoreObject["nome"]<<"=="<<nome;
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
            sensoreObject["tipo"] = tipo;
            sensoreObject["creationDate"] = sensore->getCreationDate().toString(Qt::ISODate); // Aggiungi data e ora al JSON



            QVector<Measurement*> measurements;
            SensorGetter sg(measurements);
            sensore->accept(sg);

            for (auto i = 0; i < measurements.size(); ++i) {
                sensoreObject[measurements[i]->getName()] = measurements[i]->getValue();
                sensoreObject["min"+measurements[i]->getName()] = measurements[i]->getRangeMin();
                sensoreObject["max"+measurements[i]->getName()] = measurements[i]->getRangeMax();
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

QString Json::modificaSensore(const QString& nomeSensore, const QString& nuovoNome, const QString& nuovoTipo,const QVector<double>minimi,const QVector<double>massimi, const QString& fileName) {
    if (nuovoNome.isEmpty()) {
        qDebug() << "Il nuovo nome del sensore non può essere vuoto.";
        return "empty";
    }

    QJsonArray sensoriArray = Json::leggiJson(fileName);
    QVector<Sensor*> sensorVec = Json::caricaSensori(fileName);

    bool nomeGiaEsistente = false;
    for (auto it = sensoriArray.begin(); it != sensoriArray.end() && !nomeGiaEsistente; ++it) {
        QJsonObject sensoreObject = it->toObject();
        if (sensoreObject["nome"] == nomeSensore)
        {
            if (sensoreObject["nome"] != nuovoNome) {
                // Verifica se il nuovo nome del sensore esiste già
                for (auto it2 = sensoriArray.begin(); it2 != sensoriArray.end(); ++it2) {
                    QJsonObject sensoreObject2 = it2->toObject();
                    if (sensoreObject2["nome"] == nuovoNome) {
                        nomeGiaEsistente = true;
                        return "already exsist";
                    }
                }
            } else {
                // Il nuovo nome è lo stesso del nome attuale del sensore
                nomeGiaEsistente = false;
            }

        }
    }

    if (!nomeGiaEsistente) {
        // Modifica il nome e il tipo del sensore
        for(int i=0;i<sensoriArray.size();i++){
            QJsonObject sensoreObject = sensoriArray[i].toObject();
            if (sensoreObject["nome"] == nomeSensore) {
                sensoreObject["nome"] = nuovoNome;
                sensoreObject["tipo"] = nuovoTipo;

                QVector<Measurement*> mVec;
                SensorGetter sg(mVec);
                const_cast<Sensor*>(sensorVec[i])->accept(sg);
                for(int i=0;i<mVec.size();i++){
                    sensoreObject["min"+mVec[i]->getName()] = minimi[i];
                    sensoreObject["max"+mVec[i]->getName()] = massimi[i];
                }

                sensoriArray[i] = sensoreObject; // Aggiorna l'oggetto nell'array
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

            QVector<Measurement*> measurements;
            SensorGetter sg(measurements);
            sensore->accept(sg);

            for (int i = 0; i < measurements.size(); ++i) {
                // Converte il valore numerico in QJsonValue
                QJsonValue value = QJsonValue::fromVariant(measurements[i]->getValue());
                sensoreObject[measurements[i]->getName()] = value;
                sensoreObject["max"+measurements[i]->getName()]=measurements[i]->getRangeMax();
                sensoreObject["min"+measurements[i]->getName()]=measurements[i]->getRangeMin();

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
            QVector<Measurement*> measurements;
            SensorGetter sg(measurements);
            nuovoSensore->accept(sg);
            for(int i=0;i<measurements.size();i++){
            measurements[i]->setRange(sensoreObject["min"+measurements[i]->getName()].toDouble(),
                                        sensoreObject["max"+measurements[i]->getName()].toDouble());
            }

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
//avrei bisogno di un sensor che chiami l'accept(sensorConstructor), ma quale dovrebbe essere il sensor in questione?
//in questo caso credo si debba lasciare così dato che non esiste un sensor finchè non lo creo con il new
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
