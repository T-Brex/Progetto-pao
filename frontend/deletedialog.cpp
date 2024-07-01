#include "deletedialog.h"
#include "qjsonarray.h"
#include "qjsonobject.h"
#include "backend/json.h"

DeleteDialog::DeleteDialog(QWidget *parent):QDialog(parent),sceltaNome(new QComboBox(this)),deleteButton(new QPushButton("Elimina"))
{
    QJsonArray sensoriArray = Json::leggiJson();
    QVBoxLayout *layout = new QVBoxLayout(this);
    for (const auto& sensore : sensoriArray) {
        QJsonObject sensoreObject = sensore.toObject();
        QString nome = sensoreObject["nome"].toString();
        sceltaNome->addItem(nome);
    }
    layout->addWidget(sceltaNome);
    layout->addWidget(deleteButton);
}
