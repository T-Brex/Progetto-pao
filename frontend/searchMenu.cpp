#include "searchMenu.h"
#include <QVBoxlayout>

SearchMenu::SearchMenu(){
    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(new QLineEdit("ass"));
    //layout->addWidget(new QMenu());
    layout->addWidget(new QPushButton("add"));
    layout->addWidget(new QPushButton("remove all"));
    layout->addWidget(new QPushButton("submit"));
    layout->setContentsMargins(5,5,5,5);  // (x,y,w,h)
    this->setMaximumSize(150,300);
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
