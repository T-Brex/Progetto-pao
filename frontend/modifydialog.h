#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include "adddialog.h"

class ModifyDialog : public AddDialog
{
    Q_OBJECT
public:
    QString oldSensorName;
    QString oldSensorType;

    ModifyDialog(QWidget *parent);
};

#endif // MODIFYDIALOG_H
