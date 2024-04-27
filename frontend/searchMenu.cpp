#include "searchMenu.h"
#include "backend/json.h"
#include <QVBoxlayout>
//#include "frontend/mainwindow.h"
//#include <QString>
#include <QFileDialog>

SearchMenu::SearchMenu(QWidget* parent): QWidget(parent),
    layout(new QVBoxLayout(this)),lineEdit(new QLineEdit(nullptr)),addButton(new QPushButton("Add")),saveAsButton(new QPushButton("Save as")),deleteButton(new QPushButton("Delete"))
{

    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(saveAsButton);
    layout->addWidget(deleteButton);
    //layout->addWidget(new QPushButton("remove all"));
    //layout->addWidget(new QPushButton("submit"));
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    //layout->setAlignment(Qt::AlignTop);

    this->setPalette(Qt::yellow);
    this->setAutoFillBackground(true);

    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    connect(lineEdit, &QLineEdit::textChanged, this, [=](){
        qDebug()<<lineEdit->text();
        });

    connect(addButton, &QPushButton::clicked, this, &SearchMenu::showAddDialog);
    connect(deleteButton, &QPushButton::clicked, this, &SearchMenu::showDeleteDialog);
    connect(saveAsButton, &QPushButton::clicked, this, [=]() {
        QString newFileName = QFileDialog::getSaveFileName(this, tr("Save As"), "", tr("JSON Files (*.json)"));
        if (!newFileName.isEmpty()) {
            Json::saveAs(Json::caricaSensori(), newFileName);
            qDebug() << "Sensori salvati in:" << newFileName;
        }
    });
}
