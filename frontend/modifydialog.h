#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include "adddialog.h"
#include "qlabel.h"

class ModifyDialog : public AddDialog
{
    Q_OBJECT
private:
    QString oldSensorName;
    QString oldSensorType;
    QWidget* parametriWidget;
    QGridLayout *parametriLayout;
    //QVector<QLabel*> misure;
    QVector<QLineEdit*> minimi;
    QVector<QLineEdit*> massimi;
public:
    QString getOldSensorName() const ;
    QString getOldSensorType() const ;
    void setOldSensorName(const QString &name);
    void setOldSensorType(const QString &type);
    QWidget* getParametriWidget();
    QGridLayout* getParametriLayout();
    //QVector<QLabel*>& getMisure();
    QVector<QLineEdit*>& getMinimiEdit();
    QVector<QLineEdit*>& getMassimiEdit();

    ModifyDialog(QWidget *parent);
};

#endif
