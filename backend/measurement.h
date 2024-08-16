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
    Measurement(const QString&, double);
    Measurement(const Measurement&);
    QString getName() const;
    double getValue() const;
    void setValue(double);

signals:
};

#endif // MEASUREMENT_H
