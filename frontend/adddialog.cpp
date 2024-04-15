#include "adddialog.h"
#include "qboxlayout.h"
#include <QLineEdit>
#include "qpushbutton.h"

AddDialog::AddDialog(QWidget *parent) : QDialog(parent),lineEdit(new QLineEdit(this)),sceltaTipo(new QComboBox(this)),newButton(new QPushButton("Crea"))
    //,emptyName(new QMessageBox("Inserire un nome"))
{
    emptyName.setText("Inserire un nome");

    sceltaTipo->addItem("Dust");
    sceltaTipo->addItem("Humidity");
    sceltaTipo->addItem("Wind");
    sceltaTipo->addItem("Termometer");
    sceltaTipo->addItem("AirQuality");
    //lineEdit->setFocus();

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

    connect(newButton,  &QPushButton::clicked, this, &AddDialog::newTrigger);
    //connect(newButton,  &QPushButton::clicked, this, &AddDialog::newTrigger);

}

