#ifndef JSON_H
#define JSON_H

#include "backend/sensors.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
class Json
{


public:

/*
    QFile file;
    QJsonArray sensoriArray;
    QJsonDocument jsonDocument;
    QJsonObject jsonObject;
*/

    Json();
    QJsonArray leggiJson(const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    void nuovoSensore(const QString& nome, const QString& tipo,const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    void salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    void eliminaSensore( const QString& sensoreDaRimuovere,const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    QVector<Sensor*> caricaSensori(const QString& fileName="C:/Users/bress/Desktop/progetti/File C/Progetto-pao/resources/dati.json");
    static Sensor* costruttore(const QString& nome, const QString& tipo);
};

#endif // JSON_H
