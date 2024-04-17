#include "searchMenu.h"
#include <QVBoxlayout>
//#include "frontend/mainwindow.h"
//#include <QString>

SearchMenu::SearchMenu(QWidget* parent): QWidget(parent),layout(new QVBoxLayout(this)),lineEdit(new QLineEdit(nullptr)),addButton(new QPushButton("Add")),deleteButton(new QPushButton("Delete")){
    //QVBoxLayout * layout = new QVBoxLayout(this);
    //QLineEdit *lineEdit = new QLineEdit("ass");
    //QPushButton *add=new QPushButton("add");

    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    //layout->addWidget(new QPushButton("remove all"));
    //layout->addWidget(new QPushButton("submit"));
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    this->setMaximumSize(150,300);
    //std::cout<<QString::toStdString(text());

    // Connessione del segnale textChanged() al relativo slot
    /*
    connect(lineEdit, &QLineEdit::textChanged, this, [=](){
        onTextChanged(lineEdit->text());
        });

void SearchMenu::onTextChanged(const QString &text) {
    // Puoi fare qualcos'altro qui se necessario
    qDebug()<<text;


}*/
    connect(addButton, &QPushButton::clicked, this, [=](){
        qDebug()<<lineEdit->text();
    });
    connect(addButton, &QPushButton::clicked, this, &SearchMenu::showAddDialog);
    connect(deleteButton, &QPushButton::clicked, this, &SearchMenu::showDeleteDialog);
}
