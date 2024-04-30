#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include "backend/sensors.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>


class SearchMenu: public QWidget {
    Q_OBJECT
                        //i widget non sono attributi in quanto sono sempre gli stessi ed è sufficente crearli nel costruttore che non ha parametri per la stessa ragione
                        //memorizza l'ordine di visualizzazione dei sensori (il tipo è da rivedere) è un puntatore perche potrebbero essere più di uno
public:
    QString *searchName;  //memorizza memorizza l'ultima ricerca della searchBox, potrebbe servire per esempio per modificare la stringa di default della barra (che sara qualcosa tipo "clicca qui per ricercare per nome")
    //unsigned int order;   //memorizza l'ordine di visualizzazione dei sensori (il tipo è da rivedere)
    //unsigned int *filters;
    QVBoxLayout * layout;

    QWidget *foundSensorsWidget;
    QVBoxLayout *foundSensorsLayout;

    QLineEdit *lineEdit;
    QPushButton *addButton;
    QPushButton *importButton;
    QPushButton *saveAsButton;
    QPushButton *deleteButton;
    QPushButton *deleteAllButton;
    SearchMenu(QWidget* parent = nullptr);

public slots:
    //static void onTextChanged(const QString &text);
signals:
    void showAddDialog();
    void showDeleteDialog();
    void showSaveAsDialog();
    void showDeleteAllDialog();
    void showImportDialog();
    void showModifyDialog(const Sensor* sensor);
};
#endif // SEARCHMENU_H
