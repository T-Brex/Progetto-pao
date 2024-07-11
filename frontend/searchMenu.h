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
private:
    QString *searchName;  //memorizza memorizza l'ultima ricerca della searchBox, potrebbe servire per esempio per modificare la stringa di default della barra (che sara qualcosa tipo "clicca qui per ricercare per nome")
    QVBoxLayout * layout;

    QWidget *foundSensorsWidget;
    QVBoxLayout *foundSensorsLayout;

    QLineEdit *lineEdit;
    QPushButton *addButton;

    QPushButton *deleteButton;
    QPushButton *deleteAllButton;
public:
    QString* getSearchName() const { return searchName; }
    QVBoxLayout* getLayout() const { return layout; }
    QWidget* getFoundSensorsWidget() const { return foundSensorsWidget; }
    QVBoxLayout* getFoundSensorsLayout() const { return foundSensorsLayout; }
    QLineEdit* getLineEdit() const { return lineEdit; }
    QPushButton* getAddButton() const { return addButton; }
    QPushButton* getDeleteButton() const { return deleteButton; }
    QPushButton* getDeleteAllButton() const { return deleteAllButton; }
    void aggiuntaSensori();
    void updateSensori();

    SearchMenu(QWidget* parent = nullptr);
signals:
    void showAddDialog();
    void showDeleteDialog();;
    void showDeleteAllDialog();
    void showModifyDialog(const Sensor* sensor);
};
#endif // SEARCHMENU_H
