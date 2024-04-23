#include "json.h"
#include "qfileinfo.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qmessagebox.h"
#include <QJsonArray>
#include <QFile>

Json::Json()
{

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

QString Json::nuovoSensore(const QString nome, const QString tipo, const QString fileName){
    // Se nome != ""
    //qDebug()<<fileName;
    if(!nome.isEmpty()){
        QFileInfo fileInfo(fileName);

        // Verifica se il file esiste
        if (fileInfo.exists()) {
            qDebug() << "Percorso assoluto del file:" << fileInfo.absoluteFilePath();
            qDebug() << "Nome del file:" << fileInfo.fileName();
            qDebug() << "Estensione del file:" << fileInfo.suffix();
            qDebug() << "Permessi di lettura:" << (fileInfo.isReadable() ? "Sì" : "No");
            qDebug() << "Permessi di scrittura:" << (fileInfo.isWritable() ? "Sì" : "No");
            qDebug() <<"";

        } else {
            qDebug() << "Il file non esiste.";
        }
        QJsonArray sensoriArray = Json::leggiJson();
        //qDebug()<<"fileName";
        QFile file(fileName);


        // Verifica se il sensore è già presente nel JSON
        bool sensorePresente = false;
        for (auto it = sensoriArray.begin(); it != sensoriArray.end(); ++it) {
            QJsonObject sensoreObject = it->toObject();
            if (sensoreObject["nome"] == nome) {
                QMessageBox *existingName=new QMessageBox(nullptr);
                existingName->setIcon(QMessageBox::Warning);
                existingName->setText("Il sensore '" + nome + "' esiste già nel file");
                existingName->open();
                sensorePresente = true;
                qDebug() << "Il sensore '"<< nome <<"' esiste già nel file";
                return "exsist";
                break;
            }
        }
        // Se il sensore non è presente, aggiungilo al JSON
        if (!sensorePresente) {
            Sensor* sensore = Json::costruttore(nome,tipo);
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
                return "ok";
            } else {
                qDebug() << "Errore nell'apertura del file";
                return "diocane";
            }
            return "diocane";
            //this->updateSensors();
        }
    }else{
        QMessageBox *emptyName=new QMessageBox(nullptr);
        emptyName->setIcon(QMessageBox::Warning);
        emptyName->setText("Inserire un nome");
        emptyName->open();
        qDebug()<<"Inserire un nome";
        return "empty";
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
    QFileInfo fileInfo(fileName);

    // Verifica se il file esiste
    if (fileInfo.exists()) {
        qDebug() << "Percorso assoluto del file:" << fileInfo.absoluteFilePath();
        qDebug() << "Nome del file:" << fileInfo.fileName();
        qDebug() << "Estensione del file:" << fileInfo.suffix();
        qDebug() << "Permessi di lettura:" << (fileInfo.isReadable() ? "Sì" : "No");
        qDebug() << "Permessi di scrittura:" << (fileInfo.isWritable() ? "Sì" : "No");
    } else {
        qDebug() << "Il file non esiste.";
    }

    // Rimuovi il sensore specificato, se presente
    qDebug()<<sensoreDaRimuovere;
    if (!sensoreDaRimuovere.isEmpty()) {
        QFile file(fileName);
        QJsonArray sensoriArray = Json::leggiJson();

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
