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
        buttonLayout->addWidget(cancelButton);
        buttonLayout->addWidget(confirmButton);
        layout->addLayout(buttonLayout);

        connect(cancelButton, &QPushButton::clicked, this, &DeleteWarning::reject);
        connect(confirmButton, &QPushButton::clicked, this, &DeleteWarning::confirmed);
}
