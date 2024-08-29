#include "adddialog.h"
#include "qboxlayout.h"
#include <QLineEdit>
#include "qpushbutton.h"
#include <QMessageBox>

AddDialog::AddDialog(QWidget *parent) : QDialog(parent),
    lineEdit(new QLineEdit(this)),sceltaTipo(new QComboBox(this)),confirmButton(new QPushButton("Crea")),layout(new QVBoxLayout(this))

{

    sceltaTipo->addItem("Dust");
    sceltaTipo->addItem("Humidity");
    sceltaTipo->addItem("Wind");
    sceltaTipo->addItem("Termometer");
    sceltaTipo->addItem("AirQuality");

    layout->addWidget(lineEdit);
    layout->addWidget(sceltaTipo);
    layout->addWidget(confirmButton);

    this->setMaximumSize(200,100);
    this->setModal(true);
    this->setFocus();
    this->setAutoFillBackground(true);

    setLayout(layout);
}

QLineEdit* AddDialog::getLineEdit() const { return lineEdit; }
QComboBox* AddDialog::getSceltaTipo() const { return sceltaTipo; }
QPushButton* AddDialog::getConfirmButton() const { return confirmButton; }
QVBoxLayout *AddDialog::getLayout() const { return layout; }

