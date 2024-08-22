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

    // Creazione del layout per la QDialog
    //QVBoxLayout *layout = new QVBoxLayout(this);

    // Aggiunta del QLineEdit al layout
    layout->addWidget(lineEdit);
    layout->addWidget(sceltaTipo);
    //confirmButton->
    //QHBoxLayout* confirmButtonLayout=new QHBoxLayout(confirmButton);
    //confirmButtonLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(confirmButton);

    this->setMaximumSize(200,100);
    this->setModal(true);
    this->setFocus();
    //this->setPalette(Qt::yellow);
    this->setAutoFillBackground(true);

    // Imposta il layout per la QDialog
    setLayout(layout);


}

