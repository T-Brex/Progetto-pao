#include "searchMenu.h"
#include "backend/sensors.h"
#include <QVBoxlayout>
//#include "frontend/mainwindow.h"
//#include <QString>
#include <QFileDialog>
#include "backend/json.h"
#include "frontend/sensorPanel.h"
#include "qscrollarea.h"

SearchMenu::SearchMenu(QWidget* parent): QWidget(parent),
    layout(new QVBoxLayout(this)),foundSensorsWidget(new QWidget),
    foundSensorsLayout(new QVBoxLayout(foundSensorsWidget)),
    lineEdit(new QLineEdit(nullptr)),
    addButton(new QPushButton("Add")),importButton(new QPushButton("Import")),saveAsButton(new QPushButton("Save as"))
    ,deleteButton(new QPushButton("Delete")),deleteAllButton(new QPushButton("Delete All"))
{

    //QWidget *foundSensorsWidget=new QWidget(nullptr);
    //QVBoxLayout *foundSensorsLayout=new QVBoxLayout(foundSensorsWidget);
    /*QScrollArea* sensScrollArea=new QScrollArea(nullptr);
    sensScrollArea->setWidgetResizable(true);
    sensScrollArea->setAlignment(Qt::AlignTop);
    sensScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sensScrollArea->setWidget(foundSensorsWidget);*/

    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(importButton);
    layout->addWidget(saveAsButton);
    layout->addWidget(deleteButton);
    layout->addWidget(deleteAllButton);
    layout->addWidget(foundSensorsWidget);



    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    layout->setAlignment(Qt::AlignTop);

    this->setPalette(Qt::yellow);
    this->setAutoFillBackground(true);

    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Minimum);




    //QVBoxLayout* foundSensorsLayout = new QVBoxLayout();
    //layout->addLayout(foundSensorsLayout);  // Aggiungi il layout al layout principale

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
    connect(importButton, &QPushButton::clicked, this, &SearchMenu::showImportDialog);
    connect(deleteButton, &QPushButton::clicked, this, &SearchMenu::showDeleteDialog);
    connect(saveAsButton, &QPushButton::clicked, this, &SearchMenu::showSaveAsDialog);
    connect(deleteAllButton, &QPushButton::clicked, this, &SearchMenu::showDeleteAllDialog);
    //connect(editIcon, &QPushButton::clicked, this, &SensorPanel::avviaModifica);
}
