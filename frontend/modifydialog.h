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

    QVector<QLineEdit*> minimiEdit;
    QVector<QLineEdit*> massimiEdit;


public:
    ModifyDialog(QWidget *parent);
    QString getOldSensorName() const ;
    QString getOldSensorType() const ;
    void setOldSensorName(const QString &name);
    void setOldSensorType(const QString &type);

    QWidget* getParametriWidget() const;
    QGridLayout* getParametriLayout() const;
    QVector<QLineEdit*>& getMinimiEdit();
    QVector<QLineEdit*>& getMassimiEdit();
    //Sensor *getSensor();
    //void setSensor(const Sensor*);
    //QVector<QWidget*>& getDatiWidget();
    //QVector<QHBoxLayout*>& getDatiLayout();
    //QVector<QLabel*>& getMisure();
    //QVector<QLineEdit*>& getMinimi();
    //QVector<QLineEdit*>& getMassimi();
private slots:
    void onSceltaTipoChanged();



};

#endif
