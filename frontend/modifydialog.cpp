#include "modifydialog.h"
#include "qpushbutton.h"
#include <qlabel.h>
#include "backend/json.h"
#include "backend/sensorgetter.h"

ModifyDialog::ModifyDialog(QWidget *parent):AddDialog(parent),oldSensorName(),oldSensorType(),
    parametriWidget(new QWidget(this)),
    parametriLayout(new QGridLayout (parametriWidget))
{
    //connect(sceltaTipo, QOverload<int>::of(&QComboBox::currentIndexChanged),this, &ModifyDialog::onSceltaTipoChanged);
    layout->addWidget(parametriWidget);
    layout->addWidget(confirmButton);
    layout->removeWidget(confirmButton);
    this->confirmButton->setText("Modifica");


}
QString ModifyDialog::getOldSensorName() const{ return oldSensorName; }
QString ModifyDialog::getOldSensorType() const{ return oldSensorType; }
void ModifyDialog::setOldSensorName(const QString &name)
{
    oldSensorName=name;
}

void ModifyDialog::setOldSensorType(const QString &type)
{
    oldSensorType=type;
}

QWidget* ModifyDialog::getParametriWidget(){return parametriWidget;}
QGridLayout* ModifyDialog::getParametriLayout(){return parametriLayout;}
//QVector<QLabel*>& ModifyDialog::getMisure(){return misure;}
QVector<QLineEdit*>& ModifyDialog::getMinimiEdit(){return minimi;}
QVector<QLineEdit*>& ModifyDialog::getMassimiEdit(){return massimi;}

