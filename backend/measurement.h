#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <QObject>

class Measurement : public QObject
{
    Q_OBJECT
private:
    QString name;
    double value;
    double rangeMin;
    double rangeMax;

public:
    //explicit Measurement(QObject *parent = nullptr);
    Measurement(const QString&, double v, double min = 0,double max =0);
    Measurement(const Measurement&);
    //void updateValue() ;
    QString getName() const;
    double getValue() const;
    void setValue(double);
    double getRangeMin() const;
    double getRangeMax() const;
    void setRange(double min, double max);
signals:
};

#endif // MEASUREMENT_H





