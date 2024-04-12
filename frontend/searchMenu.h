#ifndef SEARCHMENU_H
#define SEARCHMENU_H
/*
#include<QString>
#include "backend\sensors.h"
#include <QIcon>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
*/
#include "qboxlayout.h"
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QString>
#endif // SEARCHMENU_H
class SearchMenu: public QWidget {
    Q_OBJECT
private:                         //i widget non sono attributi in quanto sono sempre gli stessi ed è sufficente crearli nel costruttore che non ha parametri per la stessa ragione
    static QString *searchName;  //memorizza memorizza l'ultima ricerca della searchBox, potrebbe servire per esempio per modificare la stringa di default della barra (che sara qualcosa tipo "clicca qui per ricercare per nome")
    static unsigned int order;   //memorizza l'ordine di visualizzazione dei sensori (il tipo è da rivedere)
    static unsigned int *filters;//memorizza l'ordine di visualizzazione dei sensori (il tipo è da rivedere) è un puntatore perche potrebbero essere più di uno
public:
    SearchMenu(QWidget* parent = nullptr);
    QVBoxLayout * layout;
    QLineEdit *lineEdit;
    QPushButton *add;
public slots:
    void onTextChanged(const QString &text);
signals:
    void showDialog();
};

