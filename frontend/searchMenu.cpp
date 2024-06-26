#include "searchMenu.h"
#include "backend/sensors.h"
#include <QVBoxlayout>
#include <QFileDialog>
#include "backend/json.h"
#include "qlabel.h"

SearchMenu::SearchMenu(QWidget* parent): QWidget(parent),
    layout(new QVBoxLayout(this)),foundSensorsWidget(new QWidget),
    foundSensorsLayout(new QVBoxLayout(foundSensorsWidget)),
    lineEdit(new QLineEdit(nullptr)),
    addButton(new QPushButton("Add"))
    ,deleteButton(new QPushButton("Delete")),deleteAllButton(new QPushButton("Delete All"))
{
    //FARE FUNZIONE
    //da line 17 a linea 30 c'è lo stesso codice da line 62 a 76
    lineEdit->setPlaceholderText("Ricerca sensori");
    QVector<Sensor*> foundSensors = Json::trovaSensoriPerNome(lineEdit->text());
    for (const auto& sensor : foundSensors) {
        QWidget* sensorWidget=new QWidget(nullptr);
        QHBoxLayout* sensorLayout=new QHBoxLayout(sensorWidget);
        QPushButton* modifica = new QPushButton("Modifica");
        sensorLayout->addWidget(new QLabel(sensor->getName()));
        sensorLayout->addWidget(new QLabel(sensor->getType()));
        sensorLayout->addWidget(modifica);
        connect(modifica,&QPushButton::clicked,this,[sensor, this]() {
            emit showModifyDialog(sensor);
        });

        foundSensorsLayout->addWidget(sensorWidget);
    }

    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    layout->addWidget(deleteAllButton);
    layout->addWidget(foundSensorsWidget);

    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    layout->setAlignment(Qt::AlignTop);

    this->setPalette(Qt::lightGray);
    this->setAutoFillBackground(true);
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Minimum);






    connect(lineEdit, &QLineEdit::textChanged, this, [this](){
        // Rimuovi i widget precedenti dal layout dei sensori trovati
        QLayoutItem* item;
        while ((item = foundSensorsLayout->takeAt(0)) != nullptr) {
            //qDebug()<<"dentrox2";
            delete item->widget();
            delete item;
        }

         // Aggiungi i pulsanti dei sensori trovati al layout
        QVector<Sensor*> foundSensors = Json::trovaSensoriPerNome(lineEdit->text());
        for (const auto& sensor : foundSensors) {
            QWidget* sensorWidget=new QWidget(nullptr);
            QHBoxLayout* sensorLayout=new QHBoxLayout(sensorWidget);
            QPushButton* modifica = new QPushButton("Modifica");
            sensorLayout->addWidget(new QLabel(sensor->getName()));
            sensorLayout->addWidget(new QLabel(sensor->getType()));
            sensorLayout->addWidget(modifica);
            foundSensorsLayout->addWidget(sensorWidget);

            connect(modifica,&QPushButton::clicked,this,[sensor, this]() {
                emit showModifyDialog(sensor);
            });
        }
    });



    connect(addButton, &QPushButton::clicked, this, &SearchMenu::showAddDialog);
    connect(deleteButton, &QPushButton::clicked, this, &SearchMenu::showDeleteDialog);
    connect(deleteAllButton, &QPushButton::clicked, this, &SearchMenu::showDeleteAllDialog);
}
