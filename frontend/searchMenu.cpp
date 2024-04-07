#include "searchMenu.h"
#include <QVBoxlayout>
//#include <QString>

SearchMenu::SearchMenu(){
    QVBoxLayout * layout = new QVBoxLayout(this);
    QLineEdit *lineEdit = new QLineEdit("ass");
    layout->addWidget(lineEdit);
    //layout->addWidget(new QMenu());
    layout->addWidget(new QPushButton("add"));
    layout->addWidget(new QPushButton("remove all"));
    layout->addWidget(new QPushButton("submit"));
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    this->setMaximumSize(150,300);
    //std::cout<<QString::toStdString(text());

    // Connessione del segnale textChanged() al relativo slot
    connect(lineEdit, &QLineEdit::textChanged, this, [=](){
        onTextChanged(lineEdit->text());
        });

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
