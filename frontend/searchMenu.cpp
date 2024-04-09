#include "searchMenu.h"
#include <QVBoxlayout>
//#include "frontend/mainwindow.h"
//#include <QString>

SearchMenu::SearchMenu(){
    QVBoxLayout * layout = new QVBoxLayout(this);
    QLineEdit *lineEdit = new QLineEdit("ass");
    QPushButton *add=new QPushButton("add");
    layout->addWidget(lineEdit);
    layout->addWidget(add);
    layout->addWidget(new QPushButton("remove all"));
    layout->addWidget(new QPushButton("submit"));
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    this->setMaximumSize(150,300);
    //std::cout<<QString::toStdString(text());

    // Connessione del segnale textChanged() al relativo slot
    connect(lineEdit, &QLineEdit::textChanged, this, [=](){
        onTextChanged(lineEdit->text());
        });

    connect(add, &QPushButton::clicked, this, &SearchMenu::showDialog);

}

void SearchMenu::onTextChanged(const QString &text) {
    // Puoi fare qualcos'altro qui se necessario
    qDebug()<<text;
}

/*    {
    QLineEdit *searchBox;
    QMenu *orderBy;
    QMenu *filters;
    QPushButton *add;
    QPushButton *removeAll;
    QPushButton *submit;
        }
*/
