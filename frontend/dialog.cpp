#include "dialog.h"
#include "qboxlayout.h"
#include <QLineEdit>
#include "qpushbutton.h"

Dialog::Dialog(QWidget *parent) : QDialog(nullptr),lineEdit(new QLineEdit(this)),sceltaTipo(new QComboBox(this)),newButton(new QPushButton("Crea")) {
        sceltaTipo->addItem("Dust");
        sceltaTipo->addItem("Humidity");
        sceltaTipo->addItem("Wind");
        sceltaTipo->addItem("Termometer");
        sceltaTipo->addItem("AirQuality");

        // Creazione del layout per la QDialog
        QVBoxLayout *layout = new QVBoxLayout(this);

        // Aggiunta del QLineEdit al layout
        layout->addWidget(lineEdit);
        layout->addWidget(sceltaTipo);
        layout->addWidget(newButton);

        this->setMaximumSize(200,100);
        this->setModal(true);
        this->setFocus();
        this->setPalette(Qt::yellow);
        this->setAutoFillBackground(true);

        // Imposta il layout per la QDialog
        setLayout(layout);

        connect(newButton,  &QPushButton::clicked, this, &Dialog::newTrigger);
        //connect(this, &Dialog::accept, this, &QDialog::close);

}

Sensor* Dialog::costruttore(const QString& nome, const QString& tipo){
    Sensor* nuovoSensore = nullptr;
    if (tipo == "Dust") {
        nuovoSensore = new Dust(nome);
    } else if (tipo == "Humidity") {
        nuovoSensore = new Humidity(nome);
    } else if (tipo == "Wind") {
        nuovoSensore = new Wind(nome);
    } else if (tipo == "Termometer") {
        nuovoSensore = new Termometer(nome);
    } else if (tipo == "AirQuality") {
        nuovoSensore = new AirQuality(nome);
    }
    return nuovoSensore;
}

