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
    static QString path;
    static QJsonArray leggiJson(const QString& fileName=path);
    static QString nuovoSensore(const QString& nome, const QString& tipo,const QString& fileName=path);
    static void nuoviSensori(const QVector<Sensor*>& nuoviSensori, const QString& fileName=path);
    static QString modificaSensore(const QString& nomeSensore, const QString& nuovoNome, const QString& nuovoTipo, const QString& fileName=path);
    static void saveAs( const QVector<Sensor*>& sensori, const QString& newFileName=path);
    static void eliminaSensore( const QString& sensoreDaRimuovere,const QString& fileName=path);
    static void eliminaSensori(const QString& fileName=path);
    static QVector<Sensor*> trovaSensoriPerNome(const QString& substrNome, const QString& fileName=path);
    static QVector<Sensor*> caricaSensori(const QString& fileName=path);

    static Sensor* costruttore(const QString& nome, const QString& tipo);
};

#endif // JSON_H
