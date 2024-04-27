#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include "qboxlayout.h"
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QString>


class SearchMenu: public QWidget {
    Q_OBJECT
                        //i widget non sono attributi in quanto sono sempre gli stessi ed è sufficente crearli nel costruttore che non ha parametri per la stessa ragione
                        //memorizza l'ordine di visualizzazione dei sensori (il tipo è da rivedere) è un puntatore perche potrebbero essere più di uno
public:
    //QString *searchName;  //memorizza memorizza l'ultima ricerca della searchBox, potrebbe servire per esempio per modificare la stringa di default della barra (che sara qualcosa tipo "clicca qui per ricercare per nome")
    //unsigned int order;   //memorizza l'ordine di visualizzazione dei sensori (il tipo è da rivedere)
    //unsigned int *filters;
    QVBoxLayout * layout;
    QLineEdit *lineEdit;
    QPushButton *addButton;
    QPushButton *saveAsButton;
    QPushButton *deleteButton;
    SearchMenu(QWidget* parent = nullptr);

public slots:
    //static void onTextChanged(const QString &text);
signals:
    void showAddDialog();
    void showDeleteDialog();
};
#endif // SEARCHMENU_H
