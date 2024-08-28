#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include "adddialog.h"
#include "qlabel.h"
#include "backend/sensors.h"

class ModifyDialog : public AddDialog
{
    Q_OBJECT
private:
    QString oldSensorName;
    QString oldSensorType;

    QWidget* parametriWidget;
    QGridLayout* parametriLayout;

    Sensor* mainSensor;

public:
    QString getOldSensorName() const ;
    QString getOldSensorType() const ;
    void setOldSensorName(const QString &name);
    void setOldSensorType(const QString &type);
    QWidget* getParametriWidget() const;
    QGridLayout* getParametriLayout() const;
    Sensor *getSensor();
    void setSensor(const Sensor*);
    //QVector<QWidget*>& getDatiWidget();
    //QVector<QHBoxLayout*>& getDatiLayout();
    //QVector<QLabel*>& getMisure();
    //QVector<QLineEdit*>& getMinimi();
    //QVector<QLineEdit*>& getMassimi();

    ModifyDialog(QWidget *parent);
};

#endif
