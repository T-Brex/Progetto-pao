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
<<<<<<< HEAD
    Measurement(const QString&, double v, double min = 0,double max =0);
=======
    Measurement(const QString&, double,QObject *parent = nullptr);
>>>>>>> 2cd819f69459d430b2163cad621507adaf986d08
    Measurement(const Measurement&);
    //void updateValue() ;
    QString getName() const;
    double getValue() const;
<<<<<<< HEAD
    void setValue(double);
    double getRangeMin() const;
    double getRangeMax() const;
    void setRange(double min, double max);
=======
    void setValue(double const);

signals:
>>>>>>> 2cd819f69459d430b2163cad621507adaf986d08
};

#endif // MEASUREMENT_H





