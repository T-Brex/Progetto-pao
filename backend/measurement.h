#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <QObject>

class Measurement : public QObject
{
    Q_OBJECT
private:
    QString name;
    double value;
public:
    //explicit Measurement(QObject *parent = nullptr);
    Measurement(const QString&, double,QObject *parent = nullptr);
    Measurement(const Measurement&);
    //void updateValue() ;
    QString getName() const;
    double getValue() const;
    void setValue(double const);

signals:
};

#endif // MEASUREMENT_H
