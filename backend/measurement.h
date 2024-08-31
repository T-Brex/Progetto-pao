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
<<<<<<< HEAD

    Measurement(const QString&, double v, double min = 0,double max =0);

    Measurement(const QString&, double,QObject *parent = nullptr);

=======
    Measurement(const QString&, double v, double min = 0,double max =0);
    Measurement(const QString&, double,QObject *parent = nullptr);
>>>>>>> 89224e0cdad36821b178c40e5e6c7d4f59df6551
    Measurement(const Measurement&);
    QString getName() const;
    double getValue() const;

    void setValue(double);
    double getRangeMin() const;
    double getRangeMax() const;
    void setRange(double min, double max);

<<<<<<< HEAD




=======
>>>>>>> 89224e0cdad36821b178c40e5e6c7d4f59df6551
};

#endif





