#include "deletewarning.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"

DeleteWarning::DeleteWarning(QWidget *parent): QDialog(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *messageLabel = new QLabel("Sei sicuro di voler eliminare tutti i sensori?", this);
        layout->addWidget(messageLabel);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        QPushButton *cancelButton = new QPushButton("Annulla", this);
        QPushButton *confirmButton = new QPushButton("Conferma", this);       
        buttonLayout->addWidget(confirmButton);
        buttonLayout->addWidget(cancelButton);
        layout->addLayout(buttonLayout);

        connect(cancelButton, &QPushButton::clicked, this, &DeleteWarning::reject);
        connect(confirmButton, &QPushButton::clicked, this, &DeleteWarning::confirmed);
}

DeleteWarning::DeleteWarning(const QString &sensorName, QWidget *parent): QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *messageLabel = new QLabel("Sei sicuro di voler eliminare " +sensorName+ "?", this);
    layout->addWidget(messageLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *confirmButton = new QPushButton("Conferma", this);
    QPushButton *cancelButton = new QPushButton("Annulla", this);
    buttonLayout->addWidget(confirmButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    connect(cancelButton, &QPushButton::clicked, this, &DeleteWarning::reject);
    connect(confirmButton, &QPushButton::clicked, this, &DeleteWarning::confirmed);
}
