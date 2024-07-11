#include "modifydialog.h"
#include "qpushbutton.h"

ModifyDialog::ModifyDialog(QWidget *parent):AddDialog(parent),oldSensorName(),oldSensorType() {
    //this->lineEdit->setText(oldSensorName);
    //this->sceltaTipo->setEditText(oldSensorType);

    this->newButton->setText("Modifica");
}
void ModifyDialog::setOldSensorName(const QString &name)
{
    oldSensorName=name;
}

void ModifyDialog::setOldSensorType(const QString &type)
{
    oldSensorType=type;
}
