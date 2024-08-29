#include "modifydialog.h"
#include "qpushbutton.h"
#include <qlabel.h>
#include "backend/json.h"
#include "backend/sensorgetter.h"
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
    connect(sceltaTipo, QOverload<int>::of(&QComboBox::currentIndexChanged),this, &ModifyDialog::onSceltaTipoChanged);
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
QVector<QLineEdit*> &ModifyDialog::getMinimiEdit() {return minimiEdit;}
QVector<QLineEdit *> &ModifyDialog::getMassimiEdit() {return massimiEdit;}
void ModifyDialog::onSceltaTipoChanged(){

    Sensor *sensor=Json::costruttore("momentaneo",sceltaTipo->currentText());
    QVector<Measurement*> mVec;
    SensorGetter sg(mVec);
    sensor->accept(sg);

    QLayoutItem* item;
    while ((item = parametriLayout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }

    QLabel* misuraLabel = new QLabel("Misura");
    misuraLabel->setAlignment(Qt::AlignCenter);
    parametriLayout->addWidget(misuraLabel, 0, 0);

    QLabel* minLabel = new QLabel("Min");
    minLabel->setAlignment(Qt::AlignCenter);
    parametriLayout->addWidget(minLabel, 0, 1);

    QLabel* maxLabel = new QLabel("Max");
    maxLabel->setAlignment(Qt::AlignCenter);
    parametriLayout->addWidget(maxLabel, 0, 2);

    massimiEdit.clear();
    minimiEdit.clear();
    // Aggiungi i dati del sensore alla griglia, centrati
    for (int i = 0; i < mVec.size(); i++) {
        QLabel* misura = new QLabel(mVec[i]->getName());
        misura->setAlignment(Qt::AlignCenter);
        parametriLayout->addWidget(misura, i + 1, 0); // Colonna 0 per "Misura"

        QLineEdit* minEdit = new QLineEdit();
        minEdit->setPlaceholderText("-");
        minEdit->setAlignment(Qt::AlignCenter);
        parametriLayout->addWidget(minEdit, i + 1, 1); // Colonna 1 per "Min"
        minimiEdit.push_back(minEdit); // Aggiungi QLineEdit al QVector

        QLineEdit* maxEdit = new QLineEdit();
        maxEdit->setPlaceholderText("-");
        maxEdit->setAlignment(Qt::AlignCenter);
        parametriLayout->addWidget(maxEdit, i + 1, 2); // Colonna 2 per "Max"
        massimiEdit.push_back(maxEdit); // Aggiungi QLineEdit al QVector
    }
    show();
}
//Sensor* ModifyDialog::getSensor(){return mainSensor;}
//void ModifyDialog::setSensor(const Sensor *s){mainSensor=const_cast<Sensor*>(s);}
//QVector<QWidget*>& ModifyDialog::getDatiWidget(){return datiWidget;}
//QVector<QHBoxLayout*>& ModifyDialog::getDatiLayout(){return datiLayout;}
//QVector<QLabel*>& ModifyDialog::getMisure(){return misure;}
//QVector<QLineEdit*>& ModifyDialog::getMinimi(){return minimi;}
//QVector<QLineEdit*>& ModifyDialog::getMassimi(){return massimi;}

