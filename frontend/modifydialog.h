#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include "adddialog.h"

class ModifyDialog : public AddDialog
{
    Q_OBJECT
private:
    QString oldSensorName;
    QString oldSensorType;
public:
    QString getOldSensorName() const { return oldSensorName; }
    QString getOldSensorType() const { return oldSensorType; }
    void setOldSensorName(const QString &name);
    void setOldSensorType(const QString &type);

    ModifyDialog(QWidget *parent);
};

#endif
