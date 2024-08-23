#include "modifydialog.h"
#include "qpushbutton.h"
#include <qlabel.h>

ModifyDialog::ModifyDialog(QWidget *parent):AddDialog(parent),oldSensorName(),oldSensorType(),
    parametriWidget(new QWidget(this)),
    parametriLayout(new QGridLayout (parametriWidget))
    //misureWidget(new QWidget(parametriWidget)),
    //misureLayout(new QVBoxLayout (misureWidget)),
    //minWidget(new QWidget(parametriWidget)),
    //minLayout(new QVBoxLayout (minWidget)),
    //maxWidget(new QWidget(parametriWidget)),
    //maxLayout(new QVBoxLayout (maxWidget))
{
    //parametriLayout->addWidget(misureWidget);
    //parametriLayout->addWidget(minWidget);
    //parametriLayout->addWidget(maxWidget);

    layout->addWidget(parametriWidget);
    layout->addWidget(confirmButton);
    this->confirmButton->setText("Modifica");


}
QString ModifyDialog::getOldSensorName() const{ return oldSensorName; }
QString ModifyDialog::getOldSensorType() const{ return oldSensorType; }
void ModifyDialog::setOldSensorName(const QString &name){oldSensorName=name;}
void ModifyDialog::setOldSensorType(const QString &type){oldSensorType=type;}
QWidget* ModifyDialog::getParametriWidget() const {return parametriWidget;}
QGridLayout* ModifyDialog::getParametriLayout() const {return parametriLayout;}
QWidget* ModifyDialog::getMisureWidget() const {return misureWidget;}
QVBoxLayout* ModifyDialog::getMisureLayout() const {return misureLayout;}
QWidget* ModifyDialog::getMinWidget() const {return minWidget;}
QVBoxLayout* ModifyDialog::getMinLayout() const {return minLayout;}
QWidget* ModifyDialog::getMaxWidget() const {return maxWidget;}
QVBoxLayout* ModifyDialog::getMaxLayout() const {return maxLayout;}
//QVector<QWidget*>& ModifyDialog::getDatiWidget(){return datiWidget;}
//QVector<QHBoxLayout*>& ModifyDialog::getDatiLayout(){return datiLayout;}
//QVector<QLabel*>& ModifyDialog::getMisure(){return misure;}
//QVector<QLineEdit*>& ModifyDialog::getMinimi(){return minimi;}
//QVector<QLineEdit*>& ModifyDialog::getMassimi(){return massimi;}

