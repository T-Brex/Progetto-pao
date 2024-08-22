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
    QVector<QWidget*> datiWidget;
    QVector<QHBoxLayout*> datiLayout;
    QVector<QLabel*> misure;
    QVector<QLineEdit*> minimi;
    QVector<QLineEdit*> massimi;
public:
    QString getOldSensorName() const ;
    QString getOldSensorType() const ;
    void setOldSensorName(const QString &name);
    void setOldSensorType(const QString &type);
    QVector<QWidget*>& getDatiWidget();
    QVector<QHBoxLayout*>& getDatiLayout();
    QVector<QLabel*>& getMisure();
    QVector<QLineEdit*>& getMinimi();
    QVector<QLineEdit*>& getMassimi();

    ModifyDialog(QWidget *parent);
};

#endif
