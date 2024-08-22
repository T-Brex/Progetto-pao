#include "modifydialog.h"
#include "qpushbutton.h"
#include <qlabel.h>

ModifyDialog::ModifyDialog(QWidget *parent):AddDialog(parent),oldSensorName(),oldSensorType() {




    QWidget* titoliWidget=new QWidget(this);
    QHBoxLayout*titoliLayout=new QHBoxLayout (titoliWidget);
    QLabel* misura = new QLabel("Misura",this);
    QLabel* min = new QLabel("Min",this);
    QLabel* max = new QLabel("Max",this);
    titoliLayout->addWidget(misura);
    titoliLayout->addWidget(min);
    titoliLayout->addWidget(max);
    layout->addWidget(titoliWidget);




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

QVector<QWidget*>& ModifyDialog::getDatiWidget(){return datiWidget;}
QVector<QHBoxLayout*>& ModifyDialog::getDatiLayout(){return datiLayout;}
QVector<QLabel*>& ModifyDialog::getMisure(){return misure;}
QVector<QLineEdit*>& ModifyDialog::getMinimi(){return minimi;}
QVector<QLineEdit*>& ModifyDialog::getMassimi(){return massimi;}

