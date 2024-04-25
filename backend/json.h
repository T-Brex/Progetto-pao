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

    static QJsonArray leggiJson(const QString& fileName="dati.json");
    static QString nuovoSensore(const QString& nome, const QString& tipo,const QString& fileName="dati.json");
    static void salvaSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName="dati.json");
    static void eliminaSensore( const QString& sensoreDaRimuovere,const QString& fileName="dati.json");
    static QVector<Sensor*> caricaSensori(const QString& fileName="dati.json");

    static Sensor* costruttore(const QString& nome, const QString& tipo);
};

#endif // JSON_H
