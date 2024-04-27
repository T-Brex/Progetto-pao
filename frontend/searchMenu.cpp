#include "searchMenu.h"
#include <QVBoxlayout>
//#include "frontend/mainwindow.h"
//#include <QString>
#include <QFileDialog>

SearchMenu::SearchMenu(QWidget* parent): QWidget(parent),
    layout(new QVBoxLayout(this)),lineEdit(new QLineEdit(nullptr)),
    addButton(new QPushButton("Add")),importButton(new QPushButton("Import")),saveAsButton(new QPushButton("Save as")),deleteButton(new QPushButton("Delete")),deleteAllButton(new QPushButton("Delete All"))
{

    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(importButton);
    layout->addWidget(saveAsButton);
    layout->addWidget(deleteButton);
    layout->addWidget(deleteAllButton);

    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    layout->setAlignment(Qt::AlignTop);

    this->setPalette(Qt::yellow);
    this->setAutoFillBackground(true);

    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Minimum);

    connect(lineEdit, &QLineEdit::textChanged, this, [=](){
        qDebug()<<lineEdit->text();
        });

    connect(addButton, &QPushButton::clicked, this, &SearchMenu::showAddDialog);
    connect(importButton, &QPushButton::clicked, this, &SearchMenu::showImportDialog);
    connect(deleteButton, &QPushButton::clicked, this, &SearchMenu::showDeleteDialog);
    connect(saveAsButton, &QPushButton::clicked, this, &SearchMenu::showSaveAsDialog);
    connect(deleteAllButton, &QPushButton::clicked, this, &SearchMenu::showDeleteAllDialog);
}
